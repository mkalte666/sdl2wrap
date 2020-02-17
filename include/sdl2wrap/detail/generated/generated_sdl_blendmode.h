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
#ifndef sdl2wrap_generated_SDL_blendmode
#define sdl2wrap_generated_SDL_blendmode

#include "SDL_blendmode.h"

namespace sdl2wrap {

/**
 * \brief Scoped version of SDL_BlendMode
 * 
 * Generated From SDL_blendmode.h:60
 * \sa SDL_BlendMode
 */
enum class BlendMode : Uint32 {
    None = SDL_BLENDMODE_NONE,
    Blend = SDL_BLENDMODE_BLEND,
    Add = SDL_BLENDMODE_ADD,
    Mod = SDL_BLENDMODE_MOD,
    Mul = SDL_BLENDMODE_MUL,
    Invalid = SDL_BLENDMODE_INVALID,
};

/**
 * \brief Scoped version of SDL_BlendOperation
 * 
 * Generated From SDL_blendmode.h:73
 * \sa SDL_BlendOperation
 */
enum class BlendOperation : Uint32 {
    Add = SDL_BLENDOPERATION_ADD,
    Subtract = SDL_BLENDOPERATION_SUBTRACT,
    RevSubtract = SDL_BLENDOPERATION_REV_SUBTRACT,
    Minimum = SDL_BLENDOPERATION_MINIMUM,
    Maximum = SDL_BLENDOPERATION_MAXIMUM,
};

/**
 * \brief Scoped version of SDL_BlendFactor
 * 
 * Generated From SDL_blendmode.h:91
 * \sa SDL_BlendFactor
 */
enum class BlendFactor : Uint32 {
    Zero = SDL_BLENDFACTOR_ZERO,
    One = SDL_BLENDFACTOR_ONE,
    SrcColor = SDL_BLENDFACTOR_SRC_COLOR,
    OneMinusSrcColor = SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR,
    SrcAlpha = SDL_BLENDFACTOR_SRC_ALPHA,
    OneMinusSrcAlpha = SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,
    DstColor = SDL_BLENDFACTOR_DST_COLOR,
    OneMinusDstColor = SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR,
    DstAlpha = SDL_BLENDFACTOR_DST_ALPHA,
    OneMinusDstAlpha = SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA,
};

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
