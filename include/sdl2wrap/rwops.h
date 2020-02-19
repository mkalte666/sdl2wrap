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
 * \file rwops.h
 * wrapper for SDL_rwops.h
 */

#ifndef sdl2wrap_rwops_h
#define sdl2wrap_rwops_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on
#include "detail/generated/generated_sdl_rwops.h"
#include "detail/typewrapper.h"

namespace sdl2wrap {

/**
 * \brief File holds all file abstractions, such as SDL_rwops.h and SDL_filesystem.h
 */
namespace File {

    /**
     * \brief Since SDL_RWclose returns -1 on write error when closing a stream, we cannot use it directly in a destructor.
     * This wraps around it for destructor use. Use RWops::close() if you need the result!
     * \note there is no wrapper around for SDL_AllocRW for now. Please use custom RWops directly for now.
     * \param context
     * \sa SDL_RWclose
     */
    inline void rwopsDiscardCloseResult(SDL_RWops* context) noexcept
    {
        (void)SDL_RWclose(context);
    }

    class RWops : public TypeWrapper<RWops, SDL_RWops*, rwopsDiscardCloseResult> {
    public:
        using TypeWrapper::TypeWrapper;

        /**
         * \brief Create a RWops from a file
         * \param file
         * \param mode
         * \return
         * \sa SDL_RWFromFile
         */
        static Result fromFile(const char* file, const char* mode) noexcept;

#ifdef HAVE_STDIO_H
        /**
         * \brief Create a RWops from a file pointer.
         * \param fp
         * \param autoclose
         * \return
         * \sa SDL_RWFromFP
         */
        static Result fromFP(FILE* fp, bool autoclose) noexcept;
#endif

        /**
         * \brief Create a RWops from modifiable memory
         * \param mem
         * \param size
         * \return
         * \sa SDL_RWFromMem
         */
        static Result fromMem(void* mem, int size) noexcept;

        /**
         * \brief Create a RWops from const memory
         * \param mem
         * \param size
         * \return
         * \sa SDL_RWFromConstMem
         */
        static Result fromConstMem(const void* mem, int size) noexcept;

        /**
         * \brief Close this rwops and get the result
         * \note Use this instead of letting the object go out of scope if you must know the result
         *       ~RWops wont call SDL_Free anymore and this object becomes invalid as soon as this function returns!
         * \return
         */
        EmptyResult close() noexcept;

        /**
         * \brief Return the size of this RWops
         * \return
         * \sa SDL_RWsize
         */
        Sint64 size() const noexcept;

        /**
         * \brief Return the current offset in the data stream
         * \return
         * \sa SDL_RWsize
         */
        Sint64 tell() const noexcept;

        /**
         * \brief
         * \param offset
         * \param whence
         * \return
         * \sa SDL_RWseek
         */
        Sint64 seek(Sint64 offset, RWSeek whence) noexcept;

        /**
         * \brief
         * \param ptr
         * \param size
         * \param maxnum
         * \return
         * \sa SDL_RWread
         */
        size_t read(void* ptr, size_t size, size_t maxnum) noexcept;

        /**
         * \brief
         * \param ptr
         * \param size
         * \param num
         * \return
         * \sa SDL_RWwrite
         */
        size_t write(const void* ptr, size_t size, size_t num) noexcept;

        /**
         * \brief
         * \param bytesRead
         * \return
         * \note As oppesed to \c SDL_LoadFile_RW, this one does not have a setting to automatically close the rwops. This is intented.
         * Call close() directly or let it go out of scope!
         * \sa SDL_LoadFile_RW
         */
        sdl2wrap::Result<void*> loadFile(size_t& bytesRead) noexcept;

        /**
         * \brief
         * \param file
         * \param datasize
         * \return
         * \sa SDL_LoadFile
         */
        static sdl2wrap::Result<void*> loadFile(const char* file, size_t& datasize) noexcept;

        /**
         * \brief Read endian functions, analog to the ones from SDL
         * \return the value in native format
         * \sa SDL_Read*
         */
        /// \{
        Uint8 readU8() noexcept;
        Uint16 readLE16() noexcept;
        Uint16 readBE16() noexcept;
        Uint32 readLE32() noexcept;
        Uint32 readBE32() noexcept;
        Uint64 readLE64() noexcept;
        Uint64 readBE64() noexcept;
        /// \}

        /**
         * \brief Write endian functions, analog to the ones from SDL
         * \param value the value to write, in native format
         * \return a good result if the write succeeded, an error result otherwise
         * \sa SDL_Write*
         */
        /// \{
        EmptyResult writeU8(Uint8 value) noexcept;
        EmptyResult writeLE16(Uint16 value) noexcept;
        EmptyResult writeBE16(Uint16 value) noexcept;
        EmptyResult writeLE32(Uint32 value) noexcept;
        EmptyResult writeBE32(Uint32 value) noexcept;
        EmptyResult writeLE64(Uint64 value) noexcept;
        EmptyResult writeBE64(Uint64 value) noexcept;
        /// \}
    };

}; // namespace File
}; // namespace sdl2wrap

#endif //sdl2wrap_rwops_h
