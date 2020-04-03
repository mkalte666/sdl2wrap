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

#ifndef sdl2wrap_sdl2typewrapper_h
#define sdl2wrap_sdl2typewrapper_h

// always first!
#include "base.h"
#include "result.h"

namespace sdl2wrap {

template <class T>
using SDLDestructorFunc = void (*)(T);

/**
 * \brief Wraps an (SDL) Type by imitating an unique pointer
 * \tparam Child Child class for a new type; used for friend classing, results and whatnot
 * \tparam SDLPtrType The Original "Pointer type" from sdl. Such as: SDL_Window*, SDL_GLcontext, void*, ...
 * \tparam destructorFunc the function to be called to destroy this type (SDL_DestroyWindow, ...)
 *
 * Usually a TypeWrapper has full ownership of the pointer and only gives it up when i goes out of scope.
 * The type can only moved, not copied. get() retuns the raw pointer.
 * In cases non-owned types are needed, (SDL_GetKeyboardFocus, SDL_LockTextureSurface, ...) the "Unowned" wrapper is used.
 * It does not disable storing or helps with pointer verification, but makes it more explicit when something should not be freed
 *
 */
template <class Child, class SDLPtrType, SDLDestructorFunc<SDLPtrType> destructorFunc>
class TypeWrapper {
public:
    friend class Result<Child>;
    using ResultType = Result<Child>;
    using PtrType = SDLPtrType;

    TypeWrapper() noexcept = default;

    explicit TypeWrapper(SDLPtrType newPtr) noexcept
        : ptr(newPtr)
    {
    }
    TypeWrapper(const TypeWrapper&) = delete;
    TypeWrapper(TypeWrapper&& rhs) noexcept
        : ptr(rhs.ptr)
    {
        rhs.ptr = nullptr;
    }
    TypeWrapper& operator=(const TypeWrapper&) = delete;
    TypeWrapper& operator=(TypeWrapper&& rhs) noexcept
    {
        if (ptr != nullptr) {
            destructorFunc(ptr);
        }
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
        return *this;
    }

    virtual ~TypeWrapper() noexcept
    {
        if (ptr != nullptr) {
            destructorFunc(ptr);
        }
    }

    SDLPtrType get() const noexcept
    {
        return ptr;
    }

    static ResultType checkPtr(SDLPtrType ptr) noexcept
    {
        if (ptr == nullptr) {
            return ResultType::error(0);
        }

        return ResultType::success(Child(ptr));
    }

protected:
    /// danger danger, use with care. this breaks the guarantee that ptr is freed before!
    void forceReset(SDLPtrType newPtr) noexcept
    {
        ptr = newPtr;
    }

private:
    SDLPtrType ptr = nullptr;
};

template <class Child, class SDLPtrType, SDLDestructorFunc<SDLPtrType> destructorFunc>
class TypeWrapperWithPtrOp : public TypeWrapper<Child, SDLPtrType, destructorFunc> {
public:
    using TypeWrapper<Child, SDLPtrType, destructorFunc>::TypeWrapper;

    SDLPtrType operator->() noexcept
    {
        return TypeWrapper<Child, SDLPtrType, destructorFunc>::get();
    }
};

/**
 * \brief Subtype for unowned instances of type wrapper.
 * \sa TypeWrapper
 * \note This thing is as safe as a raw pointer. This means, not at all. Use with care, don't put it in containers, ...
 */
template <class Child>
class Unowned : public Child {
public:
    using Child::Child;
    friend class Result<Child>;
    using ResultType = Result<Child>;

    explicit Unowned(typename Child::PtrType p) noexcept
        : Child(p)
    {
    }

    Unowned(const Unowned&) = delete;
    Unowned(Unowned&& rhs) noexcept
        : Child(move(rhs.ptr))
    {
    }

    Unowned& operator=(const Unowned& rhs) noexcept = delete;
    Unowned& operator=(Unowned&& rhs) noexcept
    {
        Child::forceReset(rhs.ptr);
        rhs.forceReset(nullptr);
        return *this;
    }

    /// dtor makes sure ptr is nullptr before ~TypeWrapper is called
    ~Unowned() override
    {
        Child::forceReset(nullptr);
    }
};

} // namespace sdl2wrap
#endif //sdl2wrap_sdl2typewrapper_h
