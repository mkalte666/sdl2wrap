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

namespace Error {

SDL2WRAP_INLINE void set(const char* err) noexcept
{
    (void)SDL_SetError("%s", err); //NOLINT
}

SDL2WRAP_INLINE const char* get() noexcept
{
    return SDL_GetError();
}

SDL2WRAP_INLINE void clear() noexcept
{
    return SDL_ClearError();
}

#ifdef SDL2WRAP_USE_STL

SDL2WRAP_INLINE void set(const std::string& err) noexcept
{
    (void)SDL_SetError("%s", err.c_str()); //NOLINT
}

SDL2WRAP_INLINE std::string getStr() noexcept
{
    return std::string(Error::get());
}

#endif // SDL2WRAP_USE_STL

} // namespace Error