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
 * \file error.h
 * Wraps SDL_error.h
 */
#ifndef sdl2wrap_error_h
#define sdl2wrap_error_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on

namespace sdl2wrap {

/**
 * \brief Holds SDL_error.h functions
 */
namespace Error {
    /**
     * \brief Set error.
     * \param err
     * \sa SDL_SetError
     */
    void set(const char* err) noexcept;

    /**
     * \brief Get error.
     * \return
     * \sa SDL_GetError
     */
    const char* get() noexcept;

    /**
     * \brief Clear error.
     * \sa SDL_ClearError
     */
    void clear() noexcept;

#ifdef SDL2WRAP_USE_STL
    /**
     * \brief Set error with std::string.
     * \param str
     * \sa SDL_SetError
     */
    void set(const std::string& err) noexcept;

    /**
     * \brief Get error as std::string.
     * \return
     * \sa SDL_GetError
     */
    std::string getStr() noexcept;
#endif

}; //namespace Error
}; // namespace sdl2wrap

#endif //sdl2wrap_error_h
