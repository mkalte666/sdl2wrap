
#include <sdl2wrap/events.h>

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

#ifndef sdl2wrap_impl_events_h
#define sdl2wrap_impl_events_h

bool operator==(const Uint32& a, const EventType& b)
{
    return a == static_cast<Uint32>(b);
}
bool operator==(const EventType& a, const Uint32& b)
{
    return b == a;
}

namespace Input {

SDL2WRAP_INLINE EventType getEventType(const Event& event) noexcept
{
    return static_cast<EventType>(event.type);
}

SDL2WRAP_INLINE Result<int> peepEvents(Event* events, int numEvents, eventaction action, EventType minType, EventType maxType) noexcept
{
    auto rc = SDL_PeepEvents(events, numEvents, static_cast<SDL_eventaction>(action), static_cast<Uint32>(minType), static_cast<Uint32>(maxType));
    if (rc != -1) {
        return Result<int>::success(move(rc));
    }

    return Result<int>::error(rc);
}

SDL2WRAP_INLINE bool hasEvent(EventType type) noexcept
{
    return SDL_HasEvent(static_cast<Uint32>(type)) == SDL_TRUE;
}

SDL2WRAP_INLINE bool hasEvents(EventType minType, EventType maxType) noexcept
{
    return SDL_HasEvents(static_cast<Uint32>(minType), static_cast<Uint32>(maxType)) == SDL_TRUE;
}

SDL2WRAP_INLINE void flushEvent(EventType type) noexcept
{
    SDL_FlushEvent(static_cast<Uint32>(type));
}
SDL2WRAP_INLINE void flushEvents(EventType minType, EventType maxType) noexcept
{
    SDL_FlushEvents(static_cast<Uint32>(minType), static_cast<Uint32>(maxType));
}

SDL2WRAP_INLINE bool pollEvent(Event& event) noexcept
{
    return SDL_PollEvent(&event) == 1;
}

SDL2WRAP_INLINE bool pollEvent() noexcept
{
    return SDL_PollEvent(nullptr) == 1;
}

SDL2WRAP_INLINE Result<Event> waitEvent() noexcept
{
    Event e;
    auto rc = SDL_WaitEvent(&e);
    if (rc == 1) {
        return Result<Event>::success(move(e));
    }

    return Result<Event>::error(rc);
}

SDL2WRAP_INLINE Result<Event> waitEventTimeout(int timeout) noexcept
{
    Event e;
    auto rc = SDL_WaitEventTimeout(&e, timeout);
    if (rc == 1) {
        return Result<Event>::success(move(e));
    }

    return Result<Event>::error(rc);
}

SDL2WRAP_INLINE EmptyResult pushEvent(Event& event) noexcept
{
    auto rc = SDL_PushEvent(&event);
    return checkEmptyResultRc(rc, 1);
}

SDL2WRAP_INLINE void setEventFilter(FilterCallback filter, void* userdata) noexcept
{
    SDL_SetEventFilter(filter, userdata);
}
SDL2WRAP_INLINE bool getEventFilter(FilterCallback& filter, void*& userdata) noexcept
{
    return SDL_GetEventFilter(&filter, &userdata) == SDL_TRUE;
}
SDL2WRAP_INLINE void addEventWatch(FilterCallback filter, void* userdata) noexcept
{
    SDL_AddEventWatch(filter, userdata);
}
SDL2WRAP_INLINE void delEventWatch(FilterCallback filter, void* userdata) noexcept
{
    SDL_DelEventWatch(filter, userdata);
}

SDL2WRAP_INLINE EventState getEventState(EventType type) noexcept
{
    return setEventState(type, EventState::Query);
}
SDL2WRAP_INLINE EventState setEventState(EventType type, EventState state) noexcept
{
    return static_cast<EventState>(SDL_EventState(static_cast<Uint32>(type), static_cast<int>(state)));
}

SDL2WRAP_INLINE Result<EventType> registerEvents(int numEvents) noexcept
{
    constexpr Uint32 registerErrorValue = 0xFFFFFFFF;
    Uint32 eventOrError = SDL_RegisterEvents(numEvents);
    if (eventOrError == registerErrorValue) {
        return Result<EventType>::error(0);
    }

    auto eventType = static_cast<EventType>(eventOrError);
    return Result<EventType>::success(move(eventType));
}

} // namespace Events

#endif //sdl2wrap_impl_events_h
