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
 * Everything in this file is generated. Please use scripts/generate.py to update it! 
 */
#ifndef sdl2wrap_generated_SDL
#define sdl2wrap_generated_SDL

#include "SDL.h"

namespace sdl2wrap {

/**
 * \brief scoped enum for SDL_INIT_* defines
 * 
 * Generated from SDL.h
 * \sa SDL_INIT_*
 */
enum class InitFlags : Uint32 {
    Timer = SDL_INIT_TIMER, ///< \wrapImpl SDL_INIT_TIMER InitFlags::Timer autogenerated
    Audio = SDL_INIT_AUDIO, ///< \wrapImpl SDL_INIT_AUDIO InitFlags::Audio autogenerated
    Video = SDL_INIT_VIDEO, ///< \wrapImpl SDL_INIT_VIDEO InitFlags::Video autogenerated
    Joystick = SDL_INIT_JOYSTICK, ///< \wrapImpl SDL_INIT_JOYSTICK InitFlags::Joystick autogenerated
    Haptic = SDL_INIT_HAPTIC, ///< \wrapImpl SDL_INIT_HAPTIC InitFlags::Haptic autogenerated
    Gamecontroller = SDL_INIT_GAMECONTROLLER, ///< \wrapImpl SDL_INIT_GAMECONTROLLER InitFlags::Gamecontroller autogenerated
    Events = SDL_INIT_EVENTS, ///< \wrapImpl SDL_INIT_EVENTS InitFlags::Events autogenerated
    Sensor = SDL_INIT_SENSOR, ///< \wrapImpl SDL_INIT_SENSOR InitFlags::Sensor autogenerated
    Noparachute = SDL_INIT_NOPARACHUTE, ///< \wrapImpl SDL_INIT_NOPARACHUTE InitFlags::Noparachute autogenerated
    Everything = SDL_INIT_EVERYTHING, ///< \wrapImpl SDL_INIT_EVERYTHING InitFlags::Everything autogenerated
};
inline InitFlags operator|(InitFlags a, InitFlags b) noexcept
{
    return static_cast<InitFlags>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
