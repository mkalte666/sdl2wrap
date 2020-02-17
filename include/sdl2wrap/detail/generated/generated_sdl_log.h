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
#ifndef sdl2wrap_generated_SDL_log
#define sdl2wrap_generated_SDL_log

#include "SDL_log.h"

namespace sdl2wrap {

/**
 * \brief Scoped version of SDL_LogCategory
 * 
 * Generated From SDL_log.h:97
 * \sa SDL_LogCategory
 */
enum class LogCategory : Uint32 {
    CategoryApplication = SDL_LOG_CATEGORY_APPLICATION,
    CategoryError = SDL_LOG_CATEGORY_ERROR,
    CategoryAssert = SDL_LOG_CATEGORY_ASSERT,
    CategorySystem = SDL_LOG_CATEGORY_SYSTEM,
    CategoryAudio = SDL_LOG_CATEGORY_AUDIO,
    CategoryVideo = SDL_LOG_CATEGORY_VIDEO,
    CategoryRender = SDL_LOG_CATEGORY_RENDER,
    CategoryInput = SDL_LOG_CATEGORY_INPUT,
    CategoryTest = SDL_LOG_CATEGORY_TEST,
    CategoryReserved1 = SDL_LOG_CATEGORY_RESERVED1,
    CategoryReserved2 = SDL_LOG_CATEGORY_RESERVED2,
    CategoryReserved3 = SDL_LOG_CATEGORY_RESERVED3,
    CategoryReserved4 = SDL_LOG_CATEGORY_RESERVED4,
    CategoryReserved5 = SDL_LOG_CATEGORY_RESERVED5,
    CategoryReserved6 = SDL_LOG_CATEGORY_RESERVED6,
    CategoryReserved7 = SDL_LOG_CATEGORY_RESERVED7,
    CategoryReserved8 = SDL_LOG_CATEGORY_RESERVED8,
    CategoryReserved9 = SDL_LOG_CATEGORY_RESERVED9,
    CategoryReserved10 = SDL_LOG_CATEGORY_RESERVED10,
    CategoryCustom = SDL_LOG_CATEGORY_CUSTOM,
};
inline bool operator==(SDL_LogCategory a, LogCategory b) noexcept
{
    return a == static_cast<SDL_LogCategory>(b);
}
inline bool operator==(LogCategory a, SDL_LogCategory b) noexcept
{
    return a == static_cast<LogCategory>(b);
}

/**
 * \brief Scoped version of SDL_LogPriority
 * 
 * Generated From SDL_log.h:111
 * \sa SDL_LogPriority
 */
enum class LogPriority : Uint32 {
    PriorityVerbose = SDL_LOG_PRIORITY_VERBOSE,
    PriorityDebug = SDL_LOG_PRIORITY_DEBUG,
    PriorityInfo = SDL_LOG_PRIORITY_INFO,
    PriorityWarn = SDL_LOG_PRIORITY_WARN,
    PriorityError = SDL_LOG_PRIORITY_ERROR,
    PriorityCritical = SDL_LOG_PRIORITY_CRITICAL,
    LogPriorities = SDL_NUM_LOG_PRIORITIES,
};
inline bool operator==(SDL_LogPriority a, LogPriority b) noexcept
{
    return a == static_cast<SDL_LogPriority>(b);
}
inline bool operator==(LogPriority a, SDL_LogPriority b) noexcept
{
    return a == static_cast<LogPriority>(b);
}

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
