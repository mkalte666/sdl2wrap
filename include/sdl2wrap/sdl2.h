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
 * \file SDL2.h
 * Holds the SDL2 class that manages init and basic resource creation.
 * Also includes all relevant SDL2 sub headers
 * Analog to SDL2.h
 */

#ifndef sdl2wrap_sdl2_h
#define sdl2wrap_sdl2_h

#include "sdl2wrap/detail/base.h"
#include "sdl2wrap/detail/result.h"

/**
 * \brief Namsespace for all SDL2Wrapper related functionality
 *
 *
 */
namespace sdl2wrap {
/**
     * \brief Init Flags for SDL2
     */
enum class InitFlags : Uint32 {
    None = 0U,
    Timer = SDL_INIT_TIMER,
    Audio = SDL_INIT_AUDIO,
    Video = SDL_INIT_JOYSTICK,
    Joystick = SDL_INIT_JOYSTICK,
    Haptic = SDL_INIT_HAPTIC,
    Gamecontroller = SDL_INIT_GAMECONTROLLER,
    Events = SDL_INIT_EVENTS,
    Sensor = SDL_INIT_SENSOR,
    NoParachute = SDL_INIT_NOPARACHUTE,
    Everything = SDL_INIT_EVERYTHING
};

/**
     * \brief SDL2 Class
     * Manages the Lifetime of SDL2.
     * As soon as this object is destroyed, SDL_Quit() is called as well.
     */
class SDL2 {
public:
    /// Result may use our default constructor
    friend class Result<SDL2>;

    /// copy ctor is deleted
    SDL2(const SDL2&) = delete;

    /// move ctor uses assign
    SDL2(SDL2&& rhs)
    noexcept
    {
        *this = move(rhs);
    };
    /// copy assignment is deleted
    SDL2& operator=(const SDL2&) = delete;

    /// move assignment invalidates the other object
    SDL2& operator=(SDL2&& rhs) noexcept
    {
        valid = rhs.valid;
        rhs.valid = false;
        return *this;
    };

    /**
         * \brief Destructor calls SDL2_Quit as long as the object is valid
         */
    ~SDL2()
    {
        if (valid) {
            SDL_Quit();
        }
    }

    /**
         * \brief Initialize SDL2
         * \param flags The init flags from InitFlags, xored togehter
         * \return Result holding a valid SDL2 on success, or an error.
         */
    static Result<SDL2> init(InitFlags flags = InitFlags::Everything)
    {
        SDL2 sdl2;

        auto rc = SDL_Init(static_cast<Uint32>(flags));
        if (rc != 0) {
            return Result<SDL2>::error(rc);
        }

        sdl2.valid = true;
        return Result<SDL2>::success(move(sdl2));
    }

    bool wasInit(InitFlags flags) const noexcept
    {
        if (flags == InitFlags::None) {
            return false;
        }

        auto acutallyInit = static_cast<InitFlags>(SDL_WasInit(static_cast<Uint32>(flags)));
        return flags == acutallyInit;
    }

private:
    /// default ctor
    SDL2()
    noexcept = default;
    /**
         * \brief Validity of the sdl2 instance
         * To allow movement of the object, validity is tracked.
         * only a sucessfull call to init makes this valid;
         */
    bool valid = false;
};
} // namespace sdl2wrap

#endif // sdl2wrap_sdl2_h