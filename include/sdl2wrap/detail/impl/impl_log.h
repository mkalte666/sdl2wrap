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

namespace Log {

SDL2WRAP_INLINE void setAllPriority(sdl2wrap::LogPriority priority) noexcept
{
    SDL_LogSetAllPriority(static_cast<SDL_LogPriority>(priority));
}

SDL2WRAP_INLINE void setPriority(int category, sdl2wrap::LogPriority priority) noexcept
{
    SDL_LogSetPriority(static_cast<int>(category), static_cast<SDL_LogPriority>(priority));
}

SDL2WRAP_INLINE LogPriority getPriority(int category) noexcept
{
    return static_cast<LogPriority>(SDL_LogGetPriority(category));
}

SDL2WRAP_INLINE void getOutputFunction(OutputFunction& function, OutputFunctionDataT& data) noexcept
{
    SDL_LogGetOutputFunction(&function, &data);
}

SDL2WRAP_INLINE void setOutputFunction(sdl2wrap::Log::OutputFunction function, sdl2wrap::Log::OutputFunctionDataT data) noexcept
{
    SDL_LogSetOutputFunction(function, data);
}

SDL2WRAP_INLINE void message(int category, LogPriority priority, const char* str) noexcept
{
    SDL_LogMessage(category, static_cast<SDL_LogPriority>(priority), "%s", str); //NOLINT
}

}; //namespace Log