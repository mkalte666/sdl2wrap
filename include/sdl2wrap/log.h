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

#ifndef sdl2wrap_log_h
#define sdl2wrap_log_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on
#include "detail/generated/generated_sdl_log.h"

namespace sdl2wrap {

/**
 * \brief static class around sdl2 logging functions
 * Since logging is always available, this stuff can always be called!
 *
 * Currently there is no overload for the normal log functions as they are vararg functions
 * There are however functions returning an object of type "LogWriter" that implements them
 */
namespace Log {
    ///
    using OutputFunction = SDL_LogOutputFunction;
    ///
    using OutputFunctionDataT = void*;

    /**
     * \brief Set the priority of all log categories
     * \param priority
     * \wrapImpl SDL_LogSetAllPriority Log::setAllPriority
     */
    void setAllPriority(LogPriority priority) noexcept;

    /**
     * \brief Set the priority of one log function
     * \param category
     * \param priority
     * \wrapImpl SDL_LogSetPriority Log::setPriority
     */
    void setPriority(int category, LogPriority priority) noexcept;

    /**
     * \brief Get the priority of one log category
     * \param category
     * \return
     * \wrapImpl SDL_LogGetPriority Log::getPriority
     */
    LogPriority getPriority(int category) noexcept;

    /**
     * \brief Cet the current output function and its userdata
     * \param function
     * \param data
     * \wrapImpl SDL_LogGetOutputFunction Log::getOutputFunction
     */
    void getOutputFunction(OutputFunction& function, OutputFunctionDataT& data) noexcept;

    /**
     * \brief Set the output function and its parameter
     * \param function
     * \param data
     * \wrapImpl SDL_LogSetOutputFunction Log::setOutputFunction
     */
    void setOutputFunction(OutputFunction function, OutputFunctionDataT data) noexcept;

    /**
     * \brief Output a log message
     * \param category
     * \param priority
     * \param str
     * \wrapImpl SDL_LogMessage Log::message
     */
    void message(int category, LogPriority priority, const char* str) noexcept;

} // namespace Log
} // namespace sdl2wrap

#endif //sdl2wrap_log_h
