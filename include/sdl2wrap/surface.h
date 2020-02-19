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

#ifndef sdl2wrap_surface_h
#define sdl2wrap_surface_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on
#include "blendmode.h"
#include "detail/typewrapper.h"
#include "detail/generated/generated_sdl_surface.h"
#include "pixels.h"
#include "rect.h"
#include "rwops.h"

namespace sdl2wrap {

namespace Video {

    class Surface : public TypeWrapperWithPtrOp<Surface, SDL_Surface*, SDL_FreeSurface> {
    public:
        using TypeWrapperWithPtrOp::TypeWrapperWithPtrOp;

        static Result createRGB(int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept;
        static Result createRGBWithFormat(int width, int height, int depth, PixelFormatEnum format) noexcept;

        static Result createRGBfrom(void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept;
        static Result createRGBWithFormatFrom(void* pixels, int width, int height, int depth, int pitch, PixelFormatEnum format) noexcept;

        static Result loadBMP(File::RWops& rwops) noexcept;
        static Result loadBMP(const char* filename) noexcept;
        EmptyResult saveBMP(File::RWops& rwops) const noexcept;
        EmptyResult saveBMP(const char* filename) const noexcept;

        EmptyResult setPalette(const Palette& palette) noexcept;

        EmptyResult lock() noexcept;
        void unlock() noexcept;
        bool mustLock() const noexcept;

        EmptyResult setRLE(bool enable) noexcept;
        EmptyResult setColorKey(bool enable, Uint32 key) noexcept;
        bool hasColorKey() const noexcept;

        EmptyResult setColorMod(Uint8 r, Uint8 g, Uint8 b) noexcept;
        EmptyResult getColorMod(Uint8& r, Uint8& g, Uint8& b) const noexcept;
        EmptyResult setAlphaMod(Uint8 alpha) noexcept;
        EmptyResult getAlphaMod(Uint8& alpha) const noexcept;

        EmptyResult setBlendMode(BlendMode mode) noexcept;
        EmptyResult getBlendMode(BlendMode& mode) const noexcept;

        bool setClipRect(const Rect& rect) noexcept;
        bool resetClipRect() const noexcept;

        Result duplicate() const noexcept;
        Result convert(const PixelFormat& format) const noexcept;
        Result convertFormat(PixelFormatEnum format) const noexcept;

        static EmptyResult convertPixels(int width, int height, PixelFormatEnum srcFormat, const void* format, int srcPitch, PixelFormatEnum dstFormat, void* dst, int dstPitch) noexcept;

        EmptyResult fillRect(const Rect& rect, Uint32 color) noexcept;
        // fillRects()

        EmptyResult blit(Surface& dst) const noexcept;
        EmptyResult blit(Surface& dst, const Rect& dstRect) const noexcept;
        EmptyResult blit(const Rect& srcRect, Surface& dst) const noexcept;
        EmptyResult blit(const Rect& srcRect, Surface& dst, const Rect& dstRect) const noexcept;

        EmptyResult blitScaled(Surface& dst) const noexcept;
        EmptyResult blitScaled(Surface& dst, const Rect& dstRect) const noexcept;
        EmptyResult blitScaled(const Rect& srcRect, Surface& dst) const noexcept;
        EmptyResult blitScaled(const Rect& srcRect, Surface& dst, const Rect& dstRect) const noexcept;

        EmptyResult softStretch(const Rect& srcRect, Surface& dst, const Rect& dstRect) const noexcept;

    private:
        static Result checkPtrAndMakeResult(SDL_Surface* ptr) noexcept;
    };

    void setYUVConversionMode(YUV_CONVERSION_MODE mode) noexcept;
    YUV_CONVERSION_MODE getYUVConversionMode() noexcept;
    YUV_CONVERSION_MODE getYUVConversionModeForResolution(int width, int height) noexcept;

#ifndef SDLSDL2WRAP_DEFINITIONS

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

#endif // SDL2WRAP_DEFINITIONS

}; // namespace Video

}; // namespace sdl2wrap

#endif //sdl2wrap_surface_h
