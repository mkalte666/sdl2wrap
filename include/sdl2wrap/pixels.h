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
#include "detail/base.h"
#include "detail/generated/generated_sdl_pixels.h"
#include "detail/typewrapper.h"

namespace sdl2wrap {

namespace Video {
    /// short for SDL_Color
    using Color = SDL_Color;
    /// short for the brits
    using Colour = Color;

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

    using Palette = SDL_Palette;

}; // namespace Video

#ifdef SDL2WRAP_DEFINITIONS

SDL2WRAP_INLINE Video::PixelFormat::Result Video::PixelFormat::alloc(PixelFormatEnum format) noexcept
{
    auto ptr = SDL_AllocFormat(static_cast<Uint32>(format));
    if (ptr == nullptr) {
        return Result::error(0);
    }

    return Result::success(PixelFormat(ptr));
}

SDL2WRAP_INLINE const char* Video::PixelFormat::getName() const noexcept
{
    return getName(static_cast<PixelFormatEnum>(get()->format));
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

#endif // SDL2WRAP_DEFINITIONS

}; // namespace sdl2wrap

#endif //sdl2wrap_pixels_h
