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

#include <sdl2wrap/sdl2stl.h>
namespace s2 = sdl2wrap;
#include <iostream>

/**
 * \file init.cpp
 * Examples around SDL windows and renderers
 */

int main(int, char**)
{
    auto initResult = s2::SDL2::init(s2::InitFlags::Everything);
    if (!initResult) {
        return -1;
    }
    auto sdl2 = initResult.extractValue();

    // magic numbers? i bet your pardon linter, this is a normal number!
    auto windowResult = sdl2.createCenteredWindow("test window", 1024, 768); // NOLINT
    if (!windowResult) {
        std::cerr << "Could not create window: " << windowResult.getErrorMessage();
        return -1;
    }

    SDL_Delay(4000); //NOLINT

    return 0;
}
