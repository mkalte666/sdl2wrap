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

#ifndef sdl2wrap_objects_h
#define sdl2wrap_objects_h

#include "shared.h"

constexpr int screenW = 1024;
constexpr int screenH = 768;
constexpr int numBullets = 1024;
constexpr int numEvils = 1024;

constexpr float DefaultBulletSize = 3.0F;
constexpr float DefaultBulletOffset = DefaultBulletSize / 2.0F;
constexpr float DefaultPlayerSize = 10.0F;
constexpr float DefaultPlayerOffset = DefaultPlayerSize / 2.0F;
constexpr float DefaultEvilSize = 20.0F;
constexpr float DefaultEvilOffset = DefaultEvilSize / 2.0F;
constexpr int DefaultEvilHealth = 1;
constexpr int DefaulEvilHealthLevelDivider = 8;
constexpr Uint32 BulletDelay = 400; // ms

constexpr float PlayerStartX = 1024.0F / 2.0F;
constexpr float PlayerStartY = 768.0F / 2.0F;
constexpr float PlayerDefaultSpeed = 300.0F;

constexpr float BulletSpeed = -500.0F;
constexpr float BulletSpeedIncrease = 0.995F;
static const sdl2wrap::Video::Rect screenRect = { 0, 0, screenW, screenH };
constexpr Uint32 GameOverDelay = 2000; // ms

struct PhysState {
    float x = 0;
    float y = 0;
    float vx = 0;
    float vy = 0;
    float ax = 0;
    float ay = 0;
};

struct PlayerInput {
    bool firing = false;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
};

struct Player {
    PhysState state = {};
    float bulletDelay = static_cast<float>(BulletDelay);
    sdl2wrap::Video::FRect rect() const noexcept
    {
        return { state.x - DefaultPlayerOffset, state.y - DefaultPlayerOffset, DefaultPlayerSize, DefaultPlayerSize };
    }
};

struct Bullet {
    bool active = false;
    PhysState state = {};
    sdl2wrap::Video::FRect rect() const noexcept
    {
        return { state.x - DefaultBulletOffset, state.y - DefaultBulletOffset, DefaultBulletSize, DefaultBulletSize };
    }
};

struct Evil {
    bool active = false;
    int health = DefaultEvilHealth;
    PhysState state = {};
    sdl2wrap::Video::FRect rect() const noexcept
    {
        return { state.x - DefaultEvilOffset, state.y - DefaultEvilOffset, DefaultEvilSize, DefaultEvilSize };
    }
};

#endif //sdl2wrap_objects_h
