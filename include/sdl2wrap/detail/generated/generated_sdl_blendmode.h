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
    None = SDL_BLENDMODE_NONE, ///< \wrapImpl SDL_BLENDMODE_NONE BlendMode::None autogenerated
    Blend = SDL_BLENDMODE_BLEND, ///< \wrapImpl SDL_BLENDMODE_BLEND BlendMode::Blend autogenerated
    Add = SDL_BLENDMODE_ADD, ///< \wrapImpl SDL_BLENDMODE_ADD BlendMode::Add autogenerated
    Mod = SDL_BLENDMODE_MOD, ///< \wrapImpl SDL_BLENDMODE_MOD BlendMode::Mod autogenerated
    Mul = SDL_BLENDMODE_MUL, ///< \wrapImpl SDL_BLENDMODE_MUL BlendMode::Mul autogenerated
    Invalid = SDL_BLENDMODE_INVALID, ///< \wrapImpl SDL_BLENDMODE_INVALID BlendMode::Invalid autogenerated
};
inline bool operator==(SDL_BlendMode a, BlendMode b) noexcept
{
    return a == static_cast<SDL_BlendMode>(b);
}
inline bool operator==(BlendMode a, SDL_BlendMode b) noexcept
{
    return a == static_cast<BlendMode>(b);
}
inline BlendMode operator|(BlendMode a, BlendMode b) noexcept
{
    return static_cast<BlendMode>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_BlendOperation
 * 
 * Generated From SDL_blendmode.h:73
 * \sa SDL_BlendOperation
 */
enum class BlendOperation : Uint32 {
    Add = SDL_BLENDOPERATION_ADD, ///< \wrapImpl SDL_BLENDOPERATION_ADD BlendOperation::Add autogenerated
    Subtract = SDL_BLENDOPERATION_SUBTRACT, ///< \wrapImpl SDL_BLENDOPERATION_SUBTRACT BlendOperation::Subtract autogenerated
    RevSubtract = SDL_BLENDOPERATION_REV_SUBTRACT, ///< \wrapImpl SDL_BLENDOPERATION_REV_SUBTRACT BlendOperation::RevSubtract autogenerated
    Minimum = SDL_BLENDOPERATION_MINIMUM, ///< \wrapImpl SDL_BLENDOPERATION_MINIMUM BlendOperation::Minimum autogenerated
    Maximum = SDL_BLENDOPERATION_MAXIMUM, ///< \wrapImpl SDL_BLENDOPERATION_MAXIMUM BlendOperation::Maximum autogenerated
};
inline bool operator==(SDL_BlendOperation a, BlendOperation b) noexcept
{
    return a == static_cast<SDL_BlendOperation>(b);
}
inline bool operator==(BlendOperation a, SDL_BlendOperation b) noexcept
{
    return a == static_cast<BlendOperation>(b);
}
inline BlendOperation operator|(BlendOperation a, BlendOperation b) noexcept
{
    return static_cast<BlendOperation>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_BlendFactor
 * 
 * Generated From SDL_blendmode.h:91
 * \sa SDL_BlendFactor
 */
enum class BlendFactor : Uint32 {
    Zero = SDL_BLENDFACTOR_ZERO, ///< \wrapImpl SDL_BLENDFACTOR_ZERO BlendFactor::Zero autogenerated
    One = SDL_BLENDFACTOR_ONE, ///< \wrapImpl SDL_BLENDFACTOR_ONE BlendFactor::One autogenerated
    SrcColor = SDL_BLENDFACTOR_SRC_COLOR, ///< \wrapImpl SDL_BLENDFACTOR_SRC_COLOR BlendFactor::SrcColor autogenerated
    OneMinusSrcColor = SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR, ///< \wrapImpl SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR BlendFactor::OneMinusSrcColor autogenerated
    SrcAlpha = SDL_BLENDFACTOR_SRC_ALPHA, ///< \wrapImpl SDL_BLENDFACTOR_SRC_ALPHA BlendFactor::SrcAlpha autogenerated
    OneMinusSrcAlpha = SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA, ///< \wrapImpl SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA BlendFactor::OneMinusSrcAlpha autogenerated
    DstColor = SDL_BLENDFACTOR_DST_COLOR, ///< \wrapImpl SDL_BLENDFACTOR_DST_COLOR BlendFactor::DstColor autogenerated
    OneMinusDstColor = SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR, ///< \wrapImpl SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR BlendFactor::OneMinusDstColor autogenerated
    DstAlpha = SDL_BLENDFACTOR_DST_ALPHA, ///< \wrapImpl SDL_BLENDFACTOR_DST_ALPHA BlendFactor::DstAlpha autogenerated
    OneMinusDstAlpha = SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA, ///< \wrapImpl SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA BlendFactor::OneMinusDstAlpha autogenerated
};
inline bool operator==(SDL_BlendFactor a, BlendFactor b) noexcept
{
    return a == static_cast<SDL_BlendFactor>(b);
}
inline bool operator==(BlendFactor a, SDL_BlendFactor b) noexcept
{
    return a == static_cast<BlendFactor>(b);
}
inline BlendFactor operator|(BlendFactor a, BlendFactor b) noexcept
{
    return static_cast<BlendFactor>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
