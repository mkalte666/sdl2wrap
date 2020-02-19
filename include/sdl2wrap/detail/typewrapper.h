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

template <class Child, class SDLPtrType, SDLDestructorFunc<SDLPtrType> destructorFunc>
class TypeWrapper {
public:
    friend class Result<Child>;
    using Result = Result<Child>;
    using PtrType = SDLPtrType;

    TypeWrapper() noexcept = default;

    explicit TypeWrapper(SDLPtrType ptr) noexcept
        : ptr(ptr)
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
    ~TypeWrapper() noexcept
    {
        if (ptr != nullptr) {
            destructorFunc(ptr);
        }
    }

    SDLPtrType get() noexcept
    {
        return ptr;
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

} // namespace sdl2wrap
#endif //sdl2wrap_sdl2typewrapper_h
