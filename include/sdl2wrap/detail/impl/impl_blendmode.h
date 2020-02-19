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

namespace Video {

SDL2WRAP_INLINE BlendMode composeBlendMode(BlendFactor srcColorFactor,
    BlendFactor dstColorFactor,
    BlendOperation colorOperation,
    BlendFactor srcAlphaFactor,
    BlendFactor dstAlphaFactor,
    BlendOperation alphaOperation) noexcept
{
    auto res = SDL_ComposeCustomBlendMode(
        static_cast<SDL_BlendFactor>(srcColorFactor),
        static_cast<SDL_BlendFactor>(dstColorFactor),
        static_cast<SDL_BlendOperation>(colorOperation),
        static_cast<SDL_BlendFactor>(srcAlphaFactor),
        static_cast<SDL_BlendFactor>(dstAlphaFactor),
        static_cast<SDL_BlendOperation>(alphaOperation));

    return static_cast<BlendMode>(res);
}

}; // namespace Video