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

#ifndef sdl2wrap_render_h
#define sdl2wrap_render_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on
#include "detail/generated/generated_sdl_render.h"
#include "detail/typewrapper.h"

#include "rect.h"
#include "video.h"

namespace sdl2wrap {
namespace Video {
    using RendererInfo = SDL_RendererInfo;

    int getNumRenderDrivers() noexcept;
    Result<RendererInfo> getRenderDriverInfo(int index) noexcept;

    class Texture : public TypeWrapper<Texture, SDL_Texture*, SDL_DestroyTexture> {
    public:
        using TypeWrapper::TypeWrapper;
        EmptyResult query(PixelFormatEnum& format, TextureAccess& access, int& w, int& h) const noexcept;
        EmptyResult setColorMod(Uint8 r, Uint8 g, Uint8 b) noexcept;
        EmptyResult getColorMod(Uint8& r, Uint8& g, Uint8& b) const noexcept;
        EmptyResult setAlphaMod(Uint8 alpha) noexcept;
        sdl2wrap::Result<Uint8> getAlphaMod() const noexcept;
        EmptyResult setBlendMode(BlendMode mode) noexcept;
        sdl2wrap::Result<BlendMode> getBlendMode() const noexcept;
        EmptyResult setScaleMode(ScaleMode mode) noexcept;
        sdl2wrap::Result<ScaleMode> getScaleMode() const noexcept;
        EmptyResult update(const Rect& rect, const void* pixels, int pitch) noexcept;
        EmptyResult updateYUV(const Rect& rect, const Uint8* Yplane, int Ypitch,
            const Uint8* Uplane, int Upitch,
            const Uint8* Vplane, int Vpitch) noexcept;
        EmptyResult lock(const Rect& rect, void*& pixels, int& pitch) noexcept;
        void unlock() noexcept;
        //Surface::Result SDL_LockTextureToSurface(const Rect& rect) noexcept;
    };

    class Renderer : public TypeWrapper<Renderer, SDL_Renderer*, SDL_DestroyRenderer> {
    public:
        using TypeWrapper::TypeWrapper;
        static Result create(Window& window, int index, RendererFlags flags) noexcept;
        static Result createSoftwareRenderer(Surface& surface) noexcept;
        //static Result getRenderer(Window& window) noexcept;

        Texture::Result createTexture(PixelFormatEnum format, TextureAccess access, int w, int h) noexcept;
        Texture::Result createTextureFromSurface(Surface& surface) noexcept;

        sdl2wrap::Result<RendererInfo> getInfo() const noexcept;
        EmptyResult getOutputSize(int& w, int& h) const noexcept;

        bool getRenderRagetSupported() const noexcept;
        EmptyResult setRenderTarget(Texture& texture) noexcept;
        //Texture::Result getRenderTarget() const noexcept;

        EmptyResult setLogicalSize(int w, int h) noexcept;
        void getLogicalSize(int& w, int& h) const noexcept;
        EmptyResult setIntegerScale(bool enable) noexcept;
        bool getIntegerScale() const noexcept;
        EmptyResult setViewport(const Rect& rect) noexcept;
        Rect getViewport() const noexcept;

        EmptyResult setClipRect(const Rect& rect) noexcept;
        EmptyResult resetClipRect() noexcept;
        Rect getClipRect() const noexcept;
        bool isClipEnabled() const noexcept;

        EmptyResult setScale(float scaleX, float scaleY) noexcept;
        void getScale(float& scaleX, float scaleY) const noexcept;

        EmptyResult setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) noexcept;
        EmptyResult setDrawColor(const Color& color) noexcept;
        void getDrawColor(Uint8& r, Uint8& g, Uint8& b, Uint8& a) const noexcept;
        Color getDrawColor() const noexcept;

        EmptyResult setDrawBlendMode(BlendMode blendMode) noexcept;
        sdl2wrap::Result<BlendMode> getDrawBlendMode() const noexcept;

        EmptyResult clear() noexcept;

        EmptyResult drawPoint(int x, int y) noexcept;
        EmptyResult drawPoints(const Point* points, int count) noexcept;

        EmptyResult drawLine(int x1, int y1, int x2, int y2) noexcept;
        EmptyResult drawLines(const Point* points, int count) noexcept;

        EmptyResult drawRect(const Rect& rect) noexcept;
        EmptyResult drawRects(const Rect* rects, int count) noexcept;

        EmptyResult fillRect(const Rect& rect) noexcept;
        EmptyResult fillRects(const Rect* rects, int count) noexcept;

        EmptyResult copy(Texture& tex, const Rect* srcRect, const Rect* dstRect) noexcept;
        EmptyResult copy(Texture& tex) noexcept;
        EmptyResult copy(Texture& tex, const Rect& srcRect, const Rect& dstRect) noexcept;
        EmptyResult copyWithSrcRect(Texture& tex, const Rect& srcRect) noexcept;
        EmptyResult copyWithDstRect(Texture& tex, const Rect& dstRect) noexcept;

        EmptyResult copyEx(Texture& tex, const Rect* srcrect, const Rect* dstrect, double angle, Point center, RendererFlip flip) noexcept;
        EmptyResult copyEx(Texture& tex, double angle, Point center, RendererFlip flip) noexcept;
        EmptyResult copyEx(Texture& tex, const Rect& srcrect, const Rect& dstrect, double angle, Point center, RendererFlip flip) noexcept;
        EmptyResult copyWithSrcRect(Texture& tex, const Rect& srcrect, double angle, Point center, RendererFlip flip) noexcept;
        EmptyResult copyWithDstRect(Texture& tex, const Rect& dstrect, double angle, Point center, RendererFlip flip) noexcept;

        EmptyResult drawPointF(float x, float y) noexcept;
        EmptyResult drawPointsF(const FPoint* points, int count) noexcept;

        EmptyResult drawLineF(float x1, float y1, float x2, float y2) noexcept;
        EmptyResult drawLinesF(const FPoint* points, int count) noexcept;

        EmptyResult drawRectF(const FRect& rect) noexcept;
        EmptyResult drawRectsF(const FRect* rects, int count) noexcept;

        EmptyResult fillRectF(const FRect& rect) noexcept;
        EmptyResult fillRectsF(const FRect* rects, int count) noexcept;

        EmptyResult copyF(Texture& tex, const Rect* srcRect, const FRect* dstRect) noexcept;
        EmptyResult copyF(Texture& tex) noexcept;
        EmptyResult copyF(Texture& tex, const Rect& srcRect, const FRect& dstRect) noexcept;
        EmptyResult copyWithSrcRectF(Texture& tex, const Rect& srcRect) noexcept;
        EmptyResult copyWithDstRectF(Texture& tex, const FRect& dstRect) noexcept;

        EmptyResult copyExF(Texture& tex, const Rect* srcrect, const FRect* dstrect, double angle, FPoint center, RendererFlip flip) noexcept;
        EmptyResult copyExF(Texture& tex, double angle, FPoint center, RendererFlip flip) noexcept;
        EmptyResult copyExF(Texture& tex, const Rect& srcrect, const FRect& dstrect, double angle, FPoint center, RendererFlip flip) noexcept;
        EmptyResult copyWithSrcRectF(Texture& tex, const Rect& srcrect, double angle, FPoint center, RendererFlip flip) noexcept;
        EmptyResult copyWithDstRectF(Texture& tex, const FRect& dstrect, double angle, FPoint center, RendererFlip flip) noexcept;

        void present() noexcept;
        void flush() noexcept;
    };

    namespace GL {
        EmptyResult bindTexture(Texture& tex, float& w, float& h) noexcept;
        EmptyResult unbindTexture(Texture& tex) noexcept;
    }

    namespace Metal {
        void* renderGetMetalLayer(Renderer& renderer) noexcept;
        void* renderGetMetalCommandEncoder(Renderer& renderer) noexcept;
    }

}; // namespace Video
}; // namespace sdl2wrap

#endif //sdl2wrap_render_h
