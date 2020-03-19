
#include <sdl2wrap/audio.h>

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

namespace Audio {

SDL2WRAP_INLINE int getNumDrivers() noexcept
{
    return SDL_GetNumAudioDrivers();
}

SDL2WRAP_INLINE const char* getDriver(int index) noexcept
{
    return SDL_GetAudioDriver(index);
}

SDL2WRAP_INLINE const char* getCurrentDriver() noexcept
{
    return SDL_GetCurrentAudioDriver();
}

SDL2WRAP_INLINE EmptyResult init(const char* driverName) noexcept
{
    auto rc = SDL_AudioInit(driverName);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void quit() noexcept
{
    SDL_AudioQuit();
}

SDL2WRAP_INLINE EmptyResult open(Spec& desired) noexcept
{
    auto rc = SDL_OpenAudio(&desired, nullptr);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE EmptyResult open(Spec& desired, Spec& obtained) noexcept
{
    auto rc = SDL_OpenAudio(&desired, &obtained);
    return checkEmptyResultRc(rc);
}

SDL2WRAP_INLINE void close() noexcept
{
    SDL_CloseAudio();
}

SDL2WRAP_INLINE void closeDevice(DeviceID dev) noexcept
{
    SDL_CloseAudioDevice(dev);
}

SDL2WRAP_INLINE int getNumDevices(bool isCapture) noexcept
{
    return SDL_GetNumAudioDevices(isCapture ? 1 : 0);
}

SDL2WRAP_INLINE const char* getDeviceName(int index, bool isCapture) noexcept
{
    return SDL_GetAudioDeviceName(index, isCapture ? 1 : 0);
}

SDL2WRAP_INLINE Result<DeviceID> openDevice(const char* device, bool isCapture, const Spec& desired, Spec& obtained, AudioAllow allowedChanges)
{
    auto id = SDL_OpenAudioDevice(device, isCapture ? 1 : 0, &desired, &obtained, static_cast<int>(allowedChanges));
    if (id == 0) {
        return Result<DeviceID>::error(0);
    }

    return Result<DeviceID>::success(move(id));
}

SDL2WRAP_INLINE AudioStatus getStatus() noexcept
{
    return static_cast<AudioStatus>(SDL_GetAudioStatus());
}

SDL2WRAP_INLINE AudioStatus getDeviceStatus(DeviceID device) noexcept
{
    return static_cast<AudioStatus>(SDL_GetAudioDeviceStatus(device));
}

SDL2WRAP_INLINE void pause(bool pauseOn) noexcept
{
    SDL_PauseAudio(pauseOn ? 1 : 0);
}

SDL2WRAP_INLINE void pauseDevice(DeviceID dev, bool pauseOn) noexcept
{
    SDL_PauseAudioDevice(dev, pauseOn ? 1 : 0);
}

SDL2WRAP_INLINE void lock() noexcept
{
    SDL_LockAudio();
}

SDL2WRAP_INLINE void lockDevice(DeviceID dev) noexcept
{
    SDL_LockAudioDevice(dev);
}

SDL2WRAP_INLINE void unlock() noexcept
{
    SDL_UnlockAudio();
}

SDL2WRAP_INLINE void unlockDevice(DeviceID dev) noexcept
{
    SDL_UnlockAudioDevice(dev);
}

}; // namespace Audio