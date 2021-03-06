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

        static ResultType createRGB(int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept;
        static ResultType createRGBWithFormat(int width, int height, int depth, PixelFormatEnum format) noexcept;

        static ResultType createRGBfrom(void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept;
        static ResultType createRGBWithFormatFrom(void* pixels, int width, int height, int depth, int pitch, PixelFormatEnum format) noexcept;

        static ResultType loadBMP(File::RWops& rwops) noexcept;
        static ResultType loadBMP(const char* filename) noexcept;
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
        sdl2wrap::Result<Uint8> getAlphaMod() const noexcept;

        EmptyResult setBlendMode(BlendMode mode) noexcept;
        sdl2wrap::Result<BlendMode> getBlendMode() const noexcept;

        bool setClipRect(const Rect& rect) noexcept;
        bool resetClipRect() const noexcept;

        ResultType duplicate() const noexcept;
        ResultType convert(const PixelFormat& format) const noexcept;
        ResultType convertFormat(PixelFormatEnum format) const noexcept;

        static EmptyResult convertPixels(int width, int height, PixelFormatEnum srcFormat, const void* format, int srcPitch, PixelFormatEnum dstFormat, void* dst, int dstPitch) noexcept;

        EmptyResult fill(const Rect& rect, Uint32 color) noexcept;
        EmptyResult fill(Uint32 color) noexcept;
        // fillRects()

        EmptyResult blit(Surface& dst) const noexcept;
        EmptyResult blit(Surface& dst, Rect& dstRect) const noexcept;
        EmptyResult blit(Rect& srcRect, Surface& dst) const noexcept;
        EmptyResult blit(Rect& srcRect, Surface& dst, Rect& dstRect) const noexcept;

        EmptyResult blitScaled(Surface& dst) const noexcept;
        EmptyResult blitScaled(Surface& dst, Rect& dstRect) const noexcept;
        EmptyResult blitScaled(Rect& srcRect, Surface& dst) const noexcept;
        EmptyResult blitScaled(Rect& srcRect, Surface& dst, Rect& dstRect) const noexcept;

        EmptyResult softStretch(Rect& srcRect, Surface& dst, Rect& dstRect) const noexcept;
    };

    void setYUVConversionMode(YUV_CONVERSION_MODE mode) noexcept;
    YUV_CONVERSION_MODE getYUVConversionMode() noexcept;
    YUV_CONVERSION_MODE getYUVConversionModeForResolution(int width, int height) noexcept;

} // namespace Video

} // namespace sdl2wrap

#endif //sdl2wrap_surface_h
