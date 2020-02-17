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

#ifndef sdl2wrap_pixels_h
#define sdl2wrap_pixels_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on
#include "detail/generated/generated_sdl_pixels.h"
#include "detail/typewrapper.h"

namespace sdl2wrap {

namespace Video {
    /// short for SDL_Color
    using Color = SDL_Color;
    /// short for the brits
    using Colour = Color;

    /**
     * \brief Wraps SDL_Palette
     * \sa SDL_Palette
     */
    class Palette : public TypeWrapperWithPtrOp<Palette, SDL_Palette*, SDL_FreePalette> {
    public:
        using TypeWrapperWithPtrOp::TypeWrapperWithPtrOp;

        /**
         * \brief alloc a palette.
         * \param ncolors
         * \return
         * \sa SDL_AllocPalette
         */
        static Result alloc(int ncolors) noexcept;

        EmptyResult setColors(const Color* colors, int firstcolor, int ncolors) noexcept;
    };

    /**
     * \brief Wraps SDL_PixelFormat
     * \sa SDL_AllocFormat
     */
    class PixelFormat : public TypeWrapperWithPtrOp<PixelFormat, SDL_PixelFormat*, SDL_FreeFormat> {
    public:
        /// default ctors
        using TypeWrapperWithPtrOp::TypeWrapperWithPtrOp;

        /**
         * \brief Create a PixelFormat from a PixelFormatEnum.
         * \param format
         * \return
         * \sa SDL_AllocFormat
         */
        static Result alloc(PixelFormatEnum format) noexcept;

        /**
         * \brief Return the printable name of this format.
         * \return
         * \sa SDL_GetPixelFormatName
         */
        const char* getName() const noexcept;

        /**
         * \brief Sets the palette of this Format
         * \return
         * \sa SDL_SetPixelFormatPalette
         */
        EmptyResult setPalette(Palette& palette) noexcept;

        /**
         * \brief Maps an RGB triple to an opaque pixel value for a given pixel format.
         * \param r
         * \param g
         * \param b
         * \return
         * \sa SDL_MapRGB
         */
        Uint32 mapRGB(Uint8 r, Uint8 g, Uint8 b) const noexcept;

        /**
         * \brief Maps an RGB triple to an opaque pixel value for a given pixel format.
         * \param color
         * \return
         * \sa SDL_MapRGB
         */
        Uint32 mapRGB(const Color& color) const noexcept;

        /**
         * \brief Maps an RGBA quadruple to a pixel value for a given pixel format.
         * \param r
         * \param g
         * \param b
         * \param a
         * \return
         * \sa SDL_MapRGB
         */
        Uint32 mapRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const noexcept;

        /**
         * \brief Maps an RGBA quadruple to a pixel value for a given pixel format.
         * \param collr
         * \return
         * \sa SDL_MapRGB
         */
        Uint32 mapRGBA(const Color& collr) const noexcept;

        /**
         * \brief Get the RGB components from a pixel of the specified format.
         * \param pixel
         * \param r
         * \param g
         * \param b
         * \sa SDL_GetRGB
         */
        void getRGB(Uint32 pixel, Uint8& r, Uint8& g, Uint8& b) const noexcept;

        /**
         * \brief Get the RGB components from a pixel of the specified format.
         * \param pixel
         * \return
         * \sa SDL_GetRGB
         */
        Color getRGB(Uint32 pixel) const noexcept;

        /**
         * \brief Get the RGBA components from a pixel of the specified format.
         * \param pixel
         * \param r
         * \param g
         * \param b
         * \param a
         * \sa SDL_GetRGBA
         */
        void getRGBA(Uint32 pixel, Uint8& r, Uint8& g, Uint8& b, Uint8& a) const noexcept;

        /**
         * \brief Get the RGBA components from a pixel of the specified format.
         * \param pixel
         * \return
         * \sa SDL_GetRGBA
         */
        Color getRGBA(Uint32 pixel) const noexcept;

        /**
         * \brief Return the printable name for a enum format.
         * \param format
         * \return
         * \sa SDL_GetPixelFormatName
         */
        static const char* getName(PixelFormatEnum format) noexcept;

        /**
         * \brief Convert a enum to a pixel bitmask
         * \param format
         * \param bpp
         * \param Rmask
         * \param Gmask
         * \param Bmask
         * \param Amask
         * \return true, or false if conversion is not possible
         * \sa SDL_GetPixelFormatName
         */
        static bool enumToMask(PixelFormatEnum format, int& bpp, Uint32& Rmask, Uint32& Gmask, Uint32& Bmask, Uint32& Amask) noexcept;

        /**
         * \brief Convert a mask to a pixel format enum.
         * \param bpp
         * \param Rmask
         * \param Gmask
         * \param Bmask
         * \param Amask
         * \return
         * \sa SDL_AllocFormat
         */
        static PixelFormatEnum maskToEnum(int bpp, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept;
    };

    /**
     * \brief Calculate a 256 entry gamma ramp for a gamma value.
     * \param gamma
     * \param ramp
     * \sa SDL_CalculateGammaRamp
     */
    void calculateGammaRamp(float gamma, Uint16* ramp) noexcept;

}; // namespace Video

#ifdef SDL2WRAP_DEFINITIONS

SDL2WRAP_INLINE Video::Palette::Result Video::Palette::alloc(int ncolors) noexcept
{
    auto ptr = SDL_AllocPalette(ncolors);
    if (ptr == nullptr) {
        return Result::error(0);
    }

    return Result::success(Palette(ptr));
}

SDL2WRAP_INLINE EmptyResult Video::Palette::setColors(const Color* colors, int firstcolor, int ncolors) noexcept
{
    auto rc = SDL_SetPaletteColors(get(), colors, firstcolor, ncolors);
    if (rc != 0) {
        return EmptyResult::error(rc);
    }

    return EmptyResult::success(true);
}

SDL2WRAP_INLINE Video::PixelFormat::Result Video::PixelFormat::alloc(PixelFormatEnum format) noexcept
{
    auto ptr = SDL_AllocFormat(static_cast<Uint32>(format));
    if (ptr == nullptr) {
        return Result::error(0);
    }

    return Result::success(PixelFormat(ptr));
}

SDL2WRAP_INLINE Uint32 Video::PixelFormat::mapRGB(Uint8 r, Uint8 g, Uint8 b) const noexcept
{
    return SDL_MapRGB(get(), r, g, b);
}

SDL2WRAP_INLINE Uint32 Video::PixelFormat::mapRGB(const Color& color) const noexcept
{
    return mapRGB(color.r, color.g, color.b);
}

SDL2WRAP_INLINE Uint32 Video::PixelFormat::mapRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const noexcept
{
    return SDL_MapRGBA(get(), r, g, b, a);
}

SDL2WRAP_INLINE Uint32 Video::PixelFormat::mapRGBA(const Color& collr) const noexcept
{
    return mapRGBA(collr.r, collr.g, collr.b, collr.a);
}

SDL2WRAP_INLINE void Video::PixelFormat::getRGB(Uint32 pixel, Uint8& r, Uint8& g, Uint8& b) const noexcept
{
    SDL_GetRGB(pixel, get(), &r, &g, &b);
}

SDL2WRAP_INLINE Video::Color Video::PixelFormat::getRGB(Uint32 pixel) const noexcept
{
    Color c {};
    getRGB(pixel, c.r, c.g, c.b);
    return c;
}

SDL2WRAP_INLINE void Video::PixelFormat::getRGBA(Uint32 pixel, Uint8& r, Uint8& g, Uint8& b, Uint8& a) const noexcept
{
    SDL_GetRGBA(pixel, get(), &r, &g, &b, &a);
}

SDL2WRAP_INLINE Video::Color Video::PixelFormat::getRGBA(Uint32 pixel) const noexcept
{
    Color c {};
    getRGBA(pixel, c.r, c.g, c.b, c.a);
    return c;
}

SDL2WRAP_INLINE const char* Video::PixelFormat::getName() const noexcept
{
    return getName(static_cast<PixelFormatEnum>(get()->format));
}

SDL2WRAP_INLINE EmptyResult Video::PixelFormat::setPalette(Palette& palette) noexcept
{
    auto rc = SDL_SetPixelFormatPalette(get(), palette.get());
    if (rc != 0) {
        return EmptyResult::error(rc);
    }

    return EmptyResult::success(true);
}

SDL2WRAP_INLINE const char* Video::PixelFormat::getName(PixelFormatEnum format) noexcept
{
    return SDL_GetPixelFormatName(static_cast<Uint32>(format));
}

SDL2WRAP_INLINE bool Video::PixelFormat::enumToMask(PixelFormatEnum format, int& bpp, Uint32& Rmask, Uint32& Gmask, Uint32& Bmask, Uint32& Amask) noexcept
{
    return SDL_PixelFormatEnumToMasks(static_cast<Uint32>(format), &bpp, &Rmask, &Gmask, &Bmask, &Amask) == SDL_TRUE;
}

SDL2WRAP_INLINE PixelFormatEnum Video::PixelFormat::maskToEnum(int bpp, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept
{
    Uint32 result = SDL_MasksToPixelFormatEnum(bpp, Rmask, Gmask, Bmask, Amask);
    return static_cast<PixelFormatEnum>(result);
}

SDL2WRAP_INLINE void Video::calculateGammaRamp(float gamma, Uint16* ramp) noexcept
{
    SDL_CalculateGammaRamp(gamma, ramp);
}

#endif // SDL2WRAP_DEFINITIONS

}; // namespace sdl2wrap

#endif //sdl2wrap_pixels_h
