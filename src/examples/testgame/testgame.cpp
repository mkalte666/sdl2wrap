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

#include "shared.h"
#include "world.h"

using namespace sdl2wrap;

constexpr Uint64 ticksPerSecond = 30;

int main(int, char**)
{
    Hints::set(Hint::RenderDriver, "opengles2");
    Hints::set(Hint::RenderBatching, "1");
    auto sdl2 = SDL2::init(InitFlags::Everything).extractValue();
    auto window = Video::Window::createCentered("Testgame", 1024, 768, WindowFlags::Resizable).extractValue(); //NOLINT
    auto renderer = Video::Renderer::create(window, -1, RendererFlags::Accelerated | RendererFlags::Targettexture | RendererFlags::Presentvsync).extractValue();
    renderer.setLogicalSize(1024, 768); // NOLINT
    World world;

    auto timePerTick = Timer::getPerformanceFrequency() / ticksPerSecond;
    auto fTimePerTick = 1.0F / (static_cast<float>(ticksPerSecond));
    auto currentTime = Timer::getPerformanceCounter();
    Uint64 timePool = 0;

    bool running = true;
    while (running) {
        auto newTime = Timer::getPerformanceCounter();
        auto frameTime = newTime - currentTime;
        currentTime = newTime;
        timePool += frameTime;

        while (timePool >= timePerTick) {
            if (!world.update(fTimePerTick)) {
                running = false;
            }
            timePool -= timePerTick;
        }

        // render
        float alpha = static_cast<float>(timePool)/static_cast<float>(timePerTick);
        world.render(renderer, fTimePerTick, alpha);
    }

    return 0;
}