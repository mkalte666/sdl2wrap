
#include <sdl2wrap/rect.h>

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

SDL2WRAP_INLINE FRect Rect::toFRect() const noexcept
{
    FRect result {};
    result.x = static_cast<float>(x);
    result.y = static_cast<float>(y);
    result.w = static_cast<float>(w);
    result.h = static_cast<float>(h);
    return result;
}

SDL2WRAP_INLINE bool Rect::pointInRect(const Point& point) const noexcept
{
    return SDL_PointInRect(&point, this) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::empty() const noexcept
{
    return SDL_RectEmpty(this) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::equals(const Rect& other) const noexcept
{
    return SDL_RectEquals(this, &other) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::operator==(const Rect& other) const noexcept
{
    return equals(other);
}

SDL2WRAP_INLINE bool Rect::hasIntersection(const Rect& other) const noexcept
{
    return SDL_HasIntersection(this, &other) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::intersectRect(const Rect& other, Rect& result) const noexcept
{
    return SDL_IntersectRect(this, &other, &result) == SDL_TRUE;
}

SDL2WRAP_INLINE void Rect::unionRect(const Rect& other, Rect& result) const noexcept
{
    SDL_UnionRect(this, &other, &result);
}

SDL2WRAP_INLINE bool Rect::intersectRectAndLine(int& x1, int& y1, int& x2, int& y2) const noexcept
{
    return SDL_IntersectRectAndLine(this, &x1, &y1, &x2, &y2) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::enclosePoints(Point points[], int count, const Rect& clip, Rect& result) // NOLINT
{
    return SDL_EnclosePoints(points, count, &clip, &result) == SDL_TRUE; // NOLINT
}

SDL2WRAP_INLINE Rect FRect::toRect() const noexcept
{
    Rect result {};
    result.x = static_cast<int>(x);
    result.y = static_cast<int>(y);
    result.w = static_cast<int>(w);
    result.h = static_cast<int>(h);
    return result;
}

}; //namespace Video