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

namespace Video {

SDL2WRAP_INLINE int getNumVideoDrivers() noexcept
{
    return SDL_GetNumVideoDisplays();
}

SDL2WRAP_INLINE const char* getVideoDriver(int index) noexcept
{
    return SDL_GetVideoDriver(index);
}

SDL2WRAP_INLINE EmptyResult init(const char* driverName) noexcept
{
    return checkEmptyResultRc(SDL_VideoInit(driverName));
}

SDL2WRAP_INLINE void quit() noexcept
{
    SDL_VideoQuit();
}

SDL2WRAP_INLINE const char* getCurrentDriver() noexcept
{
    return SDL_GetCurrentVideoDriver();
}

SDL2WRAP_INLINE int getNumDisplays() noexcept
{
    return SDL_GetNumVideoDisplays();
}

SDL2WRAP_INLINE const char* getDisplayName(int displayIndex) noexcept
{
    return SDL_GetDisplayName(displayIndex);
}

SDL2WRAP_INLINE Result<Rect> getDisplayBounds(int displayIndex) noexcept
{
    Rect rect = {};
    auto rc = SDL_GetDisplayBounds(displayIndex, &rect);
    if (rc == 0) {
        return Result<Rect>::success(move(rect));
    }

    return Result<Rect>::error(rc);
}

SDL2WRAP_INLINE Result<Rect> getDisplayUsableBounds(int displayIndex) noexcept
{
    Rect rect = {};
    auto rc = SDL_GetDisplayUsableBounds(displayIndex, &rect);
    if (rc == 0) {
        return Result<Rect>::success(move(rect));
    }

    return Result<Rect>::error(rc);
}

SDL2WRAP_INLINE EmptyResult getDisplayDPI(int displayIndex, float& ddpi, float& hdpi, float& vdpi) noexcept
{
    return checkEmptyResultRc(SDL_GetDisplayDPI(displayIndex, &ddpi, &hdpi, &vdpi));
}

SDL2WRAP_INLINE DisplayOrientation getDisplayOrientation(int displayIndex) noexcept
{
    return static_cast<DisplayOrientation>(SDL_GetDisplayOrientation(displayIndex));
}

SDL2WRAP_INLINE int getNumDisplayModes(int displayIndex) noexcept
{
    return SDL_GetNumDisplayModes(displayIndex);
}

SDL2WRAP_INLINE Result<DisplayMode> getDisplayMode(int displayIndex, int modeIndex) noexcept
{
    DisplayMode mode;
    auto rc = SDL_GetDisplayMode(displayIndex, modeIndex, &mode);
    if (rc == 0) {
        return Result<DisplayMode>::success(move(mode));
    }

    return Result<DisplayMode>::error(rc);
}

SDL2WRAP_INLINE Result<DisplayMode> getDesktopDisplayMode(int displayIndex) noexcept
{
    DisplayMode mode;
    auto rc = SDL_GetDesktopDisplayMode(displayIndex, &mode);
    if (rc == 0) {
        return Result<DisplayMode>::success(move(mode));
    }

    return Result<DisplayMode>::error(rc);
}

SDL2WRAP_INLINE Result<DisplayMode> getCurrentDisplayMode(int displayIndex) noexcept
{
    DisplayMode mode;
    auto rc = SDL_GetCurrentDisplayMode(displayIndex, &mode);
    if (rc == 0) {
        return Result<DisplayMode>::success(move(mode));
    }

    return Result<DisplayMode>::error(rc);
}

SDL2WRAP_INLINE bool getClosestDisplayMode(int displayIndex, const DisplayMode& mode, DisplayMode& closest) noexcept
{
    auto* rcPtr = SDL_GetClosestDisplayMode(displayIndex, &mode, &closest);
    return rcPtr != nullptr;
}

SDL2WRAP_INLINE bool isScreenSaverEnabled() noexcept
{
    return SDL_IsScreenSaverEnabled() == SDL_TRUE;
}

SDL2WRAP_INLINE void enableScreenSaver() noexcept
{
    SDL_EnableScreenSaver();
}

SDL2WRAP_INLINE void disableScreenSaver() noexcept
{
    SDL_DisableScreenSaver();
}

namespace GL {

    SDL2WRAP_INLINE Context::ResultType Context::create(Window& window) noexcept
    {
        auto ptr = SDL_GL_CreateContext(window.get());
        return checkPtr(ptr);
    }

    SDL2WRAP_INLINE EmptyResult loadLibrary(const char* path) noexcept
    {
        auto rc = SDL_GL_LoadLibrary(path);
        return checkEmptyResultRc(rc);
    }

    SDL2WRAP_INLINE void unloadLibrary() noexcept
    {
        SDL_GL_UnloadLibrary();
    }

    SDL2WRAP_INLINE sdl2wrap::Result<void*> getProcAddress(const char* proc) noexcept
    {
        auto ptr = SDL_GL_GetProcAddress(proc);
        if (ptr != nullptr) {
            return sdl2wrap::Result<void*>::success(move(ptr));
        }

        return sdl2wrap::Result<void*>::error(0);
    }

    SDL2WRAP_INLINE bool getExtensionSupported(const char* extension) noexcept
    {
        return SDL_GL_ExtensionSupported(extension) == SDL_TRUE;
    }

    SDL2WRAP_INLINE void resetAttributes() noexcept
    {
        SDL_GL_ResetAttributes();
    }

    SDL2WRAP_INLINE EmptyResult setAttribute(GLattr attr, int value) noexcept
    {
        auto rc = SDL_GL_SetAttribute(static_cast<SDL_GLattr>(attr), value);
        return checkEmptyResultRc(rc);
    }

    SDL2WRAP_INLINE sdl2wrap::Result<int> getAttribute(GLattr attr) noexcept
    {
        int value = 0;
        auto rc = SDL_GL_GetAttribute(static_cast<SDL_GLattr>(attr), &value);
        if (rc == 0) {
            return sdl2wrap::Result<int>::success(move(value));
        }

        return sdl2wrap::Result<int>::error(rc);
    }

    SDL2WRAP_INLINE EmptyResult setSwapInterval(int interval) noexcept
    {
        auto rc = SDL_GL_SetSwapInterval(interval);
        return checkEmptyResultRc(rc);
    }

    SDL2WRAP_INLINE int getSwapInterval() noexcept
    {
        return SDL_GL_GetSwapInterval();
    }

    SDL2WRAP_INLINE void swap(Window& window) noexcept
    {
        return SDL_GL_SwapWindow(window.get());
    }

    SDL2WRAP_INLINE void getDrawableSize(Window& window, int& w, int& h) noexcept
    {
        SDL_GL_GetDrawableSize(window.get(), &w, &h);
    }

    SDL2WRAP_INLINE void makeCurrent(Window& window, Context& context) noexcept
    {
        SDL_GL_MakeCurrent(window.get(), context.get());
    }

} // namespace GL

SDL2WRAP_INLINE Window::ResultType Window::create(const char* title, int x, int y, int w, int h, WindowFlags flags) noexcept
{
    SDL_Window* window = SDL_CreateWindow(title, x, y, w, h, static_cast<Uint32>(flags));
    return checkPtr(window);
}

SDL2WRAP_INLINE Window::ResultType Window::createCentered(const char* title, int w, int h, WindowFlags flags) noexcept
{
    // sign conversion for SDL_WINDOWPOS_CENTERED
    // NOLINTNEXTLINE
    return create(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
}

SDL2WRAP_INLINE Window::ResultType Window::createFrom(void* nativeWindow) noexcept
{
    return checkPtr(SDL_CreateWindowFrom(nativeWindow));
}

SDL2WRAP_INLINE EmptyResult Window::setDisplayMode(const DisplayMode& mode) noexcept
{
    auto rc = SDL_SetWindowDisplayMode(get(), &mode);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE sdl2wrap::Result<DisplayMode> Window::getDisplayMode() const noexcept
{
    SDL_DisplayMode mode;
    auto rc = SDL_GetWindowDisplayMode(get(), &mode);
    if (rc == 0) {
        return sdl2wrap::Result<DisplayMode>::success(static_cast<DisplayMode>(mode));
    }

    return sdl2wrap::Result<DisplayMode>::error(rc);
}

SDL2WRAP_INLINE PixelFormatEnum Window::getPixelFormat() const noexcept
{
    return static_cast<PixelFormatEnum>(SDL_GetWindowPixelFormat(get()));
}

SDL2WRAP_INLINE Uint32 Window::getID() const noexcept
{
    return SDL_GetWindowID(get());
}

SDL2WRAP_INLINE WindowFlags Window::getFlags() const noexcept
{
    return static_cast<WindowFlags>(SDL_GetWindowFlags(get()));
}

SDL2WRAP_INLINE void Window::setTitle(const char* title) noexcept
{
    SDL_SetWindowTitle(get(), title);
}

SDL2WRAP_INLINE const char* Window::getTitle() const noexcept
{
    return SDL_GetWindowTitle(get());
}

SDL2WRAP_INLINE void Window::setIcon(const Surface& icon) noexcept
{
    SDL_SetWindowIcon(get(), icon.get());
}

SDL2WRAP_INLINE void Window::setData(const char* name, void* p) noexcept
{
    SDL_SetWindowData(get(), name, p);
}

SDL2WRAP_INLINE void* Window::getData(const char* name) const noexcept
{
    return SDL_GetWindowData(get(), name);
}

SDL2WRAP_INLINE void Window::setPosition(int x, int y) noexcept
{
    SDL_SetWindowPosition(get(), x, y);
}

SDL2WRAP_INLINE void Window::getPosition(int& x, int& y) const noexcept
{
    SDL_GetWindowPosition(get(), &x, &y);
}

SDL2WRAP_INLINE void Window::setSize(int w, int h) noexcept
{
    SDL_SetWindowSize(get(), w, h);
}

SDL2WRAP_INLINE void Window::getSize(int& w, int& h) const noexcept
{
    SDL_GetWindowSize(get(), &w, &h);
}

SDL2WRAP_INLINE void Window::setMinimumSize(int minW, int minH) noexcept
{
    SDL_SetWindowMinimumSize(get(), minW, minH);
}

SDL2WRAP_INLINE void Window::getMinimumSize(int& minW, int& minH) const noexcept
{
    SDL_GetWindowMinimumSize(get(), &minW, &minH);
}

SDL2WRAP_INLINE void Window::setMaximumSize(int minW, int minH) noexcept
{
    SDL_SetWindowMaximumSize(get(), minW, minH);
}

SDL2WRAP_INLINE void Window::getMaximumSize(int& minW, int& minH) const noexcept
{
    SDL_GetWindowMaximumSize(get(), &minW, &minH);
}

SDL2WRAP_INLINE EmptyResult Window::getBordersSize(int& top, int& left, int& bottom, int& right) const noexcept
{
    auto rc = SDL_GetWindowBordersSize(get(), &top, &left, &bottom, &right);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void Window::setBordered(bool bordered) noexcept
{
    SDL_SetWindowBordered(get(), bordered ? SDL_TRUE : SDL_FALSE);
}

SDL2WRAP_INLINE void Window::setResizable(bool resizable) noexcept
{
    SDL_SetWindowResizable(get(), resizable ? SDL_TRUE : SDL_FALSE);
}

SDL2WRAP_INLINE EmptyResult Window::setFullscreen(WindowFlags flags) noexcept
{
    auto rc = SDL_SetWindowFullscreen(get(), static_cast<SDL_WindowFlags>(flags));
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void Window::setInputFocus() noexcept
{
    SDL_SetWindowInputFocus(get());
}

SDL2WRAP_INLINE void Window::setGrab(bool grab) noexcept
{
    SDL_SetWindowGrab(get(), grab ? SDL_TRUE : SDL_FALSE);
}

SDL2WRAP_INLINE bool Window::getGrab() const noexcept
{
    return SDL_GetWindowGrab(get()) == SDL_TRUE;
}

SDL2WRAP_INLINE EmptyResult Window::setBrightness(float brightness) noexcept
{
    auto rc = SDL_SetWindowBrightness(get(), brightness);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE float Window::getBrightness() const noexcept
{
    return SDL_GetWindowBrightness(get());
}

SDL2WRAP_INLINE EmptyResult Window::setOpacity(float opacity) noexcept
{
    auto rc = SDL_SetWindowOpacity(get(), opacity);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE sdl2wrap::Result<float> Window::getOpacity() const noexcept
{
    float opacity;
    auto rc = SDL_GetWindowOpacity(get(), &opacity);
    if (rc == 0) {
        return sdl2wrap::Result<float>::success(move(opacity));
    }

    return sdl2wrap::Result<float>::error(rc);
}

SDL2WRAP_INLINE EmptyResult Window::setModalFor(Window& parent) noexcept
{
    auto rc = SDL_SetWindowModalFor(get(), parent.get());
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Window::setGammaRamp(const Uint16* red, const Uint16* green, const Uint16* blue) noexcept
{
    auto rc = SDL_SetWindowGammaRamp(get(), red, green, blue);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Window::getGammaRamp(Uint16* red, Uint16* green, Uint16* blue) const noexcept
{
    auto rc = SDL_GetWindowGammaRamp(get(), red, green, blue);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Window::setHitTestCallback(HitTestCallback callback, void* callbackData) noexcept
{
    auto rc = SDL_SetWindowHitTest(get(), callback, callbackData);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void Window::show() noexcept
{
    SDL_ShowWindow(get());
}

SDL2WRAP_INLINE void Window::hide() noexcept
{
    SDL_HideWindow(get());
}

SDL2WRAP_INLINE void Window::raise() noexcept
{
    SDL_RaiseWindow(get());
}

SDL2WRAP_INLINE void Window::maximize() noexcept
{
    SDL_MaximizeWindow(get());
}

SDL2WRAP_INLINE void Window::minimize() noexcept
{
    SDL_MinimizeWindow(get());
}

SDL2WRAP_INLINE void Window::restore() noexcept
{
    SDL_RestoreWindow(get());
}

}