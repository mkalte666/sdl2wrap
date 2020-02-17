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
 * Everything in this file is generated. Please use scripts/generate.py to update it! 
 */
#ifndef sdl2wrap_generated_SDL_surface
#define sdl2wrap_generated_SDL_surface

#include "SDL_surface.h"

namespace sdl2wrap {

/**
 * \brief Scoped version of SDL_YUV_CONVERSION_MODE
 * 
 * Generated From SDL_surface.h:110
 * \sa SDL_YUV_CONVERSION_MODE
 */
enum class YUV_CONVERSION_MODE : Uint32 {
    ConversionJpeg = SDL_YUV_CONVERSION_JPEG,
    ConversionBt601 = SDL_YUV_CONVERSION_BT601,
    ConversionBt709 = SDL_YUV_CONVERSION_BT709,
    ConversionAutomatic = SDL_YUV_CONVERSION_AUTOMATIC,
};

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
