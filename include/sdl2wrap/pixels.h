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
     * \wrapImpl SDL_Palette Video::Palette
     */
    class Palette : public TypeWrapperWithPtrOp<Palette, SDL_Palette*, SDL_FreePalette> {
    public:
        using TypeWrapperWithPtrOp::TypeWrapperWithPtrOp;

        /**
         * \brief alloc a palette.
         * \param ncolors
         * \return
         * \wrapImpl SDL_AllocPalette Video::Palette::alloc
         */
        static Result alloc(int ncolors) noexcept;

        EmptyResult setColors(const Color* colors, int firstcolor, int ncolors) noexcept;
    };

    /**
     * \brief Wraps SDL_PixelFormat
     * \wrapImpl SDL_PixelFormat Video::PixelFormat
     */
    class PixelFormat : public TypeWrapperWithPtrOp<PixelFormat, SDL_PixelFormat*, SDL_FreeFormat> {
    public:
        /// default ctors
        using TypeWrapperWithPtrOp::TypeWrapperWithPtrOp;

        /**
         * \brief Create a PixelFormat from a PixelFormatEnum.
         * \param format
         * \return
         * \wrapImpl SDL_AllocFormat Video::PixelFormat::allocalloc
         */
        static Result alloc(PixelFormatEnum format) noexcept;

        /**
         * \brief Return the printable name of this format.
         * \return
         * \wrapImpl SDL_GetPixelFormatName Video::PixelFormat::getName
         */
        const char* getName() const noexcept;

        /**
         * \brief Sets the palette of this Format
         * \return
         * \wrapImpl SDL_SetPixelFormatPalette Video::PixelFormat::setPalette
         */
        EmptyResult setPalette(Palette& palette) noexcept;

        /**
         * \brief Maps an RGB triple to an opaque pixel value for a given pixel format.
         * \param r
         * \param g
         * \param b
         * \return
         * \wrapImpl SDL_MapRGB Video::PixelFormat::mapRGB
         */
        Uint32 mapRGB(Uint8 r, Uint8 g, Uint8 b) const noexcept;

        /**
         * \brief Maps an RGB triple to an opaque pixel value for a given pixel format.
         * \param color
         * \return
         * \wrapImpl SDL_MapRGB Video::PixelFormat::mapRGB
         */
        Uint32 mapRGB(const Color& color) const noexcept;

        /**
         * \brief Maps an RGBA quadruple to a pixel value for a given pixel format.
         * \param r
         * \param g
         * \param b
         * \param a
         * \return
         * \wrapImpl SDL_MapRGB Video::PixelFormat::mapRGBA
         */
        Uint32 mapRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const noexcept;

        /**
         * \brief Maps an RGBA quadruple to a pixel value for a given pixel format.
         * \param collr
         * \return
         * \wrapImpl SDL_MapRGB Video::PixelFormat::mapRGBA
         */
        Uint32 mapRGBA(const Color& collr) const noexcept;

        /**
         * \brief Get the RGB components from a pixel of the specified format.
         * \param pixel
         * \param r
         * \param g
         * \param b
         * \wrapImpl SDL_GetRGB Video::PixelFormat::getRGB
         */
        void getRGB(Uint32 pixel, Uint8& r, Uint8& g, Uint8& b) const noexcept;

        /**
         * \brief Get the RGB components from a pixel of the specified format.
         * \param pixel
         * \return
         * \wrapImpl SDL_GetRGB Video::PixelFormat::getRGB
         */
        Color getRGB(Uint32 pixel) const noexcept;

        /**
         * \brief Get the RGBA components from a pixel of the specified format.
         * \param pixel
         * \param r
         * \param g
         * \param b
         * \param a
         * \wrapImpl SDL_GetRGBA Video::PixelFormat::getRGBA
         */
        void getRGBA(Uint32 pixel, Uint8& r, Uint8& g, Uint8& b, Uint8& a) const noexcept;

        /**
         * \brief Get the RGBA components from a pixel of the specified format.
         * \param pixel
         * \return
         * \wrapImpl SDL_GetRGBA Video::PixelFormat::getRGBA
         */
        Color getRGBA(Uint32 pixel) const noexcept;

        /**
         * \brief Return the printable name for a enum format.
         * \param format
         * \return
         * \wrapImpl SDL_GetPixelFormatName Video::PixelFormat::getName
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
         * \wrapImpl SDL_GetPixelFormatName Video::PixelFormat::enumToMask
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
         * \wrapImpl SDL_AllocFormat Video::PixelFormat::maskToEnum
         */
        static PixelFormatEnum maskToEnum(int bpp, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) noexcept;
    };

    /**
     * \brief Calculate a 256 entry gamma ramp for a gamma value.
     * \param gamma
     * \param ramp
     * \wrapImpl SDL_CalculateGammaRamp Video::calculateGammaRamp
     */
    void calculateGammaRamp(float gamma, Uint16* ramp) noexcept;

}; // namespace Video
}; // namespace sdl2wrap

#endif //sdl2wrap_pixels_h
