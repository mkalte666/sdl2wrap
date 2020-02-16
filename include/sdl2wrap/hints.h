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

// always first!
#include "detail/base.h"
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
     */
    bool set(const char* hint, const char* value) noexcept;
    /**
     * \brief
     * \param hint
     * \param value
     * \return
     */
    bool set(Hint hint, const char* value) noexcept;
    /**
     * \brief
     * \param hint
     * \param value
     * \param priority
     * \return
     */
    bool setWithPriority(const char* hint, const char* value, HintPriority priority) noexcept;
    /**
     * \brief
     * \param hint
     * \param value
     * \param priority
     * \return
     */
    bool setWithPriority(Hint hint, const char* value, HintPriority priority) noexcept;

    /**
     * \brief
     * \param hint
     * \return
     */
    const char* get(const char* hint) noexcept;
    /**
     * \brief
     * \param hint
     * \return
     */
    const char* get(Hint hint) noexcept;
    /**
     * \brief
     * \param hint
     * \param defaultValue
     * \return
     */
    bool getBoolean(const char* hint, bool defaultValue) noexcept;
    /**
     * \brief
     * \param hint
     * \param defaultValue
     * \return
     */
    bool getBoolean(Hint hint, bool defaultValue) noexcept;

    /**
     * \brief
     * \param hint
     * \param callback
     * \param userdata
     */
    void addCallback(const char* hint, HintCallback callback, HintCallbackDataT userdata) noexcept;
    /**
     * \brief
     * \param hint
     * \param callback
     * \param userdata
     */
    void addCallback(Hint hint, HintCallback callback, HintCallbackDataT userdata) noexcept;
    /**
     * \brief
     * \param hint
     * \param callback
     * \param userdata
     */
    void delCallback(const char* hint, HintCallback callback, HintCallbackDataT userdata) noexcept;
    /**
     * \brief
     * \param hint
     * \param callback
     * \param userdata
     */
    void delCallback(Hint hint, HintCallback callback, HintCallbackDataT userdata) noexcept;

    /**
     * \brief
     */
    void clear() noexcept;

#ifdef SDL2WRAP_USE_STL
    /**
     * \brief
     * \param hint
     * \return
     */
    std::string getStr(const std::string& hint) noexcept;
    /**
     * \brief
     * \param hint
     * \return
     */
    std::string getStr(Hint hint) noexcept;
#endif // SDL2WRAP_USE_STL
}; // namespace Hints

#ifdef SDL2WRAP_DEFINITIONS

SDL2WRAP_INLINE bool Hints::set(const char* hint, const char* value) noexcept
{
    return SDL_SetHint(hint, value) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Hints::set(Hint hint, const char* value) noexcept
{
    return set(hintToBase(hint), value);
}

SDL2WRAP_INLINE bool Hints::setWithPriority(const char* hint, const char* value, HintPriority priority) noexcept
{
    return SDL_SetHintWithPriority(hint, value, static_cast<SDL_HintPriority>(priority)) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Hints::setWithPriority(Hint hint, const char* value, HintPriority priority) noexcept
{
    return setWithPriority(hintToBase(hint), value, priority);
}

SDL2WRAP_INLINE const char* Hints::get(const char* hint) noexcept
{
    return SDL_GetHint(hint);
}

SDL2WRAP_INLINE const char* Hints::get(Hint hint) noexcept
{
    return get(hintToBase(hint));
}

SDL2WRAP_INLINE bool Hints::getBoolean(const char* hint, bool defaultValue) noexcept
{
    return SDL_GetHintBoolean(hint, static_cast<SDL_bool>(defaultValue)) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Hints::getBoolean(Hint hint, bool defaultValue) noexcept
{
    return getBoolean(hintToBase(hint), defaultValue);
}

SDL2WRAP_INLINE void Hints::addCallback(const char* hint, HintCallback callback, HintCallbackDataT userdata) noexcept
{
    SDL_AddHintCallback(hint, callback, userdata);
}

SDL2WRAP_INLINE void Hints::addCallback(Hint hint, HintCallback callback, HintCallbackDataT userdata) noexcept
{
    addCallback(hintToBase(hint), callback, userdata);
}

SDL2WRAP_INLINE void Hints::delCallback(const char* hint, HintCallback callback, HintCallbackDataT userdata) noexcept
{
    SDL_DelHintCallback(hint, callback, userdata);
}

SDL2WRAP_INLINE void Hints::delCallback(Hint hint, HintCallback callback, HintCallbackDataT userdata) noexcept
{
    delCallback(hintToBase(hint), callback, userdata);
}

SDL2WRAP_INLINE void Hints::clear() noexcept
{
    SDL_ClearHints();
}

#ifdef SDL2WRAP_USE_STL

SDL2WRAP_INLINE std::string Hints::getStr(const std::string& hint) noexcept
{
    return std::string(get(hint.c_str()));
}

SDL2WRAP_INLINE std::string Hints::getStr(Hint hint) noexcept
{
    return std::string(get(hintToBase(hint)));
}

#endif // SDL2WRAP_USE_STL

#endif // SDL2WRAP_DEFINITIONS

}; // namespace sdl2wrap

#endif //sdl2wrap_hints_h
