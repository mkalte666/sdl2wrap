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
 */
enum class InitFlags {
    Timer, ///< SDL_INIT_TIMER
    Audio, ///< SDL_INIT_AUDIO
    Video, ///< SDL_INIT_VIDEO
    Joystick, ///< SDL_INIT_JOYSTICK
    Haptic, ///< SDL_INIT_HAPTIC
    Gamecontroller, ///< SDL_INIT_GAMECONTROLLER
    Events, ///< SDL_INIT_EVENTS
    Sensor, ///< SDL_INIT_SENSOR
    Noparachute, ///< SDL_INIT_NOPARACHUTE
    Everything, ///< SDL_INIT_EVERYTHING
};

/**
 * \brief convert InitFlags to its basetype (Uint32)
 */
Uint32 initFlagsToBase(InitFlags value) noexcept;
#ifdef SDL2WRAP_DEFINITIONS
SDL2WRAP_INLINE Uint32 initFlagsToBase(InitFlags value) noexcept
{
    switch (value) {
    case InitFlags::Timer:
        return SDL_INIT_TIMER;
    case InitFlags::Audio:
        return SDL_INIT_AUDIO;
    case InitFlags::Video:
        return SDL_INIT_VIDEO;
    case InitFlags::Joystick:
        return SDL_INIT_JOYSTICK;
    case InitFlags::Haptic:
        return SDL_INIT_HAPTIC;
    case InitFlags::Gamecontroller:
        return SDL_INIT_GAMECONTROLLER;
    case InitFlags::Events:
        return SDL_INIT_EVENTS;
    case InitFlags::Sensor:
        return SDL_INIT_SENSOR;
    case InitFlags::Noparachute:
        return SDL_INIT_NOPARACHUTE;
    case InitFlags::Everything:
        return SDL_INIT_EVERYTHING;

    default:
        break;
    }

    return 0;
}
#endif // SDL2WRAP_DEFINITIONS

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
