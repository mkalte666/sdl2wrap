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

#ifndef sdl2wrap_version_h
#define sdl2wrap_version_h

// always first
#include "detail/base.h"

namespace sdl2wrap {

namespace Version {
    /**
     * \brief Get the version sdl2 was compiled as. Same as the SDL_VERSION macro
     * \return
     */
    SDL_version getCompiledVersion() noexcept;

    /**
     * \brief Get the version sdl2 is linked against. Same as the SDL_GetVersion function
     * \return
     */
    SDL_version getLinkedVersion() noexcept;

    /**
     * \brief Get the revision sdl2 is compiled against. Same as the SDL_REVISION macro
     * \return
     */
    const char* getCompiledRevision() noexcept;

    /**
     * \brief Get the revision sdl2 is linked against. Same as the SDL_GetRevision function
     * \return
     */
    const char* getLinkedRevision() noexcept;

    /**
     * \brief Get the revision number sdl2 is compiled against. Same sd the SDL_REVISION_NUMBER macro
     * \return
     */
    int getCompiledRevisionNumber() noexcept;

    /**
     * \brief Get the revision number sdl2 is linked against. Same as the SDL_GetRevisionNumber function
     * \return
     */
    int getLinkedRevisionNumber() noexcept;
}; // namespace Version

#ifdef SDL2WRAP_DEFINITIONS
#include "SDL_revision.h"

SDL2WRAP_INLINE SDL_version Version::getCompiledVersion() noexcept
{
    SDL_version v;
    SDL_VERSION(&v);
    return v;
}

SDL2WRAP_INLINE SDL_version Version::getLinkedVersion() noexcept
{
    SDL_version v;
    SDL_GetVersion(&v);
    return v;
}

SDL2WRAP_INLINE const char* Version::getCompiledRevision() noexcept
{
    return SDL_REVISION;
}

SDL2WRAP_INLINE const char* Version::getLinkedRevision() noexcept
{
    return SDL_GetRevision();
}

SDL2WRAP_INLINE int Version::getCompiledRevisionNumber() noexcept
{
    return SDL_REVISION_NUMBER;
}

SDL2WRAP_INLINE int Version::getLinkedRevisionNumber() noexcept
{
    return SDL_GetRevisionNumber();
}

#endif // SDL2WRAP_DEFINITIONS

}; // namespace sdl2wrap

#endif //sdl2wrap_version_h
