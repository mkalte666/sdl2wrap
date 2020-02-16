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
/**
 * Everything in this file is generated. Please use scripts/generate.py to update it! 
 */
#ifndef sdl2wrap_generated_SDL_pixels
#define sdl2wrap_generated_SDL_pixels

#include "SDL_pixels.h"

namespace sdl2wrap {

/**
 * \brief Scoped version of SDL_PixelType
 * 
 * Generated From SDL_pixels.h:65
 */
enum class PixelType : Uint32 {
    Unknown = SDL_PIXELTYPE_UNKNOWN,
    Index1 = SDL_PIXELTYPE_INDEX1,
    Index4 = SDL_PIXELTYPE_INDEX4,
    Index8 = SDL_PIXELTYPE_INDEX8,
    Packed8 = SDL_PIXELTYPE_PACKED8,
    Packed16 = SDL_PIXELTYPE_PACKED16,
    Packed32 = SDL_PIXELTYPE_PACKED32,
    Arrayu8 = SDL_PIXELTYPE_ARRAYU8,
    Arrayu16 = SDL_PIXELTYPE_ARRAYU16,
    Arrayu32 = SDL_PIXELTYPE_ARRAYU32,
    Arrayf16 = SDL_PIXELTYPE_ARRAYF16,
    Arrayf32 = SDL_PIXELTYPE_ARRAYF32,
};

/**
 * \brief Scoped version of SDL_BitmapOrder
 * 
 * Generated From SDL_pixels.h:73
 */
enum class BitmapOrder : Uint32 {
    None = SDL_BITMAPORDER_NONE,
    Bitmaporder4321 = SDL_BITMAPORDER_4321,
    Bitmaporder1234 = SDL_BITMAPORDER_1234,
};

/**
 * \brief Scoped version of SDL_PackedOrder
 * 
 * Generated From SDL_pixels.h:87
 */
enum class PackedOrder : Uint32 {
    None = SDL_PACKEDORDER_NONE,
    Xrgb = SDL_PACKEDORDER_XRGB,
    Rgbx = SDL_PACKEDORDER_RGBX,
    Argb = SDL_PACKEDORDER_ARGB,
    Rgba = SDL_PACKEDORDER_RGBA,
    Xbgr = SDL_PACKEDORDER_XBGR,
    Bgrx = SDL_PACKEDORDER_BGRX,
    Abgr = SDL_PACKEDORDER_ABGR,
    Bgra = SDL_PACKEDORDER_BGRA,
};

/**
 * \brief Scoped version of SDL_ArrayOrder
 * 
 * Generated From SDL_pixels.h:101
 */
enum class ArrayOrder : Uint32 {
    None = SDL_ARRAYORDER_NONE,
    Rgb = SDL_ARRAYORDER_RGB,
    Rgba = SDL_ARRAYORDER_RGBA,
    Argb = SDL_ARRAYORDER_ARGB,
    Bgr = SDL_ARRAYORDER_BGR,
    Bgra = SDL_ARRAYORDER_BGRA,
    Abgr = SDL_ARRAYORDER_ABGR,
};

/**
 * \brief Scoped version of SDL_PackedLayout
 * 
 * Generated From SDL_pixels.h:115
 */
enum class PackedLayout : Uint32 {
    None = SDL_PACKEDLAYOUT_NONE,
    Packedlayout332 = SDL_PACKEDLAYOUT_332,
    Packedlayout4444 = SDL_PACKEDLAYOUT_4444,
    Packedlayout1555 = SDL_PACKEDLAYOUT_1555,
    Packedlayout5551 = SDL_PACKEDLAYOUT_5551,
    Packedlayout565 = SDL_PACKEDLAYOUT_565,
    Packedlayout8888 = SDL_PACKEDLAYOUT_8888,
    Packedlayout2101010 = SDL_PACKEDLAYOUT_2101010,
    Packedlayout1010102 = SDL_PACKEDLAYOUT_1010102,
};

/**
 * \brief Scoped version of SDL_PixelFormatEnum
 * 
 * Generated From SDL_pixels.h:296
 */
enum class PixelFormatEnum : Uint32 {
    Unknown = SDL_PIXELFORMAT_UNKNOWN,
    Index1lsb = SDL_PIXELFORMAT_INDEX1LSB,
    Index1msb = SDL_PIXELFORMAT_INDEX1MSB,
    Index4lsb = SDL_PIXELFORMAT_INDEX4LSB,
    Index4msb = SDL_PIXELFORMAT_INDEX4MSB,
    Index8 = SDL_PIXELFORMAT_INDEX8,
    Rgb332 = SDL_PIXELFORMAT_RGB332,
    Rgb444 = SDL_PIXELFORMAT_RGB444,
    Bgr444 = SDL_PIXELFORMAT_BGR444,
    Rgb555 = SDL_PIXELFORMAT_RGB555,
    Bgr555 = SDL_PIXELFORMAT_BGR555,
    Argb4444 = SDL_PIXELFORMAT_ARGB4444,
    Rgba4444 = SDL_PIXELFORMAT_RGBA4444,
    Abgr4444 = SDL_PIXELFORMAT_ABGR4444,
    Bgra4444 = SDL_PIXELFORMAT_BGRA4444,
    Argb1555 = SDL_PIXELFORMAT_ARGB1555,
    Rgba5551 = SDL_PIXELFORMAT_RGBA5551,
    Abgr1555 = SDL_PIXELFORMAT_ABGR1555,
    Bgra5551 = SDL_PIXELFORMAT_BGRA5551,
    Rgb565 = SDL_PIXELFORMAT_RGB565,
    Bgr565 = SDL_PIXELFORMAT_BGR565,
    Rgb24 = SDL_PIXELFORMAT_RGB24,
    Bgr24 = SDL_PIXELFORMAT_BGR24,
    Rgb888 = SDL_PIXELFORMAT_RGB888,
    Rgbx8888 = SDL_PIXELFORMAT_RGBX8888,
    Bgr888 = SDL_PIXELFORMAT_BGR888,
    Bgrx8888 = SDL_PIXELFORMAT_BGRX8888,
    Argb8888 = SDL_PIXELFORMAT_ARGB8888,
    Rgba8888 = SDL_PIXELFORMAT_RGBA8888,
    Abgr8888 = SDL_PIXELFORMAT_ABGR8888,
    Bgra8888 = SDL_PIXELFORMAT_BGRA8888,
    Argb2101010 = SDL_PIXELFORMAT_ARGB2101010,
    Rgba32 = SDL_PIXELFORMAT_RGBA32,
    Argb32 = SDL_PIXELFORMAT_ARGB32,
    Bgra32 = SDL_PIXELFORMAT_BGRA32,
    Abgr32 = SDL_PIXELFORMAT_ABGR32,
    Yv12 = SDL_PIXELFORMAT_YV12,
    Iyuv = SDL_PIXELFORMAT_IYUV,
    Yuy2 = SDL_PIXELFORMAT_YUY2,
    Uyvy = SDL_PIXELFORMAT_UYVY,
    Yvyu = SDL_PIXELFORMAT_YVYU,
    Nv12 = SDL_PIXELFORMAT_NV12,
    Nv21 = SDL_PIXELFORMAT_NV21,
    ExternalOes = SDL_PIXELFORMAT_EXTERNAL_OES,
};

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
