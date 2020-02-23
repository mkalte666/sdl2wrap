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

    /**
     * \brief Get the number of video drivers compiled into SDL
     * \return
     * \wrapImpl SDL_GetNumVideoDrivers Video::getNumVideoDrivers
     */
    int getNumVideoDrivers() noexcept;

    /**
     * \brief Get the name of a built in video driver
     * \param index
     * \return
     * \wrapImpl SDL_GetVideoDriver Video::getVideoDrver
     */
    const char* getVideoDriver(int index) noexcept;

    /**
     * \brief Init the video subsystem, optionally specifying a video driver
     * \param driverName
     * \return
     * \wrapImpl SDL_VideoInit Video::init
     */
    EmptyResult init(const char* driverName) noexcept;

    /**
     * \brief
     * \wrapImpl SDL_VideoQuit Video::quit
     */
    void quit() noexcept;

    /**
     * \brief Returns the name of the currently initialized video driver.
     * \return
     * \wrapImpl SDL_GetCurrentVideoDriver Video::getCurrentVideoDriver
     */
    const char* getCurrentDriver() noexcept;

    /**
     * \brief Returns the number of available video displays.
     * \return
     * \wrapImpl SDL_GetNumVideoDisplays Video::getNumDisplays
     */
    int getNumDisplays() noexcept;

    /**
     * \brief
     * \param displayIndex
     * \return
     * \wrapImpl SDL_GetDisplayName Video::getDisplayName
     */
    const char* getDisplayName(int displayIndex) noexcept;

    /**
     * \brief
     * \param displayIndex
     * \return
     * \wrapImpl SDL_GetDisplayBounds Video::getDisplayBounds
     */
    Result<Rect> getDisplayBounds(int displayIndex) noexcept;

    /**
     * \brief
     * \param displayIndex
     * \return
     * \wrapImpl SDL_GetDisplayUsableBounds Video::getDisplayUsableBounds
     */
    Result<Rect> getDisplayUsableBounds(int displayIndex) noexcept;

    /**
     * \brief
     * \param displayIndex
     * \param ddpi
     * \param hdpi
     * \param vdpi
     * \return
     * \wrapImpl SDL_GetDisplayDPI Video::getDisplayDPI
     */
    EmptyResult getDisplayDPI(int displayIndex, float& ddpi, float& hdpi, float& vdpi) noexcept;

    /**
     * \brief
     * \param displayIndex
     * \return
     * \wrapImpl SDL_GetDisplayOrientation Video::getDisplayOrientation
     */
    DisplayOrientation getDisplayOrientation(int displayIndex) noexcept;

    /**
     * \brief
     * \param displayIndex
     * \return
     * \wrapImpl SDL_GetNumDisplayModes Video::getNumDisplayModes
     */
    int getNumDisplayModes(int displayIndex) noexcept;

    /**
     * \brief
     * \param displayIndex
     * \param modeIndex
     * \return
     * \wrapImpl SDL_GetDisplayMode Video::getDisplayMode
     */
    Result<DisplayMode> getDisplayMode(int displayIndex, int modeIndex) noexcept;

    /**
     * \brief
     * \param displayIndex
     * \return
     * \wrapImpl SDL_GetDesktopDisplayMode Video::getDesktopDisplayMode
     */
    Result<DisplayMode> getDesktopDisplayMode(int displayIndex) noexcept;

    /**
     * \brief
     * \param displayIndex
     * \return
     * \wrapImpl SDL_GetCurrentDisplayMode Video::getCurrentDisplayMode
     */
    Result<DisplayMode> getCurrentDisplayMode(int displayIndex) noexcept;

    /**
     * \brief
     * \param displayIndex
     * \param mode
     * \param closest
     * \return
     * \wrapImpl SDL_GetClosestDisplayMode Video::getClosestDisplayMode
     */
    bool getClosestDisplayMode(int displayIndex, const DisplayMode& mode, DisplayMode& closest) noexcept;

    /**
     * \brief
     * \return
     * \wrapImpl SDL_IsScreenSaverEnabled Video::isScreenSaverEnabled
     */
    bool isScreenSaverEnabled() noexcept;

    /**
     * \brief
     * \wrapImpl SDL_EnableScreenSaver Video::enableScreenSaver
     */
    void enableScreenSaver() noexcept;

    /**
     * \brief
     * \wrapImpl SDL_DisableScreenSaver Video::disableScreenSaver
     */
    void disableScreenSaver() noexcept;

    /**
     * \brief Sub namespace for openGL specific things
     */
    namespace GL {
        /**
         * \brief
         * \wrapImpl SDL_GLContext Video::Context
         */
        class Context : public TypeWrapper<Context, SDL_GLContext, SDL_GL_DeleteContext> {
        public:
            /// ctor
            using TypeWrapper::TypeWrapper;

            /**
             * \brief
             * \param window
             * \return
             * \wrapImpl SDL_GL_CreateContext Video::GL::Context::create
             */
            static Result create(Window& window) noexcept;
        };

        /**
         * \brief
         * \param path
         * \return
         * \wrapImpl SDL_GL_LoadLibrary Video::GL::loadLibrary
         */
        EmptyResult loadLibrary(const char* path) noexcept;

        /**
         * \brief
         * \wrapImpl SDL_GL_UnloadLibrary Video::GL::unloadLibrary
         */
        void unloadLibrary() noexcept;

        /**
         * \brief
         * \param proc
         * \return
         * \wrapImpl SDL_GL_GetProcAddress Video::GL::getProcAddress
         */
        sdl2wrap::Result<void*> getProcAddress(const char* proc) noexcept;

        /**
         * \brief
         * \param extension
         * \return
         * \wrapImpl SDL_GL_ExtensionSupported Video::GL::getExtensionSupported
         */
        bool getExtensionSupported(const char* extension) noexcept;

        /**
         * \brief
         * \wrapImpl SDL_GL_ResetAttributes Video::GL::resetAttributes
         */
        void resetAttributes() noexcept;

        /**
         * \brief
         * \param attr
         * \param value
         * \return
         * \wrapImpl SDL_GL_SetAttribute Video::GL::setAttribute
         */
        EmptyResult setAttribute(GLattr attr, int value) noexcept;

        /**
         * \brief
         * \param attr
         * \return
         * \wrapImpl SDL_GL_GetAttribute Video::GL::getAttribute
         */
        sdl2wrap::Result<int> getAttribute(GLattr attr) noexcept;

        /**
         * \brief
         * \param interval
         * \return
         * \wrapImpl SDL_GL_SetSwapInterval Video::GL::setSwapInterval
         */
        EmptyResult setSwapInterval(int interval) noexcept;

        /**
         * \brief
         * \return
         * \wrapImpl SDL_GL_GetSwapInterval Video::GL::getSwapInterval
         */
        int getSwapInterval() noexcept;

        /**
         * \brief
         * \param window
         * \wrapImpl SDL_GL_SwapWindow Video::GL::swap
         */
        void swap(Window& window) noexcept;

        /**
         * \brief
         * \param window
         * \param w
         * \param h
         * \wrapImpl SDL_GL_GetDrawableSize Video::GL::getDrawableSize
         */
        void getDrawableSize(Window& window, int& w, int& h) noexcept;

        /**
         * \brief
         * \param window
         * \param context
         * \wrapImpl SDL_GL_MakeCurrent Video::GL::makeCurrent
         */
        void makeCurrent(Window& window, Context& context) noexcept;
    };

    /**
     * \brief Wraps SDL_Window
     * \sa SDL_Window
     * \wrapImpl SDL_Window Video::Window
     */
    class Window : public TypeWrapper<Window, SDL_Window*, SDL_DestroyWindow> {
    public:
        using TypeWrapper::TypeWrapper;
        using HitTestCallback = SDL_HitTest;

        /**
         * \brief
         * \param title
         * \param x
         * \param y
         * \param w
         * \param h
         * \param flags
         * \return
         * \wrapImpl SDL_CreateWindow Video::Window::create
         */
        static Result create(const char* title, int x, int y, int w, int h, WindowFlags flags = static_cast<WindowFlags>(0)) noexcept;

        /**
         * \brief
         * \param title
         * \param w
         * \param h
         * \param flags
         * \return
         * \sa Video::Window::create
         * \sa SDL_CreateWindow
         */
        static Result createCentered(const char* title, int w, int h, WindowFlags flags = static_cast<WindowFlags>(0)) noexcept;

        /**
         * \brief
         * \param nativeWindow
         * \return
         * \wrapImpl SDL_CreateWindowFrom Video::Window::createFrom
         */
        static Result createFrom(void* nativeWindow) noexcept;

        /**
         * \brief
         * \param mode
         * \return
         * \wrapImpl SDL_SetWindowDisplayMode Video::Window::setDisplayMode
         */
        EmptyResult setDisplayMode(const DisplayMode& mode) noexcept;

        /***
         * \brief
         * \return
         * \wrapImpl SDL_GetWindowDisplayMode Video::Window::getDisplayMode
         */
        sdl2wrap::Result<DisplayMode> getDisplayMode() const noexcept;

        /**
         * \brief
         * \return
         * \wrapImpl SDL_GetWindowPixelFormat Video::Window::getPixelFormat
         */
        PixelFormatEnum getPixelFormat() const noexcept;

        /**
         * \brief
         * \return
         * \wrapImpl SDL_GetWindowID Video::Window::getID
         */
        Uint32 getID() const noexcept;

        /**
         * \brief
         * \return
         * \wrapImpl SDL_GetWindowFlags Video::Window::getFlags
         */
        WindowFlags getFlags() const noexcept;

        /**
         * \brief
         * \param title
         * \wrapImpl SDL_SetWindowTitle Video::Window::setTitle
         */
        void setTitle(const char* title) noexcept;

        /**
         * \brief
         * \return
         * \wrapImpl SDL_GetWindowTitle Video::Window::getTitle
         */
        const char* getTitle() const noexcept;

        /**
         * \brief
         * \param icon
         * \wrapImpl SDL_SetWindowIcon Video::Window::setIcon
         */
        void setIcon(const Surface& icon) noexcept;

        /**
         * \brief
         * \param name
         * \param ptr
         * \wrapImpl SDL_SetWindowData Video::Window::setData
         */
        void setData(const char* name, void* ptr) noexcept;

        /**
         * \brief
         * \param name
         * \return
         * \wrapImpl SDL_GetWindowData Video::Window::getData
         */
        void* getData(const char* name) const noexcept;

        /**
         * \brief
         * \param x
         * \param y
         * \wrapImpl SDL_SetWindowPosition Video::Window::setPosition
         */
        void setPosition(int x, int y) noexcept;

        /**
         * \brief
         * \param x
         * \param y
         * \wrapImpl SDL_GetWindowPosition Video::Window::getPosition
         */
        void getPosition(int& x, int& y) const noexcept;

        /**
         * \brief
         * \param w
         * \param h
         * \wrapImpl SDL_SetWindowSize Video::Window::setSize
         */
        void setSize(int w, int h) noexcept;

        /**
         * \brief
         * \param w
         * \param h
         * \wrapImpl SDL_GetWindowSize Video::Window::getSize
         */
        void getSize(int& w, int& h) const noexcept;

        /**
         * \brief
         * \param minW
         * \param minH
         * \wrapImpl SDL_SetWindowMinimumSize Video::Window::setMinimumSize
         */
        void setMinimumSize(int minW, int minH) noexcept;

        /**
         * \brief
         * \param minW
         * \param minH
         * \wrapImpl SDL_GetWindowMinimumSize Video::Window::getMinimumSize
         */
        void getMinimumSize(int& minW, int& minH) const noexcept;

        /**
         * \brief
         * \param minW
         * \param minH
         * \wrapImpl SDL_SetWindowMaximumSize Video::Window::setMaximumSize
         */
        void setMaximumSize(int minW, int minH) noexcept;

        /**
         * \brief
         * \param minW
         * \param minH
         * \wrapImpl SDL_GetWindowMaximumSize Video::Window::getMaximumSize
         */
        void getMaximumSize(int& minW, int& minH) const noexcept;

        /**
         * \brief
         * \param top
         * \param left
         * \param bottom
         * \param right
         * \return
         * \wrapImpl SDL_GetWindowBordersSize Video::Window::getBordersSize
         */
        EmptyResult getBordersSize(int& top, int& left, int& bottom, int& right) const noexcept;

        /**
         * \brief
         * \param bordered
         * \wrapImpl SDL_SetWindowBordered Video::Window::setBordered
         */
        void setBordered(bool bordered) noexcept;

        /**
         * \brief
         * \param resizable
         * \wrapImpl SDL_SetWindowResizable Video::Window::setResizable
         */
        void setResizable(bool resizable) noexcept;

        /**
         * \brief
         * \param flags
         * \return
         * \wrapImpl SDL_SetWindowFullscreen Video::Window::setFullscreen
         */
        EmptyResult setFullscreen(WindowFlags flags) noexcept;

        /**
         * \brief
         * \wrapImpl SDL_SetWindowInputFocus Video::Window::setInputFocus
         */
        void setInputFocus() noexcept;

        /**
         * \brief
         * \param grab
         * \wrapImpl SDL_SetWindowGrab Video::Window::setGrab
         */
        void setGrab(bool grab) noexcept;

        /**
         * \brief
         * \return
         * \wrapImpl SDL_GetWindowGrab Video::Window::getGrab
         */
        bool getGrab() const noexcept;

        /**
         * \brief
         * \param brightness
         * \return
         * \wrapImpl SDL_SetWindowBrightness Video::Window::setBrightness
         */
        EmptyResult setBrightness(float brightness) noexcept;

        /**
         * \brief
         * \return
         * \wrapImpl SDL_GetWindowBrightness Video::Window::getBrightness
         */
        float getBrightness() const noexcept;

        /**
         * \brief
         * \param opacity
         * \return
         * \wrapImpl SDL_SetWindowOpacity Video::Window::setOpacity
         */
        EmptyResult setOpacity(float opacity) noexcept;

        /**
         * \brief
         * \return
         * \wrapImpl SDL_GetWindowOpacity Video::Window::getOpacity
         */
        sdl2wrap::Result<float> getOpacity() const noexcept;

        /**
         * \brief
         * \param parent
         * \return
         * \wrapImpl SDL_SetWindowModalFor Video::Window::setModalFor
         */
        EmptyResult setModalFor(Window& parent) noexcept;

        /**
         * \brief
         * \param red
         * \param green
         * \param blue
         * \return
         * \wrapImpl SDL_SetWindowGammaRamp Video::Window::setGammaRamp
         */
        EmptyResult setGammaRamp(const Uint16* red, const Uint16* green, const Uint16* blue) noexcept;

        /**
         * \brief
         * \param red
         * \param green
         * \param blue
         * \return
         * \wrapImpl SDL_GetWindowGammaRamp Video::Window::getGammaRamp
         */
        EmptyResult getGammaRamp(Uint16* red, Uint16* green, Uint16* blue) const noexcept;

        /**
         * \brief
         * \param callback
         * \param callbackData
         * \return
         * \wrapImpl SDL_SetWindowHitTest Video::Window::setHitTestCallback
         */
        EmptyResult setHitTestCallback(HitTestCallback callback, void* callbackData) noexcept;

        /**
         * \brief
         * \wrapImpl SDL_ShowWindow Video::Window::show
         */
        void show() noexcept;

        /**
         * \brief
         * \wrapImpl SDL_HideWindow Video::Window::hide
         */
        void hide() noexcept;

        /**
         * \brief
         * \wrapImpl SDL_RaiseWindow Video::Window::raise
         */
        void raise() noexcept;

        /**
         * \brief
         * \wrapImpl SDL_MaximizeWindow Video::Window::maximize
         */
        void maximize() noexcept;

        /**
         * \brief
         * \wrapImpl SDL_MinimizeWindow Video::Window::minimize
         */
        void minimize() noexcept;

        /**
         * \brief
         * \wrapImpl SDL_RestoreWindow Video::Window::restore
         */
        void restore() noexcept;
    };

}; // namespace Video
}; // namespace sdl2wrap

#endif //sdl2wrap_window_h
