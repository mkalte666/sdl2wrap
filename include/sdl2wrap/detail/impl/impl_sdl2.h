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