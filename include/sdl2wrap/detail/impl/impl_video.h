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
    SDL_Rect sdlrect = {};
    auto rc = SDL_GetDisplayBounds(displayIndex, &sdlrect);
    if (rc == 0) {
        return Result<Rect>::success(Rect(sdlrect));
    }

    return Result<Rect>::error(rc);
}

SDL2WRAP_INLINE Result<Rect> getDisplayUsableBounds(int displayIndex) noexcept
{
    SDL_Rect sdlrect = {};
    auto rc = SDL_GetDisplayUsableBounds(displayIndex, &sdlrect);
    if (rc == 0) {
        return Result<Rect>::success(Rect(sdlrect));
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

    SDL2WRAP_INLINE Context::Result Context::create(Window& window) noexcept
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

    SDL2WRAP_INLINE void* getProcAddress(const char* proc) noexcept
    {
        return SDL_GL_GetProcAddress(proc);
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

    SDL2WRAP_INLINE EmptyResult getAttribute(GLattr attr, int& value) noexcept
    {
        auto rc = SDL_GL_GetAttribute(static_cast<SDL_GLattr>(attr), &value);
        return checkEmptyResultRc(rc);
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

}; // namespace GL

SDL2WRAP_INLINE Window::Result Window::create(const char* title, int x, int y, int w, int h, WindowFlags flags) noexcept
{
    SDL_Window* window = SDL_CreateWindow(title, x, y, w, h, static_cast<Uint32>(flags));
    return checkPtr(window);
}

SDL2WRAP_INLINE Window::Result Window::createCentered(const char* title, int w, int h, WindowFlags flags) noexcept
{
    // sign conversion for SDL_WINDOWPOS_CENTERED
    // NOLINTNEXTLINE
    return create(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
}

SDL2WRAP_INLINE Window::Result Window::createFrom(void* nativeWindow) noexcept
{
    return checkPtr(SDL_CreateWindowFrom(nativeWindow));
}

};