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
 * \file hints.h
 * Wrappers for SDL_HINT* functionality (SDL_hints.h)
 */

#ifndef sdl2wrap_hints_h
#define sdl2wrap_hints_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on
#include "detail/generated/generated_sdl_hints.h"

namespace sdl2wrap {

/**
 * \brief namespace providing SDL hinting
 * Hints are static cause they work before sdl2 init!
 */
namespace Hints {
    /// callback used by addCallback
    using HintCallback = SDL_HintCallback;
    /// userdata (just a void*) used by
    using HintCallbackDataT = void*;

    /**
     * \brief
     * \param hint
     * \param value
     * \return
     * \sa SDL_SetHint
     */
    bool set(const char* hint, const char* value) noexcept;
    /**
     * \brief
     * \param hint
     * \param value
     * \return
     * \sa SDL_SetHint
     */
    bool set(Hint hint, const char* value) noexcept;
    /**
     * \brief
     * \param hint
     * \param value
     * \param priority
     * \return
     * \sa SDL_SetHintWithPriority
     */
    bool setWithPriority(const char* hint, const char* value, HintPriority priority) noexcept;
    /**
     * \brief
     * \param hint
     * \param value
     * \param priority
     * \return
     * \sa SDL_SetHintWithPriority
     */
    bool setWithPriority(Hint hint, const char* value, HintPriority priority) noexcept;

    /**
     * \brief
     * \param hint
     * \return
     * \sa SDL_GetHint
     */
    const char* get(const char* hint) noexcept;
    /**
     * \brief
     * \param hint
     * \return
     * \sa SDL_GetHint
     */
    const char* get(Hint hint) noexcept;
    /**
     * \brief
     * \param hint
     * \param defaultValue
     * \return
     * \sa SDL_GetHintBoolean
     */
    bool getBoolean(const char* hint, bool defaultValue) noexcept;
    /**
     * \brief
     * \param hint
     * \param defaultValue
     * \return
     * \sa SDL_GetHintBoolean
     */
    bool getBoolean(Hint hint, bool defaultValue) noexcept;

    /**
     * \brief
     * \param hint
     * \param callback
     * \param userdata
     * \sa SDL_AddHintCallback
     */
    void addCallback(const char* hint, HintCallback callback, HintCallbackDataT userdata) noexcept;
    /**
     * \brief
     * \param hint
     * \param callback
     * \param userdata
     * \sa SDL_AddHintCallback
     */
    void addCallback(Hint hint, HintCallback callback, HintCallbackDataT userdata) noexcept;
    /**
     * \brief
     * \param hint
     * \param callback
     * \param userdata
     * \sa SDL_DelHintCallback
     */
    void delCallback(const char* hint, HintCallback callback, HintCallbackDataT userdata) noexcept;
    /**
     * \brief
     * \param hint
     * \param callback
     * \param userdata
     * \sa SDL_DelHintCallback
     */
    void delCallback(Hint hint, HintCallback callback, HintCallbackDataT userdata) noexcept;

    /**
     * \brief
     * \sa SDL_ClearHints
     */
    void clear() noexcept;

#ifdef SDL2WRAP_USE_STL
    /**
     * \brief
     * \param hint
     * \return
     * \sa SDL_GetHint
     */
    std::string getStr(const std::string& hint) noexcept;
    /**
     * \brief
     * \param hint
     * \return
     * \sa SDL_GetHint
     */
    std::string getStr(Hint hint) noexcept;
#endif // SDL2WRAP_USE_STL
}; // namespace Hints
}; // namespace sdl2wrap

#endif //sdl2wrap_hints_h
