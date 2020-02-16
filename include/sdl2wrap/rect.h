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
 * \file rect.h
 * Wrappers for SDL_Rect and SDL_FRect
 */

#ifndef sdl2wrap_rect_h
#define sdl2wrap_rect_h

// always first!
#include "detail/base.h"

namespace sdl2wrap {
using Point = SDL_Point;
using FPoint = SDL_FPoint;

// forward decl
struct FRect;

/**
     * \brief Equivalent of SDL_Rect. Also wraps all prominent SDL_Rect functions
     */
struct Rect {
    /// default ctor
    Rect() = default;
    /// ctor for the case we acre created from an SDL_Rect
    explicit Rect(const SDL_Rect& r) noexcept;

    /**
         * \brief Convert this to an FRect
         * \return
         */
    FRect toFRect() const noexcept;

    /**
         * \brief Convert this to a
         * \return
         * \sa SDL_Rect
         */
    SDL_Rect toSDLRect() const noexcept;

    /**
         * \brief Check if point is in this rect.
         * \param point
         * \return
         * \sa SDL_PointInRect
         */
    bool pointInRect(const Point& point) const noexcept;

    /**
         * \brief Check if this rect is empty.
         * \return
         * \sa SDL_RectEmpty
         */
    bool empty() const noexcept;

    /**
         * \brief Check equality of two rects.
         * \param other
         * \return
         * \sa SDL_RectEquals
         */
    bool equals(const Rect& other) const noexcept;
    /**
         * \brief same as calling equals()
         * \param other
         * \return
         * \sa SDL_HasIntersection
         */
    bool operator==(const Rect& other) const noexcept;

    /**
         * \brief Checks if this rect intersects with another.
         * \param other
         * \return
         * \sa SDL_HasIntersection
         */
    bool hasIntersection(const Rect& other) const noexcept;

    /**
         * \brief Calculate the intersection of two rectangles.
         * \param other Rect to intersect with
         * \param result result of SDL_IntersectRect goes here
         * \return
         * \sa SDL_IntersectRect
         */
    bool intersectRect(const Rect& other, Rect& result) const noexcept;

    /**
         * \brief Calculate the union of two rectangles.
         * \param other Rect to calculate union with
         * \param result result of SDL_UnionRect goes here
         * \sa SDL_UnionRect
         */
    void unionRect(const Rect& other, Rect& result) const noexcept;

    /**
         * \brief Calculate the intersection of a rectangle and line segment.
         * \param x1
         * \param y1
         * \param x2
         * \param y2
         * \return
         * \sa SDL_IntersectRectAndLine
         */
    bool intersectRectAndLine(int& x1, int& y1, int& x2, int& y2) const noexcept;

    /**
         * \brief Calculate a minimal rectangle enclosing a set of points.
         * \param points
         * \param count
         * \param clip
         * \param result
         * \return
         * \sa SDL_EnclosePoints
         */
    static bool enclosePoints(Point points[], int count, const Rect& clip, Rect& result); // NOLINT

    /// rect members
    int x, y, w, h;
};

/**
     * \brief Equivalent of SDL_FRect
     */
struct FRect {
    /// default ctor
    FRect() = default;

    /// ctor in case we want to convert from SDL_FRect
    explicit FRect(const SDL_FRect& r) noexcept;

    /**
         * \brief Convert to Rect
         * \return
         */
    Rect toRect() const noexcept;

    /**
         * \brief Convert to SDL_FRect
         * \return
         */
    SDL_FRect toSDLRect() const noexcept;

    /// rect members
    float x, y, w, h;
};

#ifdef SDL2WRAP_DEFINITIONS
SDL2WRAP_INLINE Rect::Rect(const SDL_Rect& r) noexcept
    : x(r.x)
    , y(r.y)
    , w(r.w)
    , h(r.h)
{
}

SDL2WRAP_INLINE FRect Rect::toFRect() const noexcept
{
    FRect result {};
    result.x = static_cast<float>(x);
    result.y = static_cast<float>(y);
    result.w = static_cast<float>(w);
    result.h = static_cast<float>(h);
    return result;
}

SDL2WRAP_INLINE SDL_Rect Rect::toSDLRect() const noexcept
{
    return SDL_Rect { x, y, w, h };
}

SDL2WRAP_INLINE bool Rect::pointInRect(const Point& point) const noexcept
{
    auto sdlr = toSDLRect();
    return SDL_PointInRect(&point, &sdlr) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::empty() const noexcept
{
    auto sdlr = toSDLRect();
    return SDL_RectEmpty(&sdlr) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::equals(const Rect& other) const noexcept
{
    auto a = toSDLRect();
    auto b = other.toSDLRect();
    return SDL_RectEquals(&a, &b) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::operator==(const Rect& other) const noexcept
{
    return equals(other);
}

SDL2WRAP_INLINE bool Rect::hasIntersection(const Rect& other) const noexcept
{
    auto a = toSDLRect();
    auto b = other.toSDLRect();
    return SDL_HasIntersection(&a, &b) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::intersectRect(const Rect& other, Rect& result) const noexcept
{
    auto a = toSDLRect();
    auto b = other.toSDLRect();
    SDL_Rect sdlres {};
    bool bResult = SDL_IntersectRect(&a, &b, &sdlres) == SDL_TRUE;
    result = Rect(sdlres);
    return bResult;
}

SDL2WRAP_INLINE void Rect::unionRect(const Rect& other, Rect& result) const noexcept
{
    auto a = toSDLRect();
    auto b = other.toSDLRect();
    SDL_Rect sdlres {};
    SDL_UnionRect(&a, &b, &sdlres);
    result = Rect(sdlres);
}

SDL2WRAP_INLINE bool Rect::intersectRectAndLine(int& x1, int& y1, int& x2, int& y2) const noexcept
{
    auto a = toSDLRect();
    return SDL_IntersectRectAndLine(&a, &x1, &y1, &x2, &y2) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Rect::enclosePoints(Point points[], int count, const Rect& clip, Rect& result) // NOLINT
{
    auto sdlclip = clip.toSDLRect();
    SDL_Rect sdlres {};
    auto bResult = SDL_EnclosePoints(points, count, &sdlclip, &sdlres) == SDL_TRUE; // NOLINT
    result = Rect(sdlres);
    return bResult;
}

SDL2WRAP_INLINE FRect::FRect(const SDL_FRect& r) noexcept
    : x(r.x)
    , y(r.y)
    , w(r.w)
    , h(r.h)
{
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

SDL2WRAP_INLINE SDL_FRect FRect::toSDLRect() const noexcept
{
    return SDL_FRect { x, y, w, h };
}

#endif // SDL2WRAP_DEFINITIONS

}; // sdl2wrap

#endif //sdl2wrap_rect_h
