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

/**
 * \brief Explicitly allow comparison between EventType and Uint32
 * \param a
 * \param b
 * \return
 */
bool operator==(const Uint32& a, const EventType& b);
bool operator==(const EventType& a, const Uint32& b);

namespace Input {
    using FilterCallback = SDL_EventFilter;

    /**
     * \brief Returns casted type of a given event
     *
     * Event types are Uint32 and we are using scoped enums
     * However, we cannot write a child with wrappers for SDL_Event, as its a union
     * So we have this helper.
     * \param event the event to get the type from
     * \returns event.type, casted to the EventType enum
     */
    EventType getEventType(const Event& event) noexcept;

    /**
     * \brief
     * \param events
     * \param numEvents
     * \param action
     * \param minType
     * \param maxType
     * \return
     * \wrapImpl SDL_PeepEvents Input::peepEvents
     */
    Result<int> peepEvents(Event* events, int numEvents, eventaction action, EventType minType, EventType maxType) noexcept;

    /**
     * \brief
     * \param type
     * \return
     * \wrapImpl SDL_HasEvent Imput::hasEvent
     */
    bool hasEvent(EventType type) noexcept;

    /**
     * \brief
     * \param minType
     * \param maxType
     * \return
     * \wrapImpl SDL_HasEvents Input::hasEvents
     */
    bool hasEvents(EventType minType, EventType maxType) noexcept;

    /**
     * \brief
     * \param type
     * \wrapImpl SDL_FlushEvent Input::flushEvent
     */
    void flushEvent(EventType type) noexcept;

    /**
     * \brief
     * \param minType
     * \param maxType
     * \wrapImpl SDL_FlushEvents Input::flushEvents
     */
    void flushEvents(EventType minType, EventType maxType) noexcept;

    /**
     * \brief
     * \param event
     * \return
     * \wrapImpl SDL_PollEvent Input::pollEvent
     */
    bool pollEvent(Event& event) noexcept;

    /**
     * \brief
     * \return
     * \sa pollEvent(Event& event)
     */
    bool pollEvent() noexcept;

    /**
     * \brief
     * \return
     * \wrapImpl SDL_WaitEvent Input::waitEvent
     */
    Result<Event> waitEvent() noexcept;

    /**
     * \brief
     * \param timeout
     * \return
     * \wrapImpl SDL_WaitEventTimeout Input::waitEventTimeout
     */
    Result<Event> waitEventTimeout(int timeout) noexcept;

    /**
     * \brief
     * \param event
     * \return
     * \wrapImpl SDL_PushEvent Input::pushEvent
     */
    EmptyResult pushEvent(Event& event) noexcept;

    /**
     * \brief
     * \param filter
     * \param userdata
     * \wrapImpl SDL_SetEventFilter Input::setEventFilter
     */
    void setEventFilter(FilterCallback filter, void* userdata) noexcept;

    /**
     * \brief
     * \param filter
     * \param userdata
     * \return
     * \wrapImpl SDL_GetEventFilter Input::getEventFilter
     */
    bool getEventFilter(FilterCallback& filter, void*& userdata) noexcept;

    /**
     * \brief
     * \param filter
     * \param userdata
     * \wrapImpl SDL_AddEventWatch Input::addEventWatch
     */
    void addEventWatch(FilterCallback filter, void* userdata) noexcept;

    /**
     * \brief
     * \param filter
     * \param userdata
     * \wrapImpl SDL_DelEventWatch Input::delEventWatch
     */
    void delEventWatch(FilterCallback filter, void* userdata) noexcept;

    /**
     * The functions \c Input::getEventState and \c Input::setEvent state wrap around sdls SDL_EventState
     * It does the same as the macro - call EventState but with SDL_QUERY as parameter
     * \brief
     * \param type
     * \return
     * \wrapImpl SDL_GetEventState Input::getEventState
     */
    EventState getEventState(EventType type) noexcept;

    /**
     * \brief
     * \param type
     * \param state
     * \return
     * \wrapImpl SDL_EventState
     * \sa Input::getEventState
     */
    EventState setEventState(EventType type, EventState state) noexcept;

    /**
     * \brief
     * \param numEvents
     * \return
     * \wrapImpl SDL_RegisterEvents Input::registerEvents
     */
    Result<EventType> registerEvents(int numEvents) noexcept;
}; // namespace Events

}; // namespace sdl2wrap

#endif //sdl2wrap_events_h
