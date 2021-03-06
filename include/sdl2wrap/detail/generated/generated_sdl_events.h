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
#ifndef sdl2wrap_generated_SDL_events
#define sdl2wrap_generated_SDL_events

#include "SDL_events.h"

namespace sdl2wrap {

/**
 * \brief Scoped version of SDL_EventType
 * 
 * Generated From SDL_events.h:166
 * \sa SDL_EventType
 */
enum class EventType : Uint32 {
    Firstevent = SDL_FIRSTEVENT, ///< NOLINT \wrapImpl SDL_FIRSTEVENT EventType::Firstevent autogenerated
    Quit = SDL_QUIT, ///< NOLINT \wrapImpl SDL_QUIT EventType::Quit autogenerated
    AppTerminating = SDL_APP_TERMINATING, ///< NOLINT \wrapImpl SDL_APP_TERMINATING EventType::AppTerminating autogenerated
    AppLowmemory = SDL_APP_LOWMEMORY, ///< NOLINT \wrapImpl SDL_APP_LOWMEMORY EventType::AppLowmemory autogenerated
    AppWillenterbackground = SDL_APP_WILLENTERBACKGROUND, ///< NOLINT \wrapImpl SDL_APP_WILLENTERBACKGROUND EventType::AppWillenterbackground autogenerated
    AppDidenterbackground = SDL_APP_DIDENTERBACKGROUND, ///< NOLINT \wrapImpl SDL_APP_DIDENTERBACKGROUND EventType::AppDidenterbackground autogenerated
    AppWillenterforeground = SDL_APP_WILLENTERFOREGROUND, ///< NOLINT \wrapImpl SDL_APP_WILLENTERFOREGROUND EventType::AppWillenterforeground autogenerated
    AppDidenterforeground = SDL_APP_DIDENTERFOREGROUND, ///< NOLINT \wrapImpl SDL_APP_DIDENTERFOREGROUND EventType::AppDidenterforeground autogenerated
    Displayevent = SDL_DISPLAYEVENT, ///< NOLINT \wrapImpl SDL_DISPLAYEVENT EventType::Displayevent autogenerated
    Windowevent = SDL_WINDOWEVENT, ///< NOLINT \wrapImpl SDL_WINDOWEVENT EventType::Windowevent autogenerated
    Syswmevent = SDL_SYSWMEVENT, ///< NOLINT \wrapImpl SDL_SYSWMEVENT EventType::Syswmevent autogenerated
    Keydown = SDL_KEYDOWN, ///< NOLINT \wrapImpl SDL_KEYDOWN EventType::Keydown autogenerated
    Keyup = SDL_KEYUP, ///< NOLINT \wrapImpl SDL_KEYUP EventType::Keyup autogenerated
    Textediting = SDL_TEXTEDITING, ///< NOLINT \wrapImpl SDL_TEXTEDITING EventType::Textediting autogenerated
    Textinput = SDL_TEXTINPUT, ///< NOLINT \wrapImpl SDL_TEXTINPUT EventType::Textinput autogenerated
    Keymapchanged = SDL_KEYMAPCHANGED, ///< NOLINT \wrapImpl SDL_KEYMAPCHANGED EventType::Keymapchanged autogenerated
    Mousemotion = SDL_MOUSEMOTION, ///< NOLINT \wrapImpl SDL_MOUSEMOTION EventType::Mousemotion autogenerated
    Mousebuttondown = SDL_MOUSEBUTTONDOWN, ///< NOLINT \wrapImpl SDL_MOUSEBUTTONDOWN EventType::Mousebuttondown autogenerated
    Mousebuttonup = SDL_MOUSEBUTTONUP, ///< NOLINT \wrapImpl SDL_MOUSEBUTTONUP EventType::Mousebuttonup autogenerated
    Mousewheel = SDL_MOUSEWHEEL, ///< NOLINT \wrapImpl SDL_MOUSEWHEEL EventType::Mousewheel autogenerated
    Joyaxismotion = SDL_JOYAXISMOTION, ///< NOLINT \wrapImpl SDL_JOYAXISMOTION EventType::Joyaxismotion autogenerated
    Joyballmotion = SDL_JOYBALLMOTION, ///< NOLINT \wrapImpl SDL_JOYBALLMOTION EventType::Joyballmotion autogenerated
    Joyhatmotion = SDL_JOYHATMOTION, ///< NOLINT \wrapImpl SDL_JOYHATMOTION EventType::Joyhatmotion autogenerated
    Joybuttondown = SDL_JOYBUTTONDOWN, ///< NOLINT \wrapImpl SDL_JOYBUTTONDOWN EventType::Joybuttondown autogenerated
    Joybuttonup = SDL_JOYBUTTONUP, ///< NOLINT \wrapImpl SDL_JOYBUTTONUP EventType::Joybuttonup autogenerated
    Joydeviceadded = SDL_JOYDEVICEADDED, ///< NOLINT \wrapImpl SDL_JOYDEVICEADDED EventType::Joydeviceadded autogenerated
    Joydeviceremoved = SDL_JOYDEVICEREMOVED, ///< NOLINT \wrapImpl SDL_JOYDEVICEREMOVED EventType::Joydeviceremoved autogenerated
    Controlleraxismotion = SDL_CONTROLLERAXISMOTION, ///< NOLINT \wrapImpl SDL_CONTROLLERAXISMOTION EventType::Controlleraxismotion autogenerated
    Controllerbuttondown = SDL_CONTROLLERBUTTONDOWN, ///< NOLINT \wrapImpl SDL_CONTROLLERBUTTONDOWN EventType::Controllerbuttondown autogenerated
    Controllerbuttonup = SDL_CONTROLLERBUTTONUP, ///< NOLINT \wrapImpl SDL_CONTROLLERBUTTONUP EventType::Controllerbuttonup autogenerated
    Controllerdeviceadded = SDL_CONTROLLERDEVICEADDED, ///< NOLINT \wrapImpl SDL_CONTROLLERDEVICEADDED EventType::Controllerdeviceadded autogenerated
    Controllerdeviceremoved = SDL_CONTROLLERDEVICEREMOVED, ///< NOLINT \wrapImpl SDL_CONTROLLERDEVICEREMOVED EventType::Controllerdeviceremoved autogenerated
    Controllerdeviceremapped = SDL_CONTROLLERDEVICEREMAPPED, ///< NOLINT \wrapImpl SDL_CONTROLLERDEVICEREMAPPED EventType::Controllerdeviceremapped autogenerated
    Fingerdown = SDL_FINGERDOWN, ///< NOLINT \wrapImpl SDL_FINGERDOWN EventType::Fingerdown autogenerated
    Fingerup = SDL_FINGERUP, ///< NOLINT \wrapImpl SDL_FINGERUP EventType::Fingerup autogenerated
    Fingermotion = SDL_FINGERMOTION, ///< NOLINT \wrapImpl SDL_FINGERMOTION EventType::Fingermotion autogenerated
    Dollargesture = SDL_DOLLARGESTURE, ///< NOLINT \wrapImpl SDL_DOLLARGESTURE EventType::Dollargesture autogenerated
    Dollarrecord = SDL_DOLLARRECORD, ///< NOLINT \wrapImpl SDL_DOLLARRECORD EventType::Dollarrecord autogenerated
    Multigesture = SDL_MULTIGESTURE, ///< NOLINT \wrapImpl SDL_MULTIGESTURE EventType::Multigesture autogenerated
    Clipboardupdate = SDL_CLIPBOARDUPDATE, ///< NOLINT \wrapImpl SDL_CLIPBOARDUPDATE EventType::Clipboardupdate autogenerated
    Dropfile = SDL_DROPFILE, ///< NOLINT \wrapImpl SDL_DROPFILE EventType::Dropfile autogenerated
    Droptext = SDL_DROPTEXT, ///< NOLINT \wrapImpl SDL_DROPTEXT EventType::Droptext autogenerated
    Dropbegin = SDL_DROPBEGIN, ///< NOLINT \wrapImpl SDL_DROPBEGIN EventType::Dropbegin autogenerated
    Dropcomplete = SDL_DROPCOMPLETE, ///< NOLINT \wrapImpl SDL_DROPCOMPLETE EventType::Dropcomplete autogenerated
    Audiodeviceadded = SDL_AUDIODEVICEADDED, ///< NOLINT \wrapImpl SDL_AUDIODEVICEADDED EventType::Audiodeviceadded autogenerated
    Audiodeviceremoved = SDL_AUDIODEVICEREMOVED, ///< NOLINT \wrapImpl SDL_AUDIODEVICEREMOVED EventType::Audiodeviceremoved autogenerated
    Sensorupdate = SDL_SENSORUPDATE, ///< NOLINT \wrapImpl SDL_SENSORUPDATE EventType::Sensorupdate autogenerated
    RenderTargetsReset = SDL_RENDER_TARGETS_RESET, ///< NOLINT \wrapImpl SDL_RENDER_TARGETS_RESET EventType::RenderTargetsReset autogenerated
    RenderDeviceReset = SDL_RENDER_DEVICE_RESET, ///< NOLINT \wrapImpl SDL_RENDER_DEVICE_RESET EventType::RenderDeviceReset autogenerated
    Userevent = SDL_USEREVENT, ///< NOLINT \wrapImpl SDL_USEREVENT EventType::Userevent autogenerated
    Lastevent = SDL_LASTEVENT, ///< NOLINT \wrapImpl SDL_LASTEVENT EventType::Lastevent autogenerated
};
inline bool operator==(SDL_EventType a, EventType b) noexcept
{
    return a == static_cast<SDL_EventType>(b);
}
inline bool operator==(EventType a, SDL_EventType b) noexcept
{
    return a == static_cast<EventType>(b);
}
inline EventType operator|(EventType a, EventType b) noexcept
{
    return static_cast<EventType>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_eventaction
 * 
 * Generated From SDL_events.h:619
 * \sa SDL_eventaction
 */
enum class eventaction : Uint32 {
    Addevent = SDL_ADDEVENT, ///< NOLINT \wrapImpl SDL_ADDEVENT eventaction::Addevent autogenerated
    Peekevent = SDL_PEEKEVENT, ///< NOLINT \wrapImpl SDL_PEEKEVENT eventaction::Peekevent autogenerated
    Getevent = SDL_GETEVENT, ///< NOLINT \wrapImpl SDL_GETEVENT eventaction::Getevent autogenerated
};
inline bool operator==(SDL_eventaction a, eventaction b) noexcept
{
    return a == static_cast<SDL_eventaction>(b);
}
inline bool operator==(eventaction a, SDL_eventaction b) noexcept
{
    return a == static_cast<eventaction>(b);
}
inline eventaction operator|(eventaction a, eventaction b) noexcept
{
    return static_cast<eventaction>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

} // namespace sdl2wrap

#endif // sdl2wrap_generated_*
