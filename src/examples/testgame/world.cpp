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

constexpr float PlayerStartX = 1024.0F / 2.0F;
constexpr float PlayerStartY = 768.0F / 2.0F;
constexpr float PlayerDefaultSpeed = 300.0F;

World::World() noexcept
{
    player.state.x = PlayerStartX;
    player.state.y = PlayerStartY;
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

bool World::update(float dt) noexcept
{
    Event e;
    while (Input::pollEvent(e)) {
        switch (Input::getEventType(e)) {
        case EventType::Quit:
            return false;
        case EventType::Keydown:
        case EventType::Keyup: {
            if (e.key.repeat != 0) {
                break;
            }
            float yeno = Input::getEventType(e) == EventType::Keydown ? 1.0F : 0.0F;
            switch (static_cast<Scancode>(e.key.keysym.scancode)) {
            case Scancode::W:
                player.state.vy = -1.0F * yeno * PlayerDefaultSpeed;
                break;
            case Scancode::S:
                player.state.vy = 1.0F * yeno * PlayerDefaultSpeed;
                break;
            case Scancode::A:
                player.state.vx = -1.0F * yeno * PlayerDefaultSpeed;
                break;
            case Scancode::D:
                player.state.vx = 1.0F * yeno * PlayerDefaultSpeed;
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

    player.state = integrate(player.state, dt);
    return true;
}

void World::render(Video::Renderer& renderer, float dt) noexcept
{
    renderer.setDrawColor(black);
    renderer.clear();
    renderer.setDrawColor(white);

    // draw player
    auto playerState = integrate(player.state, dt);
    renderer.drawPointF(playerState.x, playerState.y);
    auto playerState2 = player.state;
    playerState2.x += 40.0F; //NOLINT

    renderer.drawPointF(playerState.x, playerState.y);
    renderer.drawPointF(playerState2.x, playerState2.y);

    (void)dt;
    renderer.present();
}
