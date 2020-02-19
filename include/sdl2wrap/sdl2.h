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
     * \sa SDL_Init
     */
    static Result<SDL2> init(InitFlags flags = InitFlags::Everything);

    /**
     * \brief Initalize a sub system
     * \param subsystem
     * \return EmptyResult. Hods the sdl error if something went wrong
     * \sa SDL_InitSubSystem
     */
    EmptyResult initSubSystem(InitFlags subsystem) noexcept;

    /**
     * \brief Clean up a specific subsystem
     * \param subsystem  subsytem to clean up
     * \sa SDL_QuitSubSystem
     */
    void quitSubSystem(InitFlags subsystem) noexcept;

    /**
     * \brief Check if a SDL feature was initialized
     * \param flags the feature(s), ored to gether
     * \return if the selected features are already init
     * \sa SDL_WasInit
     */
    bool wasInit(InitFlags flags) const noexcept;

    /**
     * \brief Get all features that are initialized
     * \return ored-together flags of present features
     * \sa SDL_WasInit
     */
    InitFlags wasInit() const noexcept;

    // video functions

    /** up next in our lineup:
    int getNumVideoDrivers() const noexcept;
    const char* getVideoDriver(int index) const noexcept;
    EmptyResult videoInit(const char* driverName) const noexcept;
    void videoQuit() const noexcept;
    const char* getCurrentVideoDriver() const noexcept;
    int getNumVideoDisplays() const noexcept;
    const char* getDisplayName(int displayIndex) const noexcept;
    Result<Rect> getDisplayBounds(int displayIndex) const noexcept;
    Result<Rect> getDisplayUseableBounds(int displayIndex) const noexcept;
    EmptyResult getDisplayDPI(int diplayIndex, float& ddpi, float& hdpi, float& vdpi) const noexcept;
    DisplayOrientation getDisplayOrientation(int displayIndex) const noexcept;
    int getNumDisplayModes(int displayIndex) const noexcept;
    Result<DisplayMode> getDisplayMode(int displayIndex, int modeIndex) const noexcept;
    Result<DisplayMode> getDesktopDisplayMode(int displayIndex) const noexcept;
    Result<DisplayMode> getCurrentDisplayMode(int displayIndex) const noexcept;

    bool getClosestDisplayMode(int displayIndex, const DisplayMode& mode, DisplayMode& closest) const noexcept;
*/
    Window::Result createWindow(const char* title, int x, int y, int w, int h, WindowFlags flags = static_cast<WindowFlags>(0)) noexcept;
    Window::Result createCenteredWindow(const char* title, int w, int h, WindowFlags flags = static_cast<WindowFlags>(0)) noexcept;

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

SDL2WRAP_INLINE SDL2::SDL2(SDL2&& rhs) noexcept
{
    *this = move(rhs);
}

SDL2WRAP_INLINE SDL2::~SDL2() noexcept
{
    if (valid) {
        SDL_Quit();
    }
}

SDL2WRAP_INLINE SDL2& SDL2::operator=(SDL2&& rhs) noexcept
{
    valid = rhs.valid;
    rhs.valid = false;
    return *this;
};

SDL2WRAP_INLINE EmptyResult SDL2::initSubSystem(InitFlags subsystem) noexcept
{
    auto rc = SDL_InitSubSystem(static_cast<Uint32>(subsystem));
    if (rc != 0) {
        return EmptyResult::error(rc);
    }
    return EmptyResult::success(true);
}

SDL2WRAP_INLINE void SDL2::quitSubSystem(InitFlags subsystem) noexcept
{
    SDL_QuitSubSystem(static_cast<Uint32>(subsystem));
}

SDL2WRAP_INLINE Result<SDL2> SDL2::init(InitFlags flags)
{
    SDL2 sdl2;

    auto rc = SDL_Init(static_cast<Uint32>(flags));
    if (rc != 0) {
        return Result<SDL2>::error(rc);
    }

    sdl2.valid = true;
    return Result<SDL2>::success(move(sdl2));
}

SDL2WRAP_INLINE bool SDL2::wasInit(InitFlags flags) const noexcept
{
    auto afterInitFlags = static_cast<InitFlags>(SDL_WasInit(static_cast<Uint32>(flags)));
    return flags == afterInitFlags;
}

SDL2WRAP_INLINE InitFlags SDL2::wasInit() const noexcept
{
    return static_cast<InitFlags>(SDL_WasInit(0));
}

SDL2WRAP_INLINE Window::Result SDL2::createWindow(const char* title, int x, int y, int w, int h, WindowFlags flags) noexcept
{
    SDL_Window* window = SDL_CreateWindow(title, x, y, w, h, static_cast<Uint32>(flags));
    if (window == nullptr) {
        return Window::Result::error(0);
    }

    return Window::Result::success(Window(window));
}

SDL2WRAP_INLINE Window::Result SDL2::createCenteredWindow(const char* title, int w, int h, WindowFlags flags) noexcept
{
    // sign conversion for SDL_WINDOWPOS_CENTERED
    // NOLINTNEXTLINE
    return createWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
}

#endif // SDL2WRAP_DEFINITIONS

} // namespace sdl2wrap

#endif // sdl2wrap_sdl2_h