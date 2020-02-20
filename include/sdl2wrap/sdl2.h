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

// always first
// clang-format off
#include "detail/base.h"
// clang-format on
#include "detail/generated/generated_sdl.h"
#include "detail/result.h"

#include "error.h"
#include "hints.h"
#include "log.h"
#include "rwops.h"
#include "version.h"
#include "video.h"

/**
 * \brief Namsespace for all SDL2Wrapper related functionality
 *
 *
 */
namespace sdl2wrap {

/**
 * \brief SDL2 Class
 * Manages the Lifetime of SDL2.
 * As soon as this object is destroyed, SDL_Quit() is called as well.
 * \wrapImpl SDL2 SDL2
 */
class SDL2 {
public:
    /// Result may use our default constructor
    friend class Result<SDL2>;

    /// copy ctor is deleted
    SDL2(const SDL2&) = delete;

    /// move ctor uses assign
    SDL2(SDL2&& rhs)
    noexcept;

    /// copy assignment is deleted
    SDL2& operator=(const SDL2&) = delete;

    /// move assignment invalidates the other object
    SDL2& operator=(SDL2&& rhs) noexcept;

    // init and destruction functions

    /**
     * \brief Destructor calls SDL2_Quit as long as the object is valid
     */
    ~SDL2() noexcept;

    /**
     * \brief Initialize SDL2
     * \param flags The init flags from InitFlags, xored togehter
     * \return Result holding a valid SDL2 on success, or an error.
     * \wrapImpl SDL_Init SDL2::init
     */
    static Result<SDL2> init(InitFlags flags = InitFlags::Everything);

    /**
     * \brief Initalize a sub system
     * \param subsystem
     * \return EmptyResult. Hods the sdl error if something went wrong
     * \wrapImpl SDL_InitSubSystem SDL2::initSubSystem
     */
    EmptyResult initSubSystem(InitFlags subsystem) noexcept;

    /**
     * \brief Clean up a specific subsystem
     * \param subsystem  subsytem to clean up
     * \wrapImpl SDL_QuitSubSystem SDL2::quitSubSystem
     */
    void quitSubSystem(InitFlags subsystem) noexcept;

    /**
     * \brief Check if a SDL feature was initialized
     * \param flags the feature(s), ored to gether
     * \return if the selected features are already init
     */
    bool wasInit(InitFlags flags) const noexcept;

    /**
     * \brief Get all features that are initialized
     * \return ored-together flags of present features
     * \wrapImpl SDL_WasInit SDL2::wasInit
     */
    InitFlags wasInit() const noexcept;

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

#ifdef SDL2WRAP_DEFINITIONS
#include "detail/generated/impl.h"
#endif

} // namespace sdl2wrap

#endif // sdl2wrap_sdl2_h