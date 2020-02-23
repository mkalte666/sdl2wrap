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

SDL2WRAP_INLINE Surface::Result Surface::createRGB(int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept
{
    return checkPtr(SDL_CreateRGBSurface(0, width, height, depth, Rmask, Gmask, Bmask, Amask));
}

SDL2WRAP_INLINE Surface::Result Surface::createRGBWithFormat(int width, int height, int depth, PixelFormatEnum format) noexcept
{
    return checkPtr(SDL_CreateRGBSurfaceWithFormat(0, width, height, depth, static_cast<Uint32>(format)));
}

SDL2WRAP_INLINE Surface::Result Surface::createRGBfrom(void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept
{
    return checkPtr(SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask));
}

SDL2WRAP_INLINE Surface::Result Surface::createRGBWithFormatFrom(void* pixels, int width, int height, int depth, int pitch, PixelFormatEnum format) noexcept
{
    return checkPtr(SDL_CreateRGBSurfaceWithFormatFrom(pixels, width, height, depth, pitch, static_cast<Uint32>(format)));
}

SDL2WRAP_INLINE Surface::Result Surface::loadBMP(File::RWops& rwops) noexcept
{
    return checkPtr(SDL_LoadBMP_RW(rwops.get(), 0));
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
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::saveBMP(const char* filename) const noexcept
{
    auto rwopsRes = File::RWops::fromFile(filename, "wb");
    if (!rwopsRes) {
        return EmptyResult::error(rwopsRes);
    }

    return saveBMP(rwopsRes.getValue());
}

SDL2WRAP_INLINE EmptyResult Surface::setPalette(const Palette& palette) noexcept
{
    auto rc = SDL_SetSurfacePalette(get(), palette.get());
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::lock() noexcept
{
    auto rc = SDL_LockSurface(get());
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void Surface::unlock() noexcept
{
    SDL_UnlockSurface(get());
}

SDL2WRAP_INLINE bool Surface::mustLock() const noexcept
{
    auto* p = get();
    return SDL_MUSTLOCK(p); //NOLINT the sdl marco has issues
}

SDL2WRAP_INLINE EmptyResult Surface::setRLE(bool enable) noexcept
{
    auto rc = SDL_SetSurfaceRLE(get(), enable ? 1 : 0);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::setColorKey(bool enable, Uint32 key) noexcept
{
    auto rc = SDL_SetColorKey(get(), enable ? 1 : 0, key);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE bool Surface::hasColorKey() const noexcept
{
    return SDL_HasColorKey(get()) == SDL_TRUE;
}

SDL2WRAP_INLINE EmptyResult Surface::setColorMod(Uint8 r, Uint8 g, Uint8 b) noexcept
{
    auto rc = SDL_SetSurfaceColorMod(get(), r, g, b);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::getColorMod(Uint8& r, Uint8& g, Uint8& b) const noexcept
{
    auto rc = SDL_GetSurfaceColorMod(get(), &r, &g, &b);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::setAlphaMod(Uint8 alpha) noexcept
{
    auto rc = SDL_SetSurfaceAlphaMod(get(), alpha);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE sdl2wrap::Result<Uint8> Surface::getAlphaMod() const noexcept
{
    Uint8 alpha = 0;
    auto rc = SDL_GetSurfaceAlphaMod(get(), &alpha);
    if (rc == 0) {
        return sdl2wrap::Result<Uint8>::success(move(alpha));
    }

    return sdl2wrap::Result<Uint8>::error(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::setBlendMode(BlendMode mode) noexcept
{
    auto rc = SDL_SetSurfaceBlendMode(get(), static_cast<SDL_BlendMode>(mode));
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE sdl2wrap::Result<BlendMode> Surface::getBlendMode() const noexcept
{
    BlendMode mode;
    SDL_BlendMode sdlmode;
    auto rc = SDL_GetSurfaceBlendMode(get(), &sdlmode);
    mode = static_cast<BlendMode>(sdlmode);
    if (rc == 0) {
        return sdl2wrap::Result<BlendMode>::success(move(mode));
    }

    return sdl2wrap::Result<BlendMode>::error(rc);
}

SDL2WRAP_INLINE bool Surface::setClipRect(const Rect& rect) noexcept
{
    auto sdlrect = rect.toSDLRect();
    return SDL_SetClipRect(get(), &sdlrect) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Surface::resetClipRect() const noexcept
{
    return SDL_SetClipRect(get(), nullptr) == SDL_TRUE;
    ;
}

SDL2WRAP_INLINE Surface::Result Surface::duplicate() const noexcept
{
    auto newPtr = SDL_DuplicateSurface(get());
    return checkPtr(newPtr);
}

SDL2WRAP_INLINE Surface::Result Surface::convert(const PixelFormat& format) const noexcept
{
    auto newPtr = SDL_ConvertSurface(get(), format.get(), 0);
    return checkPtr(newPtr);
}

SDL2WRAP_INLINE Surface::Result Surface::convertFormat(PixelFormatEnum format) const noexcept
{
    auto newPtr = SDL_ConvertSurfaceFormat(get(), static_cast<SDL_PixelFormatEnum>(format), 0);
    return checkPtr(newPtr);
}

SDL2WRAP_INLINE EmptyResult Surface::convertPixels(int width, int height, PixelFormatEnum srcFormat, const void* format, int srcPitch, PixelFormatEnum dstFormat, void* dst, int dstPitch) noexcept
{
    auto rc = SDL_ConvertPixels(width, height, static_cast<SDL_PixelFormatEnum>(srcFormat), format, srcPitch, static_cast<SDL_PixelFormatEnum>(dstFormat), dst, dstPitch);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::fill(const Rect& rect, Uint32 color) noexcept
{
    auto sdlrect = rect.toSDLRect();
    auto rc = SDL_FillRect(get(), &sdlrect, color);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::fill(Uint32 color) noexcept
{
    auto rc = SDL_FillRect(get(), nullptr, color);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::blit(Surface& dst) const noexcept
{
    auto rc = SDL_BlitSurface(get(), nullptr, dst.get(), nullptr);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::blit(Surface& dst, const Rect& dstRect) const noexcept
{
    auto dstRectSdl = dstRect.toSDLRect();
    auto rc = SDL_BlitSurface(get(), nullptr, dst.get(), &dstRectSdl);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::blit(const Rect& srcRect, Surface& dst) const noexcept
{
    auto srcRectSdl = srcRect.toSDLRect();
    auto rc = SDL_BlitSurface(get(), &srcRectSdl, dst.get(), nullptr);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::blit(const Rect& srcRect, Surface& dst, const Rect& dstRect) const noexcept
{
    auto srcRectSdl = srcRect.toSDLRect();
    auto dstRectSdl = dstRect.toSDLRect();
    auto rc = SDL_BlitSurface(get(), &srcRectSdl, dst.get(), &dstRectSdl);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::blitScaled(Surface& dst) const noexcept
{
    auto rc = SDL_BlitScaled(get(), nullptr, dst.get(), nullptr);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::blitScaled(Surface& dst, const Rect& dstRect) const noexcept
{
    auto dstRectSdl = dstRect.toSDLRect();
    auto rc = SDL_BlitScaled(get(), nullptr, dst.get(), &dstRectSdl);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::blitScaled(const Rect& srcRect, Surface& dst) const noexcept
{
    auto srcRectSdl = srcRect.toSDLRect();
    auto rc = SDL_BlitScaled(get(), &srcRectSdl, dst.get(), nullptr);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::blitScaled(const Rect& srcRect, Surface& dst, const Rect& dstRect) const noexcept
{
    auto srcRectSdl = srcRect.toSDLRect();
    auto dstRectSdl = dstRect.toSDLRect();
    auto rc = SDL_BlitScaled(get(), &srcRectSdl, dst.get(), &dstRectSdl);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Surface::softStretch(const Rect& srcRect, Surface& dst, const Rect& dstRect) const noexcept
{
    auto srcRectSdl = srcRect.toSDLRect();
    auto dstRectSdl = dstRect.toSDLRect();
    auto rc = SDL_SoftStretch(get(), &srcRectSdl, dst.get(), &dstRectSdl);
    return checkEmptyResultRc(rc);
}

}; // namespace Video