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
// clang-format off
#include "detail/base.h"
// clang-format on

namespace sdl2wrap {

namespace Version {
    /**
     * \brief Get the version sdl2 was compiled as.
     * \return
     * \wrapImpl SDL_VERSION getCompiledVersion
     */
    SDL_version getCompiledVersion() noexcept;

    /**
     * \brief Get the version sdl2 is linked against.
     * \return
     * \wrapImpl SDL_GetVersion getLinkedVersion
     */
    SDL_version getLinkedVersion() noexcept;

    /**
     * \brief Get the revision sdl2 is compiled against.
     * \return
     * \wrapImpl SDL_REVISION getCompiledRevision
     */
    const char* getCompiledRevision() noexcept;

    /**
     * \brief Get the revision sdl2 is linked against.
     * \wrapImpl SDL_GetRevision getLinkedRevision
     */
    const char* getLinkedRevision() noexcept;

    /**
     * \brief Get the revision number sdl2 is compiled against.
     * \wrapImpl SDL_REVISION_NUMBER getCompiledRevisionNumber
     */
    int getCompiledRevisionNumber() noexcept;

    /**
     * \brief Get the revision number sdl2 is linked against.
     * \return
     * \wrapImpl SDL_GetRevisionNumber getLinkedRevisionNumber
     */
    int getLinkedRevisionNumber() noexcept;
}; // namespace Version
}; // namespace sdl2wrap

#endif //sdl2wrap_version_h
