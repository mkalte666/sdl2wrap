//
// Created by mkalte on 12/02/2020.
//

#ifndef sdl2wrap_log_h
#define sdl2wrap_log_h

// always first!
#include "detail/base.h"

namespace sdl2wrap {

/**
 * \brief Predefined log categories
 * Instead of a scoped enum we use LogCategory as a struct containing an enum,
 * We want to allow implicit casting to int, as all functions accepting a category allow user defined categories too.
 */
struct LogCategory {
    enum {
        Application = SDL_LOG_CATEGORY_APPLICATION,
        Error = SDL_LOG_CATEGORY_ERROR,
        Assert = SDL_LOG_CATEGORY_ASSERT,
        System = SDL_LOG_CATEGORY_SYSTEM,
        Audio = SDL_LOG_CATEGORY_AUDIO,
        Video = SDL_LOG_CATEGORY_VIDEO,
        Render = SDL_LOG_CATEGORY_RENDER,
        Input = SDL_LOG_CATEGORY_INPUT,
        Test = SDL_LOG_CATEGORY_TEST,
        Custom = SDL_LOG_CATEGORY_CUSTOM
    };
};

enum class LogPriority : int {
    Verbose = SDL_LOG_PRIORITY_VERBOSE,
    Debug = SDL_LOG_PRIORITY_DEBUG,
    Info = SDL_LOG_PRIORITY_INFO,
    Warn = SDL_LOG_PRIORITY_WARN,
    Error = SDL_LOG_PRIORITY_ERROR,
    Critical = SDL_LOG_PRIORITY_CRITICAL
};

/**
 * \brief static class around sdl2 logging functions
 * Since logging is always available, this class is completly static
 *
 * Currently there is no overload for the normal log functions as they are vararg functions
 * There are however functions returning an object of type "LogWriter" that implements them
 */
class Log {
public:
    ///
    using OutputFunction = SDL_LogOutputFunction;
    ///
    using OutputFunctionDataT = void*;

    /**
     * \brief Set the priority of all log categories
     * \param priority
     */
    static void setAllPriority(LogPriority priority) noexcept;

    /**
     * \brief Set the priority of one log function
     * \param category
     * \param priority
     */
    static void setPriority(int category, LogPriority priority) noexcept;

    /**
     * \brief Get the priority of one log category
     * \param category
     * \return
     */
    static LogPriority getPriority(int category) noexcept;

    /**
     * \brief Cet the current output function and its userdata
     * \param function
     * \param data
     */
    static void getOutputFunction(OutputFunction& function, OutputFunctionDataT& data) noexcept;

    /**
     * \brief Set the output function and its parameter
     * \param function
     * \param data
     */
    static void setOutputFunction(OutputFunction function, OutputFunctionDataT data) noexcept;

    /**
     * \brief Output a log message
     * \param category
     * \param priority
     * \param str
     */
    static void message(int category, LogPriority priority, const char* str) noexcept;
};

#ifdef SDL2WRAP_DEFINITIONS

SDL2WRAP_INLINE void Log::setAllPriority(sdl2wrap::LogPriority priority) noexcept
{
    SDL_LogSetAllPriority(static_cast<SDL_LogPriority>(priority));
}

SDL2WRAP_INLINE void Log::setPriority(int category, sdl2wrap::LogPriority priority) noexcept
{
    SDL_LogSetPriority(static_cast<int>(category), static_cast<SDL_LogPriority>(priority));
}

SDL2WRAP_INLINE LogPriority Log::getPriority(int category) noexcept
{
    return static_cast<LogPriority>(SDL_LogGetPriority(category));
}

SDL2WRAP_INLINE void Log::getOutputFunction(OutputFunction& function, OutputFunctionDataT& data) noexcept
{
    SDL_LogGetOutputFunction(&function, &data);
}

SDL2WRAP_INLINE void Log::setOutputFunction(sdl2wrap::Log::OutputFunction function, sdl2wrap::Log::OutputFunctionDataT data) noexcept
{
    SDL_LogSetOutputFunction(function, data);
}

SDL2WRAP_INLINE void Log::message(int category, LogPriority priority, const char* str) noexcept
{
    SDL_LogMessage(category, static_cast<SDL_LogPriority>(priority), "%s", str); //NOLINT
}

#endif // SDL2WRAP_DEFINITIONS

}; // namespace sdl2wrap

#endif //sdl2wrap_log_h
