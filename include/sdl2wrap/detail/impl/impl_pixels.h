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

SDL2WRAP_INLINE Palette::Result Palette::alloc(int ncolors) noexcept
{
    auto ptr = SDL_AllocPalette(ncolors);
    if (ptr == nullptr) {
        return Result::error(0);
    }

    return Result::success(Palette(ptr));
}

SDL2WRAP_INLINE EmptyResult Palette::setColors(const Color* colors, int firstcolor, int ncolors) noexcept
{
    auto rc = SDL_SetPaletteColors(get(), colors, firstcolor, ncolors);
    if (rc != 0) {
        return EmptyResult::error(rc);
    }

    return EmptyResult::success(true);
}

SDL2WRAP_INLINE PixelFormat::Result PixelFormat::alloc(PixelFormatEnum format) noexcept
{
    auto ptr = SDL_AllocFormat(static_cast<Uint32>(format));
    if (ptr == nullptr) {
        return Result::error(0);
    }

    return Result::success(PixelFormat(ptr));
}

SDL2WRAP_INLINE Uint32 PixelFormat::mapRGB(Uint8 r, Uint8 g, Uint8 b) const noexcept
{
    return SDL_MapRGB(get(), r, g, b);
}

SDL2WRAP_INLINE Uint32 PixelFormat::mapRGB(const Color& color) const noexcept
{
    return mapRGB(color.r, color.g, color.b);
}

SDL2WRAP_INLINE Uint32 PixelFormat::mapRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const noexcept
{
    return SDL_MapRGBA(get(), r, g, b, a);
}

SDL2WRAP_INLINE Uint32 PixelFormat::mapRGBA(const Color& collr) const noexcept
{
    return mapRGBA(collr.r, collr.g, collr.b, collr.a);
}

SDL2WRAP_INLINE void PixelFormat::getRGB(Uint32 pixel, Uint8& r, Uint8& g, Uint8& b) const noexcept
{
    SDL_GetRGB(pixel, get(), &r, &g, &b);
}

SDL2WRAP_INLINE Color PixelFormat::getRGB(Uint32 pixel) const noexcept
{
    Color c {};
    getRGB(pixel, c.r, c.g, c.b);
    return c;
}

SDL2WRAP_INLINE void PixelFormat::getRGBA(Uint32 pixel, Uint8& r, Uint8& g, Uint8& b, Uint8& a) const noexcept
{
    SDL_GetRGBA(pixel, get(), &r, &g, &b, &a);
}

SDL2WRAP_INLINE Color PixelFormat::getRGBA(Uint32 pixel) const noexcept
{
    Color c {};
    getRGBA(pixel, c.r, c.g, c.b, c.a);
    return c;
}

SDL2WRAP_INLINE const char* PixelFormat::getName() const noexcept
{
    return getName(static_cast<PixelFormatEnum>(get()->format));
}

SDL2WRAP_INLINE EmptyResult PixelFormat::setPalette(Palette& palette) noexcept
{
    auto rc = SDL_SetPixelFormatPalette(get(), palette.get());
    if (rc != 0) {
        return EmptyResult::error(rc);
    }

    return EmptyResult::success(true);
}

SDL2WRAP_INLINE const char* PixelFormat::getName(PixelFormatEnum format) noexcept
{
    return SDL_GetPixelFormatName(static_cast<Uint32>(format));
}

SDL2WRAP_INLINE bool PixelFormat::enumToMask(PixelFormatEnum format, int& bpp, Uint32& Rmask, Uint32& Gmask, Uint32& Bmask, Uint32& Amask) noexcept
{
    return SDL_PixelFormatEnumToMasks(static_cast<Uint32>(format), &bpp, &Rmask, &Gmask, &Bmask, &Amask) == SDL_TRUE;
}

SDL2WRAP_INLINE PixelFormatEnum PixelFormat::maskToEnum(int bpp, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept
{
    Uint32 result = SDL_MasksToPixelFormatEnum(bpp, Rmask, Gmask, Bmask, Amask);
    return static_cast<PixelFormatEnum>(result);
}

SDL2WRAP_INLINE void calculateGammaRamp(float gamma, Uint16* ramp) noexcept
{
    SDL_CalculateGammaRamp(gamma, ramp);
}

}; // namespace Video