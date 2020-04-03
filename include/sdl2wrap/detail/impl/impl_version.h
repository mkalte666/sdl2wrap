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

#include "SDL_revision.h"

namespace Version {

SDL2WRAP_INLINE SDL_version getCompiledVersion() noexcept
{
    SDL_version v;
    SDL_VERSION(&v);
    return v;
}

SDL2WRAP_INLINE SDL_version getLinkedVersion() noexcept
{
    SDL_version v;
    SDL_GetVersion(&v);
    return v;
}

SDL2WRAP_INLINE const char* getCompiledRevision() noexcept
{
    return SDL_REVISION;
}

SDL2WRAP_INLINE const char* getLinkedRevision() noexcept
{
    return SDL_GetRevision();
}

SDL2WRAP_INLINE int getCompiledRevisionNumber() noexcept
{
    return SDL_REVISION_NUMBER;
}

SDL2WRAP_INLINE int getLinkedRevisionNumber() noexcept
{
    return SDL_GetRevisionNumber();
}

} // namespace Version