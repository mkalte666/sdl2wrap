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

SDL2WRAP_INLINE Video::Rect::Rect(const SDL_Rect& r) noexcept
    : x(r.x)
    , y(r.y)
    , w(r.w)
    , h(r.h)
{
}

SDL2WRAP_INLINE Video::FRect Video::Rect::toFRect() const noexcept
{
    FRect result {};
    result.x = static_cast<float>(x);
    result.y = static_cast<float>(y);
    result.w = static_cast<float>(w);
    result.h = static_cast<float>(h);
    return result;
}

SDL2WRAP_INLINE SDL_Rect Video::Rect::toSDLRect() const noexcept
{
    return SDL_Rect { x, y, w, h };
}

SDL2WRAP_INLINE bool Video::Rect::pointInRect(const Point& point) const noexcept
{
    auto sdlr = toSDLRect();
    return SDL_PointInRect(&point, &sdlr) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Video::Rect::empty() const noexcept
{
    auto sdlr = toSDLRect();
    return SDL_RectEmpty(&sdlr) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Video::Rect::equals(const Rect& other) const noexcept
{
    auto a = toSDLRect();
    auto b = other.toSDLRect();
    return SDL_RectEquals(&a, &b) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Video::Rect::operator==(const Rect& other) const noexcept
{
    return equals(other);
}

SDL2WRAP_INLINE bool Video::Rect::hasIntersection(const Rect& other) const noexcept
{
    auto a = toSDLRect();
    auto b = other.toSDLRect();
    return SDL_HasIntersection(&a, &b) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Video::Rect::intersectRect(const Rect& other, Rect& result) const noexcept
{
    auto a = toSDLRect();
    auto b = other.toSDLRect();
    SDL_Rect sdlres {};
    bool bResult = SDL_IntersectRect(&a, &b, &sdlres) == SDL_TRUE;
    result = Rect(sdlres);
    return bResult;
}

SDL2WRAP_INLINE void Video::Rect::unionRect(const Rect& other, Rect& result) const noexcept
{
    auto a = toSDLRect();
    auto b = other.toSDLRect();
    SDL_Rect sdlres {};
    SDL_UnionRect(&a, &b, &sdlres);
    result = Rect(sdlres);
}

SDL2WRAP_INLINE bool Video::Rect::intersectRectAndLine(int& x1, int& y1, int& x2, int& y2) const noexcept
{
    auto a = toSDLRect();
    return SDL_IntersectRectAndLine(&a, &x1, &y1, &x2, &y2) == SDL_TRUE;
}

SDL2WRAP_INLINE bool Video::Rect::enclosePoints(Point points[], int count, const Rect& clip, Rect& result) // NOLINT
{
    auto sdlclip = clip.toSDLRect();
    SDL_Rect sdlres {};
    auto bResult = SDL_EnclosePoints(points, count, &sdlclip, &sdlres) == SDL_TRUE; // NOLINT
    result = Rect(sdlres);
    return bResult;
}

SDL2WRAP_INLINE Video::FRect::FRect(const SDL_FRect& r) noexcept
    : x(r.x)
    , y(r.y)
    , w(r.w)
    , h(r.h)
{
}

SDL2WRAP_INLINE Video::Rect Video::FRect::toRect() const noexcept
{
    Rect result {};
    result.x = static_cast<int>(x);
    result.y = static_cast<int>(y);
    result.w = static_cast<int>(w);
    result.h = static_cast<int>(h);
    return result;
}

SDL2WRAP_INLINE SDL_FRect Video::FRect::toSDLRect() const noexcept
{
    return SDL_FRect { x, y, w, h };
}