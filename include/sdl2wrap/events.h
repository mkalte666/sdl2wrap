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

#ifndef sdl2wrap_events_h
#define sdl2wrap_events_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on

#include "detail/generated/generated_sdl_events.h"
#include "keyboard.h"

namespace sdl2wrap {

/**
     * \brief Implements the EventState Defines from SDL_events.h
     */
enum class EventState : int {
    Query = SDL_QUERY, ///< \wrapImpl SDL_QUERY EventState::Query
    Ignore = SDL_IGNORE, ///< \wrapImpl SDL_IGNORE EventState::Ignore
    Disable = SDL_DISABLE, ///< \wrapImpl SDL_DISABLE EventState::Disable
    Enable = SDL_ENABLE ///< \wrapImpl SDL_ENABLE EventState::Enable
};

/// \wrapImpl SDL_Event sdl2wrap::Event only a alias in the main namespace. we aint gonna touch the union!
using Event = SDL_Event;

namespace Input {
    using FilterCallback = SDL_EventFilter;

    Result<int> peepEvents(Event* events, int numEvents, eventaction action, EventType minType, EventType maxType) noexcept;
    bool hasEvent(EventType type) noexcept;
    bool hasEvents(EventType minType, EventType maxType) noexcept;

    void flushEvent(EventType type) noexcept;
    void flushEvents(EventType minType, EventType maxType) noexcept;

    bool pollEvent(Event& event) noexcept;
    bool pollEvent() noexcept;

    Result<Event> waitEvent() noexcept;
    Result<Event> waitEvent(int timeout) noexcept;

    EmptyResult pushEvent(Event& event) noexcept;

    void setEventFilter(FilterCallback filter, void* userdata) noexcept;
    bool getEventFilter(FilterCallback& filter, void*& userdata) noexcept;
    void addEventWatch(FilterCallback filter, void* userdata) noexcept;
    void delEventWatch(FilterCallback filter, void* userdata) noexcept;

    EventState getEventState(EventType type) noexcept;
    EventState setEventState(EventType type, EventState state) noexcept;

    Result<EventType> registerEvents(int numEvents) noexcept;
}; // namespace Events

}; // namespace sdl2wrap

#endif //sdl2wrap_events_h
