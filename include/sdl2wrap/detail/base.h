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
 * \file base.h
 *
 * Include that collects most shared dependencies (such as the SDL2 headers)
 */

#ifndef sdl2wrap_sdl2base_h
#define sdl2wrap_sdl2base_h

// logic is as follows:
// if SDL2WRAP_DEFINITIONS is explicitly defined, someone wants to create their static file
// so we disable inline
#if defined(SDL2WRAP_DEFINITIONS)
#define SDL2WRAP_INLINE
#endif

// however, if its not defined, and we dont have SDL2WRAP_STATIC, we need inline to do its thing
#if !defined(SDL2WRAP_DEFINITIONS) && (defined(SDL2WRAP_HEADER_ONLY) || !defined(SDL2WRAP_STATIC))
#define SDL2WRAP_DEFINITIONS
#define SDL2WRAP_INLINE inline //NOLINT(cppcoreguidelines-macro-usage)
#endif

// std includes, if requested
#ifdef SDL2WRAP_USE_STL
#include <string>
#include <utility>
#endif // SDL2WRAP_USE_STL

// external includes
#include <SDL.h>

namespace sdl2wrap {

/**
     * \brief Due to us maybe not using anything of the STL, we dont have std::move and std::remove_reference
     * \tparam T
     */
///\{
template <class T>
struct removeRef {
    using type = T;
};

template <class T>
struct removeRef<T&> {
    using type = T;
};

template <class T>
struct removeRef<T&&> {
    using type = T;
};

template <class T>
constexpr typename removeRef<T>::type&& move(T&& arg)
{
    return static_cast<typename removeRef<T>::type&&>(arg);
}
///\}

}; // namespace sdl2wrap

#ifdef NDEBUG
// NOLINTNEXTLINE
#define SDL2WRAP_ASSERT_WRAPPER(condition) \
    if (!(condition)) {                    \
        abort();                           \
    }
#else
#define SDL2WRAP_ASSERT_WRAPPER(condition) SDL_assert((condition)) //NOLINT
#endif

/**
 *
 * Wrapper around either SDL_Assert (debug builds) or just a custom assert that aborts() when the assert fails
 */
#define SDL2WRAP_ASSERT(condition) SDL2WRAP_ASSERT_WRAPPER((condition)) //NOLINT

#endif // sdl2wrap_sdl2base_h