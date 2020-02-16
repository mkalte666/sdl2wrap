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
#include "detail/base.h"

namespace sdl2wrap {

/**
 * \brief Holds SDL_error.h functions
 */
namespace Error {
    /**
     * \brief Set error. SDL_SetError
     * \param err
     */
    void set(const char* err) noexcept;

    /**
     * \brief Get error. SDL_GetError
     * \return
     */
    const char* get() noexcept;

    /**
     * \brief Clear error. SDL_ClearError
     */
    void clear() noexcept;

#ifdef SDL2WRAP_USE_STL
    /**
     * \brief Set error with std::string. SDL_SetError
     * \param str
     */
    void set(const std::string& str) noexcept;

    /**
     * \brief Get error as std::string. SDL_GetError
     * \return
     */
    std::string getStr() noexcept;
#endif

}; //namespace Error

#ifdef SDL2WRAP_DEFINITIONS

SDL2WRAP_INLINE void Error::set(const char* err) noexcept
{
    (void)SDL_SetError("%s", err);
}

SDL2WRAP_INLINE const char* Error::get() noexcept
{
    return SDL_GetError();
}

SDL2WRAP_INLINE void Error::clear() noexcept
{
    return SDL_ClearError();
}

#ifdef SDL2WRAP_USE_STL

SDL2WRAP_INLINE void Error::set(const std::string& err) noexcept
{
    (void)SDL_SetError("%s", err.c_str());
}

SDL2WRAP_INLINE std::string Error::getStr() noexcept
{
    return std::string(Error::get());
}

#endif // SDL2WRAP_USE_STL
#endif // SDL2WRAP_DEFINITIONS

}; // namespace sdl2wrap

#endif //sdl2wrap_error_h
