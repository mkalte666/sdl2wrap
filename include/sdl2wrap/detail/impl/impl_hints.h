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
namespace Hints {

SDL2WRAP_INLINE bool set(const char* hint, const char* value) noexcept
{
    return SDL_SetHint(hint, value) == SDL_TRUE;
}

SDL2WRAP_INLINE bool set(Hint hint, const char* value) noexcept
{
    return set(hintToBase(hint), value);
}

SDL2WRAP_INLINE bool setWithPriority(const char* hint, const char* value, HintPriority priority) noexcept
{
    return SDL_SetHintWithPriority(hint, value, static_cast<SDL_HintPriority>(priority)) == SDL_TRUE;
}

SDL2WRAP_INLINE bool setWithPriority(Hint hint, const char* value, HintPriority priority) noexcept
{
    return setWithPriority(hintToBase(hint), value, priority);
}

SDL2WRAP_INLINE const char* get(const char* hint) noexcept
{
    return SDL_GetHint(hint);
}

SDL2WRAP_INLINE const char* get(Hint hint) noexcept
{
    return get(hintToBase(hint));
}

SDL2WRAP_INLINE bool getBoolean(const char* hint, bool defaultValue) noexcept
{
    return SDL_GetHintBoolean(hint, static_cast<SDL_bool>(defaultValue)) == SDL_TRUE;
}

SDL2WRAP_INLINE bool getBoolean(Hint hint, bool defaultValue) noexcept
{
    return getBoolean(hintToBase(hint), defaultValue);
}

SDL2WRAP_INLINE void addCallback(const char* hint, HintCallback callback, HintCallbackDataT userdata) noexcept
{
    SDL_AddHintCallback(hint, callback, userdata);
}

SDL2WRAP_INLINE void addCallback(Hint hint, HintCallback callback, HintCallbackDataT userdata) noexcept
{
    addCallback(hintToBase(hint), callback, userdata);
}

SDL2WRAP_INLINE void delCallback(const char* hint, HintCallback callback, HintCallbackDataT userdata) noexcept
{
    SDL_DelHintCallback(hint, callback, userdata);
}

SDL2WRAP_INLINE void delCallback(Hint hint, HintCallback callback, HintCallbackDataT userdata) noexcept
{
    delCallback(hintToBase(hint), callback, userdata);
}

SDL2WRAP_INLINE void clear() noexcept
{
    SDL_ClearHints();
}

#ifdef SDL2WRAP_USE_STL

SDL2WRAP_INLINE std::string getStr(const std::string& hint) noexcept
{
    return std::string(get(hint.c_str()));
}

SDL2WRAP_INLINE std::string getStr(Hint hint) noexcept
{
    return std::string(get(hintToBase(hint)));
}

#endif // SDL2WRAP_USE_STL

} // namespace Hints