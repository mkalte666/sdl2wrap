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
SDL2WRAP_INLINE Surface::Result Surface::checkPtrAndMakeResult(SDL_Surface* ptr) noexcept
{
    if (ptr == nullptr) {
        return Result::error(0);
    }

    return Result::success(Surface(ptr));
}

SDL2WRAP_INLINE Surface::Result Surface::createRGB(int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept
{
    return checkPtrAndMakeResult(SDL_CreateRGBSurface(0, width, height, depth, Rmask, Gmask, Bmask, Amask));
}

SDL2WRAP_INLINE Surface::Result Surface::createRGBWithFormat(int width, int height, int depth, PixelFormatEnum format) noexcept
{
    return checkPtrAndMakeResult(SDL_CreateRGBSurfaceWithFormat(0, width, height, depth, static_cast<Uint32>(format)));
}

SDL2WRAP_INLINE Surface::Result Surface::createRGBfrom(void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept
{
    return checkPtrAndMakeResult(SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask));
}

SDL2WRAP_INLINE Surface::Result Surface::createRGBWithFormatFrom(void* pixels, int width, int height, int depth, int pitch, PixelFormatEnum format) noexcept
{
    return checkPtrAndMakeResult(SDL_CreateRGBSurfaceWithFormatFrom(pixels, width, height, depth, pitch, static_cast<Uint32>(format)));
}

SDL2WRAP_INLINE Surface::Result Surface::loadBMP(File::RWops& rwops) noexcept
{
    return checkPtrAndMakeResult(SDL_LoadBMP_RW(rwops.get(), 0));
}

SDL2WRAP_INLINE Surface::Result Surface::loadBMP(const char* filename) noexcept
{
    auto rwopsRes = File::RWops::fromFile(filename, "rb");
    if (!rwopsRes) {
        return Result::error(rwopsRes);
    }

    return loadBMP(rwopsRes.getValue());
}

SDL2WRAP_INLINE EmptyResult Surface::saveBMP(File::RWops& rwops) const noexcept
{
    auto rc = SDL_SaveBMP_RW(get(), rwops.get(), 0);
    if (rc != 0) {
        return EmptyResult::error(rc);
    }

    return EmptyResult::success(true);
}

SDL2WRAP_INLINE EmptyResult Surface::saveBMP(const char* filename) const noexcept
{
    auto rwopsRes = File::RWops::fromFile(filename, "wb");
    if (!rwopsRes) {
        return EmptyResult::error(rwopsRes);
    }

    return saveBMP(rwopsRes.getValue());
}

}; // namespace Video