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

#ifndef sdl2wrap_impl_timer_h
#define sdl2wrap_impl_timer_h

namespace Timer {

SDL2WRAP_INLINE Uint32 getTicks() noexcept
{
    return SDL_GetTicks();
}

SDL2WRAP_INLINE bool ticksPassed(Uint32 currTime, Uint32 timeout) noexcept
{
    return SDL_TICKS_PASSED(currTime, timeout);
}

SDL2WRAP_INLINE bool ticksPassed(Uint32 timeout) noexcept
{
    return ticksPassed(getTicks(), timeout);
}

SDL2WRAP_INLINE Uint64 getPerformanceCounter() noexcept
{
    return SDL_GetPerformanceCounter();
}

SDL2WRAP_INLINE Uint64 getPerformanceFrequency() noexcept
{
    return SDL_GetPerformanceFrequency();
}

SDL2WRAP_INLINE void delay(Uint32 ms) noexcept
{
    SDL_Delay(ms);
}

SDL2WRAP_INLINE TimerID addTimer(Uint32 interval, TimerCallback callback, void* param) noexcept
{
    return SDL_AddTimer(interval, callback, param);
}

SDL2WRAP_INLINE bool removeTimer(TimerID id) noexcept
{
    return SDL_RemoveTimer(id) == SDL_TRUE;
}

} // namespace Timer

#endif //sdl2wrap_impl_timer_h
