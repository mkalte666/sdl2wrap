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

/**
 * \file init.cpp
 * Examples around SDL init and shutdown
 */

// just here is the first distinction!
// there are two headers - sdl2.h and sdl2stl.h
// sdl2stl.h enables functionality with the stl - mostly std::string and similar containers
// the stl is not required to get sdl2wrap working however
// also, instead of including sdl2sl.h, you could also define SDL2WRAP_USE_STL before including sdl2.h!
// anyway, here we go!
#include <iostream>
#include <sdl2wrap/sdl2stl.h>

namespace s2 = sdl2wrap;

int main(int, char**)
{
    // normal init
    {
        auto result = s2::SDL2::init(); // same as init(s2::InitFlags::everything)
        // always check results!
        // calling getValue or extractValue without a result present will terminate via an assert!
        // this is intentional!
        if (!result) {
            std::cout << "Init error! " << result.getErrorMessage() << "\n";
            return -1;
        }

        auto sdl = result.extractValue();
        std::cout << "First init was ok!"
                  << "\n";
        // you now can use any sdl functions - everything stems from this object.
        // note that extractValue() *moves* the value out of the result.
        // doing anything with any result.getValue() after extract is an error!
    } // moving on, going out of scope calls SDL_Quit()

    // checking init and subsystems
    {
        auto result = s2::SDL2::init(s2::InitFlags::Video);
        if (!result) {
            std::cout << "Init error! " << result.getErrorMessage() << "\n";
            return -1;
        }

        auto sdl = result.extractValue();
        // only created video, but we want audio too!
        if (!sdl.wasInit(s2::InitFlags::Audio)) {
            auto subsystemResult = sdl.initSubSystem(s2::InitFlags::Audio);
            // of course checking the result!
            if (!subsystemResult) {
                std::cout << "Init subsystem error!" << subsystemResult.getErrorMessage() << "\n";
                return -1; // note that returning means sdl goes out of scope - sdl_quit is called!
            }

            // you can use asserts too!
            SDL2WRAP_ASSERT(sdl.wasInit(s2::InitFlags::Audio));

            std::cout << "Second init also ran, and subsystem was loaded just fine! \n";
        }
    } // again, going out of scope means SDL_Quit is called.

    // a good next example would be video.cpp!
    // also, look inside the headers (sdl2wrap/sdl2.h) for in-code documentation!

    return 0;
}