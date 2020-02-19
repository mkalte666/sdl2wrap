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

namespace File {

SDL2WRAP_INLINE RWops::Result RWops::fromFile(const char* file, const char* mode) noexcept
{
    auto rwops = SDL_RWFromFile(file, mode);
    if (rwops == nullptr) {
        return Result::error(0);
    }

    return Result::success(RWops(rwops));
}

#ifdef HAVE_STDIO_H
SDL2WRAP_INLINE RWops::Result RWops::fromFP(FILE* fp, bool autoclose) noexcept
{
    auto rwops = SDL_RWFromFP(fp, autoclose ? SDL_TRUE : SDL_FALSE);
    if (rwops == nullptr) {
        return Result::error(0);
    }

    return Result::success(RWops(rwops));
}
#endif

SDL2WRAP_INLINE RWops::Result RWops::fromMem(void* mem, int size) noexcept
{
    auto rwops = SDL_RWFromMem(mem, size);
    if (rwops == nullptr) {
        return Result::error(0);
    }

    return Result::success(RWops(rwops));
}

SDL2WRAP_INLINE RWops::Result RWops::fromConstMem(const void* mem, int size) noexcept
{
    auto rwops = SDL_RWFromConstMem(mem, size);
    if (rwops == nullptr) {
        return Result::error(0);
    }

    return Result::success(RWops(rwops));
}

SDL2WRAP_INLINE EmptyResult RWops::close() noexcept
{
    auto rc = SDL_RWclose(get());
    forceReset(nullptr);
    if (rc != 0) {
        return EmptyResult::error(rc);
    }

    return EmptyResult::success(true);
}

SDL2WRAP_INLINE Sint64 RWops::size() const noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_RWsize(get());
}

SDL2WRAP_INLINE Sint64 RWops::tell() const noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_RWtell(get());
}

SDL2WRAP_INLINE Sint64 RWops::seek(Sint64 offset, RWSeek whence) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_RWseek(get(), offset, static_cast<int>(whence));
}

SDL2WRAP_INLINE size_t RWops::read(void* ptr, size_t size, size_t maxnum) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_RWread(get(), ptr, size, maxnum);
}

SDL2WRAP_INLINE size_t RWops::write(const void* ptr, size_t size, size_t num) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_RWwrite(get(), ptr, size, num);
}

SDL2WRAP_INLINE sdl2wrap::Result<void*> RWops::loadFile(size_t& bytesRead) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    void* data = SDL_LoadFile_RW(get(), &bytesRead, 0);
    if (data == nullptr) {
        return sdl2wrap::Result<void*>::error(0);
    }

    return sdl2wrap::Result<void*>::success(move(data));
}

SDL2WRAP_INLINE sdl2wrap::Result<void*> RWops::loadFile(const char* file, size_t& datasize) noexcept
{
    void* data = SDL_LoadFile(file, &datasize);
    if (data == nullptr) {
        return sdl2wrap::Result<void*>::error(0);
    }

    return sdl2wrap::Result<void*>::success(move(data));
}

SDL2WRAP_INLINE Uint8 RWops::readU8() noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_ReadU8(get());
}

SDL2WRAP_INLINE Uint16 RWops::readLE16() noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_ReadLE16(get());
}

SDL2WRAP_INLINE Uint16 RWops::readBE16() noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_ReadBE16(get());
}

SDL2WRAP_INLINE Uint32 RWops::readLE32() noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_ReadLE32(get());
}

SDL2WRAP_INLINE Uint32 RWops::readBE32() noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_ReadBE32(get());
}

SDL2WRAP_INLINE Uint64 RWops::readLE64() noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_ReadLE64(get());
}

SDL2WRAP_INLINE Uint64 RWops::readBE64() noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return SDL_ReadBE64(get());
}

SDL2WRAP_INLINE EmptyResult checkRwopsWriteRc(size_t rc) noexcept
{
    if (rc == 1) {
        return EmptyResult::success(true);
    }

    return EmptyResult::error(0);
}

SDL2WRAP_INLINE EmptyResult RWops::writeU8(Uint8 value) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return checkRwopsWriteRc(SDL_WriteU8(get(), value));
}

SDL2WRAP_INLINE EmptyResult RWops::writeLE16(Uint16 value) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return checkRwopsWriteRc(SDL_WriteLE16(get(), value));
}

SDL2WRAP_INLINE EmptyResult RWops::writeBE16(Uint16 value) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return checkRwopsWriteRc(SDL_WriteBE16(get(), value));
}

SDL2WRAP_INLINE EmptyResult RWops::writeLE32(Uint32 value) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return checkRwopsWriteRc(SDL_WriteLE32(get(), value));
}

SDL2WRAP_INLINE EmptyResult RWops::writeBE32(Uint32 value) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return checkRwopsWriteRc(SDL_WriteBE32(get(), value));
}

SDL2WRAP_INLINE EmptyResult RWops::writeLE64(Uint64 value) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return checkRwopsWriteRc(SDL_WriteLE64(get(), value));
}

SDL2WRAP_INLINE EmptyResult RWops::writeBE64(Uint64 value) noexcept
{
    SDL2WRAP_ASSERT(get() != nullptr);
    return checkRwopsWriteRc(SDL_WriteBE64(get(), value));
}

}; //namespace File