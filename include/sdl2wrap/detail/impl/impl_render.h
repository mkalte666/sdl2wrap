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

#ifndef sdl2wrap_impl_render_h
#define sdl2wrap_impl_render_h

namespace Video {

SDL2WRAP_INLINE int getNumRenderDrivers() noexcept
{
    return SDL_GetNumRenderDrivers();
}

SDL2WRAP_INLINE Result<RendererInfo> getRenderDriverInfo(int index) noexcept
{
    RendererInfo info;
    auto rc = SDL_GetRenderDriverInfo(index, &info);
    if (rc == 0) {
        return Result<RendererInfo>::success(move(info));
    }

    return Result<RendererInfo>::error(rc);
}

SDL2WRAP_INLINE EmptyResult Texture::query(PixelFormatEnum& format, TextureAccess& access, int& w, int& h) const noexcept
{
    auto sdlformat = static_cast<Uint32>(format);
    auto sdlaccess = static_cast<int>(access);
    auto rc = SDL_QueryTexture(get(), &sdlformat, &sdlaccess, &w, &h);
    if (rc == 0) {
        format = static_cast<PixelFormatEnum>(sdlformat);
        access = static_cast<TextureAccess>(sdlaccess);
        return EmptyResult::success(true);
    }

    return EmptyResult::error(rc);
}

SDL2WRAP_INLINE EmptyResult Texture::setColorMod(Uint8 r, Uint8 g, Uint8 b) noexcept
{
    auto rc = SDL_SetTextureColorMod(get(), r, g, b);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Texture::getColorMod(Uint8& r, Uint8& g, Uint8& b) const noexcept
{
    auto rc = SDL_GetTextureColorMod(get(), &r, &g, &b);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Texture::setAlphaMod(Uint8 alpha) noexcept
{
    auto rc = SDL_SetTextureAlphaMod(get(), alpha);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE sdl2wrap::Result<Uint8> Texture::getAlphaMod() const noexcept
{
    Uint8 alpha = 0;
    auto rc = SDL_GetTextureAlphaMod(get(), &alpha);
    if (rc == 0) {
        return sdl2wrap::Result<Uint8>::success(move(alpha));
    }

    return sdl2wrap::Result<Uint8>::error(rc);
}

SDL2WRAP_INLINE EmptyResult Texture::setBlendMode(BlendMode mode) noexcept
{
    auto rc = SDL_SetTextureBlendMode(get(), static_cast<SDL_BlendMode>(mode));
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE sdl2wrap::Result<BlendMode> Texture::getBlendMode() const noexcept
{
    SDL_BlendMode sdlmode;
    auto rc = SDL_GetTextureBlendMode(get(), &sdlmode);
    if (rc == 0) {
        auto mode = static_cast<BlendMode>(sdlmode);
        return sdl2wrap::Result<BlendMode>::success(move(mode));
    }

    return sdl2wrap::Result<BlendMode>::error(rc);
}

SDL2WRAP_INLINE EmptyResult Texture::setScaleMode(ScaleMode mode) noexcept
{
    auto rc = SDL_SetTextureScaleMode(get(), static_cast<SDL_ScaleMode>(mode));
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE sdl2wrap::Result<ScaleMode> Texture::getScaleMode() const noexcept
{
    SDL_ScaleMode sdlmode;
    auto rc = SDL_GetTextureScaleMode(get(), &sdlmode);
    if (rc == 0) {
        auto mode = static_cast<ScaleMode>(sdlmode);
        return sdl2wrap::Result<ScaleMode>::success(move(mode));
    }

    return sdl2wrap::Result<ScaleMode>::error(rc);
}

SDL2WRAP_INLINE EmptyResult Texture::update(const Rect& rect, const void* pixels, int pitch) noexcept
{
    auto rc = SDL_UpdateTexture(get(), &rect, pixels, pitch);

    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Texture::updateYUV(const Rect& rect, const Uint8* Yplane, int Ypitch, const Uint8* Uplane, int Upitch, const Uint8* Vplane, int Vpitch) noexcept
{
    auto rc = SDL_UpdateYUVTexture(get(), &rect, Yplane, Ypitch, Uplane, Upitch, Vplane, Vpitch);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Texture::lock(const Rect& rect, void*& pixels, int& pitch) noexcept
{
    auto rc = SDL_LockTexture(get(), &rect, &pixels, &pitch);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void Texture::unlock() noexcept
{
    SDL_UnlockTexture(get());
}

SDL2WRAP_INLINE Renderer::Result Renderer::create(Window& window, int index, RendererFlags flags) noexcept
{
    auto renderer = SDL_CreateRenderer(window.get(), index, static_cast<Uint32>(flags));
    return checkPtr(renderer);
}

SDL2WRAP_INLINE Renderer::Result Renderer::createSoftwareRenderer(Surface& surface) noexcept
{
    auto renderer = SDL_CreateSoftwareRenderer(surface.get());
    return checkPtr(renderer);
}

SDL2WRAP_INLINE Texture::Result Renderer::createTexture(PixelFormatEnum format, TextureAccess access, int w, int h) noexcept
{
    auto tex = SDL_CreateTexture(get(), static_cast<Uint32>(format), static_cast<int>(access), w, h);
    return Texture::checkPtr(tex);
}

SDL2WRAP_INLINE Texture::Result Renderer::createTextureFromSurface(Surface& surface) noexcept
{
    auto tex = SDL_CreateTextureFromSurface(get(), surface.get());
    return Texture::checkPtr(tex);
}

SDL2WRAP_INLINE sdl2wrap::Result<RendererInfo> Renderer::getInfo() const noexcept
{
    RendererInfo info;
    auto rc = SDL_GetRendererInfo(get(), &info);
    if (rc == 0) {
        return sdl2wrap::Result<RendererInfo>::success(move(info));
    }

    return sdl2wrap::Result<RendererInfo>::error(rc);
}

SDL2WRAP_INLINE EmptyResult Renderer::getOutputSize(int& w, int& h) const noexcept
{
    auto rc = SDL_GetRendererOutputSize(get(), &w, &h);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE bool Renderer::getRenderRagetSupported() const noexcept
{
    return SDL_RenderTargetSupported(get()) == SDL_TRUE;
}

SDL2WRAP_INLINE EmptyResult Renderer::setRenderTarget(Texture& texture) noexcept
{
    auto rc = SDL_SetRenderTarget(get(), texture.get());
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Renderer::setLogicalSize(int w, int h) noexcept
{
    auto rc = SDL_RenderSetLogicalSize(get(), w, h);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void Renderer::getLogicalSize(int& w, int& h) const noexcept
{
    SDL_RenderGetLogicalSize(get(), &w, &h);
}

SDL2WRAP_INLINE EmptyResult Renderer::setIntegerScale(bool enable) noexcept
{
    auto rc = SDL_RenderSetIntegerScale(get(), enable ? SDL_TRUE : SDL_FALSE);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE bool Renderer::getIntegerScale() const noexcept
{
    return SDL_RenderGetIntegerScale(get()) == SDL_TRUE;
}

SDL2WRAP_INLINE EmptyResult Renderer::setViewport(const Rect& rect) noexcept
{
    auto rc = SDL_RenderSetViewport(get(), &rect);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE Rect Renderer::getViewport() const noexcept
{
    Rect rect;
    SDL_RenderGetViewport(get(), &rect);
    return rect;
}

SDL2WRAP_INLINE EmptyResult Renderer::setClipRect(const Rect& rect) noexcept
{
    auto rc = SDL_RenderSetClipRect(get(), &rect);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Renderer::resetClipRect() noexcept
{
    auto rc = SDL_RenderSetClipRect(get(), nullptr);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE Rect Renderer::getClipRect() const noexcept
{
    Rect rect;
    SDL_RenderGetClipRect(get(), &rect);
    return rect;
}

SDL2WRAP_INLINE bool Renderer::isClipEnabled() const noexcept
{
    return SDL_RenderIsClipEnabled(get()) == SDL_TRUE;
}

SDL2WRAP_INLINE EmptyResult Renderer::setScale(float scaleX, float scaleY) noexcept
{
    auto rc = SDL_RenderSetScale(get(), scaleX, scaleY);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void Renderer::getScale(float& scaleX, float scaleY) const noexcept
{
    SDL_RenderGetScale(get(), &scaleX, &scaleY);
}

SDL2WRAP_INLINE EmptyResult Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) noexcept
{
    auto rc = SDL_SetRenderDrawColor(get(), r, g, b, a);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void Renderer::getDrawColor(Uint8& r, Uint8& g, Uint8& b, Uint8& a) const noexcept
{
    SDL_GetRenderDrawColor(get(), &r, &g, &b, &a);
}

SDL2WRAP_INLINE EmptyResult Renderer::setDrawBlendMode(BlendMode blendMode) noexcept
{
    auto rc = SDL_SetRenderDrawBlendMode(get(), static_cast<SDL_BlendMode>(blendMode));
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE sdl2wrap::Result<BlendMode> Renderer::getDrawBlendMode() const noexcept
{
    SDL_BlendMode sdlmode;
    auto rc = SDL_GetRenderDrawBlendMode(get(), &sdlmode);
    if (rc == 0) {
        auto mode = static_cast<BlendMode>(sdlmode);
        return sdl2wrap::Result<BlendMode>::success(move(mode));
    }

    return sdl2wrap::Result<BlendMode>::error(rc);
}

SDL2WRAP_INLINE EmptyResult Renderer::clear() noexcept
{
    auto rc = SDL_RenderClear(get());
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Renderer::drawPoint(int x, int y) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawPoint(get(), x, y));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawPoints(const Point* points, int count) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawPoints(get(), points, count));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawLine(int x1, int y1, int x2, int y2) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawLine(get(), x1, y1, x2, y2));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawLines(const Point* points, int count) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawLines(get(), points, count));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawRect(const Rect& rect) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawRect(get(), &rect));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawRects(const Rect* rects, int count) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawRects(get(), rects, count));
}

SDL2WRAP_INLINE EmptyResult Renderer::fillRect(const Rect& rect) noexcept
{
    return checkEmptyResultRc(SDL_RenderFillRect(get(), &rect));
}

SDL2WRAP_INLINE EmptyResult Renderer::fillRects(const Rect* rects, int count) noexcept
{
    return checkEmptyResultRc(SDL_RenderFillRects(get(), rects, count));
}

SDL2WRAP_INLINE EmptyResult Renderer::copy(Texture& tex, const Rect* srcRect, const Rect* dstRect) noexcept
{
    return checkEmptyResultRc(SDL_RenderCopy(get(), tex.get(), srcRect, dstRect));
}

SDL2WRAP_INLINE EmptyResult Renderer::copy(Texture& tex) noexcept
{
    return copy(tex, nullptr, nullptr);
}

SDL2WRAP_INLINE EmptyResult Renderer::copy(Texture& tex, const Rect& srcRect, const Rect& dstRect) noexcept
{
    return copy(tex, &srcRect, &dstRect);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyWithSrcRect(Texture& tex, const Rect& srcRect) noexcept
{
    return copy(tex, &srcRect, nullptr);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyWithDstRect(Texture& tex, const Rect& dstRect) noexcept
{
    return copy(tex, nullptr, &dstRect);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyEx(Texture& tex, const Rect* srcrect, const Rect* dstrect, double angle, Point center, RendererFlip flip) noexcept
{
    auto rc = SDL_RenderCopyEx(get(), tex.get(), srcrect, dstrect, angle, &center, static_cast<SDL_RendererFlip>(flip));
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyEx(Texture& tex, double angle, Point center, RendererFlip flip) noexcept
{
    return copyEx(tex, nullptr, nullptr, angle, center, flip);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyEx(Texture& tex, const Rect& srcrect, const Rect& dstrect, double angle, Point center, RendererFlip flip) noexcept
{
    return copyEx(tex, &srcrect, &dstrect, angle, center, flip);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyWithSrcRect(Texture& tex, const Rect& srcrect, double angle, Point center, RendererFlip flip) noexcept
{
    return copyEx(tex, &srcrect, nullptr, angle, center, flip);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyWithDstRect(Texture& tex, const Rect& dstrect, double angle, Point center, RendererFlip flip) noexcept
{
    return copyEx(tex, nullptr, &dstrect, angle, center, flip);
}

SDL2WRAP_INLINE EmptyResult Renderer::drawPointF(float x, float y) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawPointF(get(), x, y));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawPointsF(const FPoint* points, int count) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawPointsF(get(), points, count));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawLineF(float x1, float y1, float x2, float y2) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawLineF(get(), x1, y1, x2, y2));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawLinesF(const FPoint* points, int count) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawLinesF(get(), points, count));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawRectF(const FRect& rect) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawRectF(get(), &rect));
}

SDL2WRAP_INLINE EmptyResult Renderer::drawRectsF(const FRect* rects, int count) noexcept
{
    return checkEmptyResultRc(SDL_RenderDrawRectsF(get(), rects, count));
}

SDL2WRAP_INLINE EmptyResult Renderer::fillRectF(const FRect& rect) noexcept
{
    return checkEmptyResultRc(SDL_RenderFillRectF(get(), &rect));
}

SDL2WRAP_INLINE EmptyResult Renderer::fillRectsF(const FRect* rects, int count) noexcept
{
    return checkEmptyResultRc(SDL_RenderFillRectsF(get(), rects, count));
}

SDL2WRAP_INLINE EmptyResult Renderer::copyF(Texture& tex, const Rect* srcRect, const FRect* dstRect) noexcept
{
    return checkEmptyResultRc(SDL_RenderCopyF(get(), tex.get(), srcRect, dstRect));
}

SDL2WRAP_INLINE EmptyResult Renderer::copyF(Texture& tex) noexcept
{
    return copyF(tex, nullptr, nullptr);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyF(Texture& tex, const Rect& srcRect, const FRect& dstRect) noexcept
{
    return copyF(tex, &srcRect, &dstRect);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyWithSrcRectF(Texture& tex, const Rect& srcRect) noexcept
{
    return copyF(tex, &srcRect, nullptr);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyWithDstRectF(Texture& tex, const FRect& dstRect) noexcept
{
    return copyF(tex, nullptr, &dstRect);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyExF(Texture& tex, const Rect* srcrect, const FRect* dstrect, double angle, FPoint center, RendererFlip flip) noexcept
{
    auto rc = SDL_RenderCopyExF(get(), tex.get(), srcrect, dstrect, angle, &center, static_cast<SDL_RendererFlip>(flip));
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyExF(Texture& tex, double angle, FPoint center, RendererFlip flip) noexcept
{
    return copyExF(tex, nullptr, nullptr, angle, center, flip);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyExF(Texture& tex, const Rect& srcrect, const FRect& dstrect, double angle, FPoint center, RendererFlip flip) noexcept
{
    return copyExF(tex, &srcrect, &dstrect, angle, center, flip);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyWithSrcRectF(Texture& tex, const Rect& srcrect, double angle, FPoint center, RendererFlip flip) noexcept
{
    return copyExF(tex, &srcrect, nullptr, angle, center, flip);
}

SDL2WRAP_INLINE EmptyResult Renderer::copyWithDstRectF(Texture& tex, const FRect& dstrect, double angle, FPoint center, RendererFlip flip) noexcept
{
    return copyExF(tex, nullptr, &dstrect, angle, center, flip);
}

SDL2WRAP_INLINE void Renderer::present() noexcept
{
    SDL_RenderPresent(get());
}

SDL2WRAP_INLINE void Renderer::flush() noexcept
{
    SDL_RenderFlush(get());
}

namespace GL {

    SDL2WRAP_INLINE EmptyResult bindTexture(Texture& tex, float& w, float& h) noexcept
    {
        auto rc = SDL_GL_BindTexture(tex.get(), &w, &h);
        return checkEmptyResultRc(rc);
    }

    SDL2WRAP_INLINE EmptyResult unbindTexture(Texture& tex) noexcept
    {
        auto rc = SDL_GL_UnbindTexture(tex.get());
        return checkEmptyResultRc(rc);
    }

}; // namespace GL

namespace Metal {

    SDL2WRAP_INLINE void* renderGetMetalLayer(Renderer& renderer) noexcept
    {
        return SDL_RenderGetMetalLayer(renderer.get());
    }

    SDL2WRAP_INLINE void* renderGetMetalCommandEncoder(Renderer& renderer) noexcept
    {
        return SDL_RenderGetMetalCommandEncoder(renderer.get());
    }

}; // namespace Metal
}; // namespace Video

#endif //sdl2wrap_impl_render_h
