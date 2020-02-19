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

#ifndef sdl2wrap_result_h
#define sdl2wrap_result_h

// always first!
#include "base.h"

namespace sdl2wrap {

/**
 * \brief Holds a result of class T or error information on failure
 * \tparam T Type of the result class. Must be movable and default constructable.
 */
template <class T>
class Result {
public:
    /**
     * \brief Information about an sdl error. msg contains the result of SDL_GetError() or a custom message
     */
    struct ErrorInfo {
        /// return code of the failed sdl function
        int rc = 0;
        /// c style array cause sdl only gives us these back and we may not have std::string available
        char msg[1024] = {}; //NOLINT
    };

    /// disabled
    Result(const Result&) = delete;

    /**
     * \brief Move constructor
     * \param rhs
     */
    Result(Result&& rhs) noexcept
    {
        *this = move(rhs);
    };
    /// disabled
    Result& operator=(const Result&) = delete;
    /**
     * \brief Move opeator
     * \param rhs
     * \return moves other member in here.
     */
    Result& operator=(Result&& rhs) noexcept
    {
        info = rhs.info;
        rhs.info = nullptr;
        value = move(rhs.value);
        return *this;
    }

    /// dtor
    ~Result() noexcept
    {
        delete info;
    }

    /**
     * \brief Creates a Result object
     * \param value the result
     * \return new result object
     */
    static Result success(T&& value) noexcept
    {
        return Result(move(value));
    }

    /**
     * \brief Creates a Result object that has an error
     * \param rc return code.
     * \return new result object
     * Note that the message becomes the result of SDL_GetError()
     */
    static Result error(int rc) noexcept
    {
        return Result(rc, SDL_GetError());
    }

    /**
     * \brief Create a Result object that has an error
     * \param rc return code for the error
     * \param msg the message of the error
     * \return new result object
     */
    static Result error(int rc, const char* msg) noexcept
    {
        return Result(rc, msg);
    }

    /**
     * \brief Create an error result from another result object
     * \tparam otherT base type of other Result
     * \param other
     * \return new result object
     */
    template <class otherT>
    static Result error(const Result<otherT>& other) noexcept
    {
        SDL2WRAP_ASSERT(other.hasError());
        auto otherErr = other.getError();
        return Result(otherErr.rc, otherErr.msg); //NOLINT: see above
    }

    /**
     * \brief Return value, if this result has one. Will assert if not
     * \return reference to the object
     */
    T& getValue() noexcept
    {
        SDL2WRAP_ASSERT(hasValue());

        return value;
    }

    /**
     * \brief Moves the value out of this result. Asserts if there is no value
     * \return The result object
     */
    T extractValue() noexcept
    {
        SDL2WRAP_ASSERT(hasValue());
        return move(value);
    }

    /**
     * \brief Retirms the error of this result. Asserts if there is a value
     * \return
     */
    const ErrorInfo& getError() const noexcept
    {
        SDL2WRAP_ASSERT(hasError());
        return *info;
    }

#ifdef SDL2WRAP_USE_STL
    /**
     * \brief Get the message, if there is an error
     * \return std::string containing the message of the error
     */
    std::string getErrorMessage() noexcept
    {
        return std::string(&(getError().msg[0]));
    }
#endif // SDL2WRAP_USE_STL

    /**
     * \return true if there is a value, false otherwise
     */
    bool hasValue() const noexcept
    {
        return !hasError();
    }

    /**
     * \brief
     * \return true if there is an error, false otherwise
     */
    bool hasError() const noexcept
    {
        return info != nullptr;
    }

    /**
     * \brief conversion operator for use directly as condition.
     * \return same as hasValue()
     */
    explicit operator bool() const noexcept
    {
        return hasValue();
    }

private:
    /**
     * \brief Ctor is Private. use success() or error() instead
     */
    Result() noexcept
        : info(new ErrorInfo)
    {
        info->msg[0] = '\0';
    }
    /**
     * \brief Ctor is Private. use success() or error() instead
     * \param rc
     * \param msg
     */
    Result(int rc, const char* msg) noexcept
        : info(new ErrorInfo)
    {
        info->rc = rc;
        SDL_utf8strlcpy(static_cast<char*>(info->msg), msg, sizeof(info->msg));
    }

    /**
     * \brief Ctor is Private. use success() or error() instead
     * \param value
     */
    explicit Result(T&& value) noexcept
        : value(move(value))
    {
    }

private:
    /// value
    T value = {};
    /// error, or null if there is a valid value
    ErrorInfo* info = nullptr;
};

/// Result type for the case where only success of failure is relevant
using EmptyResult = Result<bool>;

} // namespace sdl2wrap

#endif // sdl2wrap_result_h
