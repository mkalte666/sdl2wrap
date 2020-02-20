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
 * \file video.h
 * Wraps SDL_video.h
 */

#ifndef sdl2wrap_window_h
#define sdl2wrap_window_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on
#include "detail/generated/generated_sdl_video.h"
#include "detail/typewrapper.h"

#include "pixels.h"
#include "rect.h"
#include "surface.h"

namespace sdl2wrap {

namespace Video {

    /**
     * \brief Wraps SDL_DisplayMode
     * \sa SDL_DisplayMode
     */
    using DisplayMode = SDL_DisplayMode;

    int getNumVideoDrivers() noexcept;
    const char* getVideoDriver(int index) noexcept;
    EmptyResult init(const char* driverName) noexcept;
    void quit() noexcept;
    const char* getCurrentDriver() noexcept;
    int getNumDisplays() noexcept;
    const char* getDisplayName(int displayIndex) noexcept;
    Result<Rect> getDisplayBounds(int displayIndex) noexcept;
    Result<Rect> getDisplayUsableBounds(int displayIndex) noexcept;
    EmptyResult getDisplayDPI(int displayIndex, float& ddpi, float& hdpi, float& vdpi) noexcept;
    DisplayOrientation getDisplayOrientation(int displayIndex) noexcept;
    int getNumDisplayModes(int displayIndex) noexcept;
    Result<DisplayMode> getDisplayMode(int displayIndex, int modeIndex) noexcept;
    Result<DisplayMode> getDesktopDisplayMode(int displayIndex) noexcept;
    Result<DisplayMode> getCurrentDisplayMode(int displayIndex) noexcept;

    bool getClosestDisplayMode(int displayIndex, const DisplayMode& mode, DisplayMode& closest) noexcept;

    /**
 * \brief Wraps SDL_Window
 * \sa SDL_Window
 */
    class Window : public TypeWrapper<Window, SDL_Window*, SDL_DestroyWindow> {
    public:
        using TypeWrapper::TypeWrapper;

        static Result create(const char* title, int x, int y, int w, int h, WindowFlags flags = static_cast<WindowFlags>(0)) noexcept;
        static Result createCentered(const char* title, int w, int h, WindowFlags flags = static_cast<WindowFlags>(0)) noexcept;
        static Result createFrom(void* nativeWindow) noexcept;
    };

}; // namespace Video
}; // namespace sdl2wrap

#endif //sdl2wrap_window_h
