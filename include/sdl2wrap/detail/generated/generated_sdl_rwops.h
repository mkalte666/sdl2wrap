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
#ifndef sdl2wrap_generated_SDL_rwops
#define sdl2wrap_generated_SDL_rwops

#include "SDL_rwops.h"

namespace sdl2wrap {

/**
 * \brief scoped enum for SDL_RWOPS_* defines
 * 
 * Generated from SDL_rwops.h
 * \sa SDL_RWOPS_*
 */
enum class RWType : Uint32 {
    Unknown = SDL_RWOPS_UNKNOWN,
    Winfile = SDL_RWOPS_WINFILE,
    Stdfile = SDL_RWOPS_STDFILE,
    Jnifile = SDL_RWOPS_JNIFILE,
    Memory = SDL_RWOPS_MEMORY,
    MemoryRo = SDL_RWOPS_MEMORY_RO,
};

/**
 * \brief scoped enum for RW_SEEK_* defines
 * 
 * Generated from SDL_rwops.h
 * \sa RW_SEEK_*
 */
enum class RWSeek : Uint32 {
    Set = RW_SEEK_SET,
    Cur = RW_SEEK_CUR,
    End = RW_SEEK_END,
};

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
