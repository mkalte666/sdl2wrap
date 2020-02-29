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
#ifndef sdl2wrap_generated_SDL_render
#define sdl2wrap_generated_SDL_render

#include "SDL_render.h"

namespace sdl2wrap {

/**
 * \brief Scoped version of SDL_RendererFlags
 * 
 * Generated From SDL_render.h:73
 * \sa SDL_RendererFlags
 */
enum class RendererFlags : Uint32 {
    Software = SDL_RENDERER_SOFTWARE, ///< \wrapImpl SDL_RENDERER_SOFTWARE RendererFlags::Software autogenerated
    Accelerated = SDL_RENDERER_ACCELERATED, ///< \wrapImpl SDL_RENDERER_ACCELERATED RendererFlags::Accelerated autogenerated
    Presentvsync = SDL_RENDERER_PRESENTVSYNC, ///< \wrapImpl SDL_RENDERER_PRESENTVSYNC RendererFlags::Presentvsync autogenerated
    Targettexture = SDL_RENDERER_TARGETTEXTURE, ///< \wrapImpl SDL_RENDERER_TARGETTEXTURE RendererFlags::Targettexture autogenerated
};
inline bool operator==(SDL_RendererFlags a, RendererFlags b) noexcept
{
    return a == static_cast<SDL_RendererFlags>(b);
}
inline bool operator==(RendererFlags a, SDL_RendererFlags b) noexcept
{
    return a == static_cast<RendererFlags>(b);
}

/**
 * \brief Scoped version of SDL_ScaleMode
 * 
 * Generated From SDL_render.h:96
 * \sa SDL_ScaleMode
 */
enum class ScaleMode : Uint32 {
    Scalemodenearest = SDL_ScaleModeNearest, ///< \wrapImpl SDL_ScaleModeNearest ScaleMode::Scalemodenearest autogenerated
    Scalemodelinear = SDL_ScaleModeLinear, ///< \wrapImpl SDL_ScaleModeLinear ScaleMode::Scalemodelinear autogenerated
    Scalemodebest = SDL_ScaleModeBest, ///< \wrapImpl SDL_ScaleModeBest ScaleMode::Scalemodebest autogenerated
};
inline bool operator==(SDL_ScaleMode a, ScaleMode b) noexcept
{
    return a == static_cast<SDL_ScaleMode>(b);
}
inline bool operator==(ScaleMode a, SDL_ScaleMode b) noexcept
{
    return a == static_cast<ScaleMode>(b);
}

/**
 * \brief Scoped version of SDL_TextureAccess
 * 
 * Generated From SDL_render.h:106
 * \sa SDL_TextureAccess
 */
enum class TextureAccess : Uint32 {
    Static = SDL_TEXTUREACCESS_STATIC, ///< \wrapImpl SDL_TEXTUREACCESS_STATIC TextureAccess::Static autogenerated
    Streaming = SDL_TEXTUREACCESS_STREAMING, ///< \wrapImpl SDL_TEXTUREACCESS_STREAMING TextureAccess::Streaming autogenerated
    Target = SDL_TEXTUREACCESS_TARGET, ///< \wrapImpl SDL_TEXTUREACCESS_TARGET TextureAccess::Target autogenerated
};
inline bool operator==(SDL_TextureAccess a, TextureAccess b) noexcept
{
    return a == static_cast<SDL_TextureAccess>(b);
}
inline bool operator==(TextureAccess a, SDL_TextureAccess b) noexcept
{
    return a == static_cast<TextureAccess>(b);
}

/**
 * \brief Scoped version of SDL_TextureModulate
 * 
 * Generated From SDL_render.h:116
 * \sa SDL_TextureModulate
 */
enum class TextureModulate : Uint32 {
    None = SDL_TEXTUREMODULATE_NONE, ///< \wrapImpl SDL_TEXTUREMODULATE_NONE TextureModulate::None autogenerated
    Color = SDL_TEXTUREMODULATE_COLOR, ///< \wrapImpl SDL_TEXTUREMODULATE_COLOR TextureModulate::Color autogenerated
    Alpha = SDL_TEXTUREMODULATE_ALPHA, ///< \wrapImpl SDL_TEXTUREMODULATE_ALPHA TextureModulate::Alpha autogenerated
};
inline bool operator==(SDL_TextureModulate a, TextureModulate b) noexcept
{
    return a == static_cast<SDL_TextureModulate>(b);
}
inline bool operator==(TextureModulate a, SDL_TextureModulate b) noexcept
{
    return a == static_cast<TextureModulate>(b);
}

/**
 * \brief Scoped version of SDL_RendererFlip
 * 
 * Generated From SDL_render.h:126
 * \sa SDL_RendererFlip
 */
enum class RendererFlip : Uint32 {
    None = SDL_FLIP_NONE, ///< \wrapImpl SDL_FLIP_NONE RendererFlip::None autogenerated
    Horizontal = SDL_FLIP_HORIZONTAL, ///< \wrapImpl SDL_FLIP_HORIZONTAL RendererFlip::Horizontal autogenerated
    Vertical = SDL_FLIP_VERTICAL, ///< \wrapImpl SDL_FLIP_VERTICAL RendererFlip::Vertical autogenerated
};
inline bool operator==(SDL_RendererFlip a, RendererFlip b) noexcept
{
    return a == static_cast<SDL_RendererFlip>(b);
}
inline bool operator==(RendererFlip a, SDL_RendererFlip b) noexcept
{
    return a == static_cast<RendererFlip>(b);
}

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
