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
     * \wrapImpl SDL_DisplayMode Video::DisplayMode
     */
    using DisplayMode = SDL_DisplayMode;

    // forward decl for less pain
    class Window;

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

    bool isScreenSaverEnabled() noexcept;
    void enableScreenSaver() noexcept;
    void disableScreenSaver() noexcept;

    /**
     * \brief Sub namespace for openGL specific things
     */
    namespace GL {
        class Context : public TypeWrapper<Context, SDL_GLContext, SDL_GL_DeleteContext> {
        public:
            using TypeWrapper::TypeWrapper;

            static Result create(Window& window) noexcept;
        };

        EmptyResult loadLibrary(const char* path) noexcept;
        void unloadLibrary() noexcept;

        void* getProcAddress(const char* proc) noexcept;
        bool getExtensionSupported(const char* extension) noexcept;

        void resetAttributes() noexcept;
        EmptyResult setAttribute(GLattr attr, int value) noexcept;
        EmptyResult getAttribute(GLattr attr, int& value) noexcept;

        EmptyResult setSwapInterval(int interval) noexcept;
        int getSwapInterval() noexcept;

        void swap(Window& window) noexcept;
        void getDrawableSize(Window& window, int& w, int& h) noexcept;
        void makeCurrent(Window& window, Context& context) noexcept;
    };

    /**
 * \brief Wraps SDL_Window
 * \sa SDL_Window
 */
    class Window : public TypeWrapper<Window, SDL_Window*, SDL_DestroyWindow> {
    public:
        using TypeWrapper::TypeWrapper;
        using HitTestCallback = SDL_HitTest;

        static Result create(const char* title, int x, int y, int w, int h, WindowFlags flags = static_cast<WindowFlags>(0)) noexcept;
        static Result createCentered(const char* title, int w, int h, WindowFlags flags = static_cast<WindowFlags>(0)) noexcept;
        static Result createFrom(void* nativeWindow) noexcept;

        EmptyResult setDisplayMode(const DisplayMode& mode) noexcept;
        sdl2wrap::Result<DisplayMode> getDisplayMode() const noexcept;
        PixelFormatEnum getPixelFormat() const noexcept;

        Uint32 getID() const noexcept;
        WindowFlags getFlags() const noexcept;

        void setTitle(const char* title) noexcept;
        const char* getTitle() const noexcept;
        void setIcon(const Surface& icon) noexcept;

        void setData(const char* name, void* ptr) noexcept;
        void* getData(const char* name) const noexcept;

        void setPosition(int x, int y) noexcept;
        void getPosition(int& x, int& y) const noexcept;
        void setSize(int w, int h) noexcept;
        void getSize(int& w, int& h) const noexcept;
        void setMinimumSize(int minW, int minH) noexcept;
        void getMinimumSize(int& minW, int& minH) const noexcept;
        void setMaximumSize(int minW, int minH) noexcept;
        void getMaximumSize(int& minW, int& minH) const noexcept;

        EmptyResult getBorderSize(int& top, int& left, int& bottom, int& right) const noexcept;

        void setBordered(bool bordered) noexcept;
        void setResizable(bool resizable) noexcept;
        void setFullscreen(bool fullscreen) noexcept;
        void setInputFocus() noexcept;

        void setGrab(bool grab) noexcept;
        bool getGrab() const noexcept;

        EmptyResult setBrightness(float brightness) noexcept;
        float getBrightness() const noexcept;

        EmptyResult setOpacity(float opacity) noexcept;
        EmptyResult getOpacity(float& opacity) const noexcept;

        EmptyResult setModalFor(Window& parent) noexcept;

        EmptyResult setGammaRamp(const Uint16* red, const Uint16* green, const Uint16* blue) noexcept;
        EmptyResult getGammaRamp(Uint16* red, Uint16* green, Uint16* blue) const noexcept;

        EmptyResult setHitTestCallback(HitTestCallback callback, void* callbackData) noexcept;

        void show();
        void hide();
        void raise();
        void maximize();
        void minimize();
        void restore();
    };

}; // namespace Video
}; // namespace sdl2wrap

#endif //sdl2wrap_window_h
