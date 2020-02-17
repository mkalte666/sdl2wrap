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
 * \file video.h
 * Wraps SDL_video.h
 */

#ifndef sdl2wrap_window_h
#define sdl2wrap_window_h

// always first!
#include "detail/base.h"
#include "detail/generated/generated_sdl_video.h"
#include "detail/typewrapper.h"

#include "pixels.h"
#include "rect.h"
#include "surface.h"

namespace sdl2wrap {

/// Wraps SDL_DisplayMode
using DisplayMode = SDL_DisplayMode;

class Window : public TypeWrapper<Window, SDL_Window*, SDL_DestroyWindow> {
public:
    using TypeWrapper::TypeWrapper;
};

#ifdef SDL2WRAP_DEFINITIONS

#endif // SDL2WRAP_DEFINITIONS

}; // sdl2wrap

#endif //sdl2wrap_window_h
