/*
  SDL2 C++ Wrapper
  Copyright (C) 2020 Malte Kießling <mkalte@mkalte.me>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include "world.h"
using namespace sdl2wrap;

Uint32 notRandom()
{
    static Uint32 x = 12345; // NOLINT
    x = (0x5DEECE66D * x + 13) % INT32_MAX; // NOLINT
    return x;
}

World::World() noexcept
{
    player.state.x = PlayerStartX;
    player.state.y = PlayerStartY;
    newLevel();
}

PhysState integrate(PhysState in, float dt)
{
    PhysState out;
    out.x = in.x + in.vx * dt + in.ax * dt * dt / 2.0F; // NOLINT half for integration of a
    out.y = in.y + in.vy * dt + in.ay * dt * dt / 2.0F; // NOLINT half for integration of a
    out.vx = in.vx + in.ax * dt;
    out.vy = in.vy + in.ay * dt;
    return out;
}

PhysState interpolate(PhysState in, float dt, float alpha)
{
    PhysState futureState = integrate(in, dt);
    PhysState out = in;
    out.x = SDL_floorf(in.x * (1.0F - alpha) + futureState.x * alpha);
    out.y = SDL_floorf(in.y * (1.0F - alpha) + futureState.y * alpha);
    return out;
}

bool World::update(float dt) noexcept
{
    Event e;
    while (Input::pollEvent(e)) {
        switch (Input::getEventType(e)) {
        case EventType::Quit:
            return false;
        case EventType::Keydown:
        case EventType::Keyup: {
            bool pressed = Input::getEventType(e) == EventType::Keydown;

            switch (static_cast<Scancode>(e.key.keysym.scancode)) {
            case Scancode::W:
                playerInput.up = pressed;
                break;
            case Scancode::S:
                playerInput.down = pressed;
                break;
            case Scancode::A:
                playerInput.left = pressed;
                break;
            case Scancode::D:
                playerInput.right = pressed;
                break;
            case Scancode::Space:
                playerInput.firing = pressed;
                break;
            default:
                break;
            }
            break;
        }
        default:
            break;
        }
    }

    // handle game over
    if (gameOver) {
        if (Timer::ticksPassed(gameOverOver)) {
            gameOver = false;
            level = 0;
            player = Player();
            player.state.x = PlayerStartX;
            player.state.y = PlayerStartY;
            for (auto& bullet : bullets) {
                bullet.active = false;
            }
            newLevel();
        }

        return true;
    }

    if (playerInput.left && !playerInput.right) {
        player.state.vx = -1.0F * PlayerDefaultSpeed;
    } else if (!playerInput.left && playerInput.right) {
        player.state.vx = 1.0F * PlayerDefaultSpeed;
    } else {
        player.state.vx = 0.0F;
    }
    if (playerInput.up && !playerInput.down) {
        player.state.vy = -1.0F * PlayerDefaultSpeed;
    } else if (!playerInput.up && playerInput.down) {
        player.state.vy = 1.0F * PlayerDefaultSpeed;
    } else {
        player.state.vy = 0.0F;
    }

    auto oldState = player.state;
    player.state = integrate(oldState, dt);
    if (!player.rect().toRect().hasIntersection(screenRect)) {
        player.state = oldState;
    }

    if (playerInput.firing) {
        maybeSpawnBullet();
    }

    for (auto& bullet : bullets) {
        if (bullet.active) {
            auto oldBulletRect = bullet.rect().toRect();
            bullet.state = integrate(bullet.state, dt);
            if (!bullet.rect().toRect().hasIntersection(screenRect)) {
                bullet.active = false;
                continue;
            }
            auto newBulletRect = bullet.rect().toRect();
            for (auto& evil : evils) {
                if (evil.active) {
                    int x2 = newBulletRect.x + newBulletRect.w;
                    int y2 = newBulletRect.y + newBulletRect.h;
                    if (evil.rect().toRect().intersectRectAndLine(oldBulletRect.x, oldBulletRect.y, x2, y2)) {
                        --evil.health;
                        bullet.active = false;
                        player.bulletDelay *= BulletSpeedIncrease;
                    }
                }
            }
        }
    }

    bool anyEvil = false;
    for (auto& evil : evils) {
        if (evil.active) {
            anyEvil = true;
            evil.state = integrate(evil.state, dt);
            if (evil.health <= 0 || evil.state.y > static_cast<float>(screenH)) {
                evil.active = false;
                continue;
            }
            if (evil.rect().toRect().hasIntersection(player.rect().toRect())) {
                gameOver = true;
                gameOverOver = Timer::getTicks() + GameOverDelay;
            }
        }
    }

    if (!anyEvil) {
        newLevel();
    }
    return true;
}

void World::render(Video::Renderer& renderer, float dt, float alpha) noexcept
{
    renderer.setDrawColor(black);
    renderer.clear();
    renderer.setDrawColor(white);

    if (gameOver) {
        renderer.setDrawColor(notRed);
        renderer.fillRect(screenRect);
        renderer.present();
        return;
    }

    // draw player
    renderer.fillRectF(player.rect());

    // draw bullets.
    for (auto& bullet : bullets) {
        if (bullet.active) {
            auto bulletCopy = bullet;
            bulletCopy.state = interpolate(bulletCopy.state, dt, alpha);
            renderer.fillRectF(bulletCopy.rect());
        }
    }

    renderer.setDrawColor(notRed);
    for (auto& evil : evils) {
        if (evil.active) {
            auto evilCopy = evil;
            evilCopy.state = interpolate(evilCopy.state, dt, alpha);
            renderer.fillRectF(evilCopy.rect());
        }
    }
    renderer.present();
}
void World::maybeSpawnBullet()
{
    if (Timer::ticksPassed(nextBullet)) {
        nextBullet = Timer::getTicks() + static_cast<Uint32>(player.bulletDelay);
        for (auto& bullet : bullets) {
            if (!bullet.active) {
                bullet.active = true;
                bullet.state.x = player.state.x;
                bullet.state.y = player.state.y;
                bullet.state.vy = BulletSpeed;
                break;
            }
        }
    }
}
void World::newLevel()
{
    for (auto& evil : evils) {
        evil.active = false;
    }

    ++level;
    int evilCount = level * level;
    for (int i = 0; i < evilCount && i < numEvils; i++) {
        auto& evil = evils[i]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
        evil.active = true;
        evil.health = DefaultEvilHealth + level / DefaulEvilHealthLevelDivider;
        evil.state.x = static_cast<float>(static_cast<int>(notRandom()) % screenW);
        evil.state.y = static_cast<float>((static_cast<int>(notRandom()) % screenH) - screenH);
        evil.state.vy = PlayerDefaultSpeed;
    }
}
