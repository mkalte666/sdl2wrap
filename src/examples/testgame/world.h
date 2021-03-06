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

#ifndef sdl2wrap_world_h
#define sdl2wrap_world_h

#include "objects.h"
#include "shared.h"

class World {
public:
    World() noexcept;
    World(const World&) = delete;
    World(World&&) noexcept = default;
    World& operator=(const World&) = delete;
    World& operator=(World&&) noexcept = default;
    ~World() noexcept = default;

    bool update(float dt) noexcept;
    void render(sdl2wrap::Video::Renderer& renderer, float dt, float alpha) noexcept;

private:
    void maybeSpawnBullet();
    void newLevel();
    Player player = {};
    Bullet bullets[numBullets]; //NOLINT
    Uint32 nextBullet = 0;
    Evil evils[numEvils]; //NOLINT
    int level = 0;
    bool gameOver = false;
    Uint32 gameOverOver = 0;
    PlayerInput playerInput = {};
};

#endif //sdl2wrap_world_h
