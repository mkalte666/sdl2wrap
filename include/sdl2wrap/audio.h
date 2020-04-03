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

#ifndef sdl2wrap_audio_h
#define sdl2wrap_audio_h

// always first
// clang-format off
#include "detail/base.h"
// clang-format on
#include "detail/generated/generated_sdl_audio.h"

namespace sdl2wrap {

namespace Audio {
    using Callback = SDL_AudioCallback;
    using DeviceID = SDL_AudioDeviceID;
    using Spec = SDL_AudioSpec;

    int getNumDrivers() noexcept;
    const char* getDriver(int index) noexcept;
    const char* getCurrentDriver() noexcept;

    EmptyResult init(const char* driverName) noexcept;
    void quit() noexcept;

    EmptyResult open(Spec& desired) noexcept;
    EmptyResult open(Spec& desired, Spec& obtained) noexcept;

    void close() noexcept;
    void closeDevice(DeviceID dev) noexcept;

    int getNumDevices(bool isCapture) noexcept;
    const char* getDeviceName(int index, bool isCapture) noexcept;
    Result<DeviceID> openDevice(const char* device, bool isCapture, const Spec& desired, Spec& obtained, AudioAllow allowedChanges);

    AudioStatus getStatus() noexcept;
    AudioStatus getDeviceStatus(DeviceID device) noexcept;

    void pause(bool pauseOn) noexcept;
    void pauseDevice(DeviceID dev, bool pauseOn) noexcept;

    void lock() noexcept;
    void lockDevice(DeviceID dev) noexcept;
    void unlock() noexcept;
    void unlockDevice(DeviceID dev) noexcept;

} // namespace Audio

} // namespace sdl2wrap

#endif //sdl2wrap_audio_h
