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
     * \sa SDL_LogSetAllPriority
     */
    void setAllPriority(LogPriority priority) noexcept;

    /**
     * \brief Set the priority of one log function
     * \param category
     * \param priority
     * \sa SDL_LogSetPriority
     */
    void setPriority(int category, LogPriority priority) noexcept;

    /**
     * \brief Get the priority of one log category
     * \param category
     * \return
     * \sa SDL_LogGetPriority
     */
    LogPriority getPriority(int category) noexcept;

    /**
     * \brief Cet the current output function and its userdata
     * \param function
     * \param data
     * \sa SDL_LogGetOutputFunction
     */
    void getOutputFunction(OutputFunction& function, OutputFunctionDataT& data) noexcept;

    /**
     * \brief Set the output function and its parameter
     * \param function
     * \param data
     * \sa SDL_LogSetOutputFunction
     */
    void setOutputFunction(OutputFunction function, OutputFunctionDataT data) noexcept;

    /**
     * \brief Output a log message
     * \param category
     * \param priority
     * \param str
     * \sa SDL_LogMessage
     */
    void message(int category, LogPriority priority, const char* str) noexcept;

}; // namespace Log
}; // namespace sdl2wrap

#endif //sdl2wrap_log_h
