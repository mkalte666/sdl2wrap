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
#ifndef sdl2wrap_generated_SDL_hints
#define sdl2wrap_generated_SDL_hints

#include "SDL_hints.h"

namespace sdl2wrap {

/**
 * \brief Scoped version of SDL_HintPriority
 * 
 * Generated From SDL_hints.h:1265
 * \sa SDL_HintPriority
 */
enum class HintPriority : Uint32 {
    Default = SDL_HINT_DEFAULT,
    Normal = SDL_HINT_NORMAL,
    Override = SDL_HINT_OVERRIDE,
};
inline bool operator==(SDL_HintPriority a, HintPriority b) noexcept
{
    return a == static_cast<SDL_HintPriority>(b);
}
inline bool operator==(HintPriority a, SDL_HintPriority b) noexcept
{
    return a == static_cast<HintPriority>(b);
}

/**
 * \brief scoped enum for SDL_HINT_* defines
 * 
 * Generated from SDL_hints.h
 * \sa SDL_HINT_*
 */
enum class Hint {
    FramebufferAcceleration, ///< SDL_HINT_FRAMEBUFFER_ACCELERATION
    RenderDriver, ///< SDL_HINT_RENDER_DRIVER
    RenderOpenglShaders, ///< SDL_HINT_RENDER_OPENGL_SHADERS
    RenderDirect3dThreadsafe, ///< SDL_HINT_RENDER_DIRECT3D_THREADSAFE
    RenderDirect3d11Debug, ///< SDL_HINT_RENDER_DIRECT3D11_DEBUG
    RenderLogicalSizeMode, ///< SDL_HINT_RENDER_LOGICAL_SIZE_MODE
    RenderScaleQuality, ///< SDL_HINT_RENDER_SCALE_QUALITY
    RenderVsync, ///< SDL_HINT_RENDER_VSYNC
    VideoAllowScreensaver, ///< SDL_HINT_VIDEO_ALLOW_SCREENSAVER
    VideoExternalContext, ///< SDL_HINT_VIDEO_EXTERNAL_CONTEXT
    VideoX11Xvidmode, ///< SDL_HINT_VIDEO_X11_XVIDMODE
    VideoX11Xinerama, ///< SDL_HINT_VIDEO_X11_XINERAMA
    VideoX11Xrandr, ///< SDL_HINT_VIDEO_X11_XRANDR
    VideoX11WindowVisualid, ///< SDL_HINT_VIDEO_X11_WINDOW_VISUALID
    VideoX11NetWmPing, ///< SDL_HINT_VIDEO_X11_NET_WM_PING
    VideoX11NetWmBypassCompositor, ///< SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR
    VideoX11ForceEgl, ///< SDL_HINT_VIDEO_X11_FORCE_EGL
    WindowFrameUsableWhileCursorHidden, ///< SDL_HINT_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN
    WindowsIntresourceIcon, ///< SDL_HINT_WINDOWS_INTRESOURCE_ICON
    WindowsIntresourceIconSmall, ///< SDL_HINT_WINDOWS_INTRESOURCE_ICON_SMALL
    WindowsEnableMessageloop, ///< SDL_HINT_WINDOWS_ENABLE_MESSAGELOOP
    GrabKeyboard, ///< SDL_HINT_GRAB_KEYBOARD
    MouseDoubleClickTime, ///< SDL_HINT_MOUSE_DOUBLE_CLICK_TIME
    MouseDoubleClickRadius, ///< SDL_HINT_MOUSE_DOUBLE_CLICK_RADIUS
    MouseNormalSpeedScale, ///< SDL_HINT_MOUSE_NORMAL_SPEED_SCALE
    MouseRelativeSpeedScale, ///< SDL_HINT_MOUSE_RELATIVE_SPEED_SCALE
    MouseRelativeModeWarp, ///< SDL_HINT_MOUSE_RELATIVE_MODE_WARP
    MouseFocusClickthrough, ///< SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH
    TouchMouseEvents, ///< SDL_HINT_TOUCH_MOUSE_EVENTS
    MouseTouchEvents, ///< SDL_HINT_MOUSE_TOUCH_EVENTS
    VideoMinimizeOnFocusLoss, ///< SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS
    IdleTimerDisabled, ///< SDL_HINT_IDLE_TIMER_DISABLED
    Orientations, ///< SDL_HINT_ORIENTATIONS
    AppleTvControllerUiEvents, ///< SDL_HINT_APPLE_TV_CONTROLLER_UI_EVENTS
    AppleTvRemoteAllowRotation, ///< SDL_HINT_APPLE_TV_REMOTE_ALLOW_ROTATION
    IosHideHomeIndicator, ///< SDL_HINT_IOS_HIDE_HOME_INDICATOR
    AccelerometerAsJoystick, ///< SDL_HINT_ACCELEROMETER_AS_JOYSTICK
    TvRemoteAsJoystick, ///< SDL_HINT_TV_REMOTE_AS_JOYSTICK
    XinputEnabled, ///< SDL_HINT_XINPUT_ENABLED
    XinputUseOldJoystickMapping, ///< SDL_HINT_XINPUT_USE_OLD_JOYSTICK_MAPPING
    Gamecontrollerconfig, ///< SDL_HINT_GAMECONTROLLERCONFIG
    GamecontrollerconfigFile, ///< SDL_HINT_GAMECONTROLLERCONFIG_FILE
    GamecontrollerIgnoreDevices, ///< SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES
    GamecontrollerIgnoreDevicesExcept, ///< SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT
    GamecontrollerUseButtonLabels, ///< SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS
    JoystickAllowBackgroundEvents, ///< SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS
    JoystickHidapi, ///< SDL_HINT_JOYSTICK_HIDAPI
    JoystickHidapiPs4, ///< SDL_HINT_JOYSTICK_HIDAPI_PS4
    JoystickHidapiPs4Rumble, ///< SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE
    JoystickHidapiSteam, ///< SDL_HINT_JOYSTICK_HIDAPI_STEAM
    JoystickHidapiSwitch, ///< SDL_HINT_JOYSTICK_HIDAPI_SWITCH
    JoystickHidapiXbox, ///< SDL_HINT_JOYSTICK_HIDAPI_XBOX
    JoystickHidapiGamecube, ///< SDL_HINT_JOYSTICK_HIDAPI_GAMECUBE
    EnableSteamControllers, ///< SDL_HINT_ENABLE_STEAM_CONTROLLERS
    AllowTopmost, ///< SDL_HINT_ALLOW_TOPMOST
    TimerResolution, ///< SDL_HINT_TIMER_RESOLUTION
    QtwaylandContentOrientation, ///< SDL_HINT_QTWAYLAND_CONTENT_ORIENTATION
    QtwaylandWindowFlags, ///< SDL_HINT_QTWAYLAND_WINDOW_FLAGS
    ThreadStackSize, ///< SDL_HINT_THREAD_STACK_SIZE
    VideoHighdpiDisabled, ///< SDL_HINT_VIDEO_HIGHDPI_DISABLED
    MacCtrlClickEmulateRightClick, ///< SDL_HINT_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK
    VideoWinD3dcompiler, ///< SDL_HINT_VIDEO_WIN_D3DCOMPILER
    VideoWindowSharePixelFormat, ///< SDL_HINT_VIDEO_WINDOW_SHARE_PIXEL_FORMAT
    WinrtPrivacyPolicyUrl, ///< SDL_HINT_WINRT_PRIVACY_POLICY_URL
    WinrtPrivacyPolicyLabel, ///< SDL_HINT_WINRT_PRIVACY_POLICY_LABEL
    WinrtHandleBackButton, ///< SDL_HINT_WINRT_HANDLE_BACK_BUTTON
    VideoMacFullscreenSpaces, ///< SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES
    MacBackgroundApp, ///< SDL_HINT_MAC_BACKGROUND_APP
    AndroidApkExpansionMainFileVersion, ///< SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION
    AndroidApkExpansionPatchFileVersion, ///< SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION
    ImeInternalEditing, ///< SDL_HINT_IME_INTERNAL_EDITING
    AndroidTrapBackButton, ///< SDL_HINT_ANDROID_TRAP_BACK_BUTTON
    AndroidBlockOnPause, ///< SDL_HINT_ANDROID_BLOCK_ON_PAUSE
    ReturnKeyHidesIme, ///< SDL_HINT_RETURN_KEY_HIDES_IME
    EmscriptenKeyboardElement, ///< SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT
    NoSignalHandlers, ///< SDL_HINT_NO_SIGNAL_HANDLERS
    WindowsNoCloseOnAltF4, ///< SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4
    BmpSaveLegacyFormat, ///< SDL_HINT_BMP_SAVE_LEGACY_FORMAT
    WindowsDisableThreadNaming, ///< SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING
    RpiVideoLayer, ///< SDL_HINT_RPI_VIDEO_LAYER
    VideoDoubleBuffer, ///< SDL_HINT_VIDEO_DOUBLE_BUFFER
    OpenglEsDriver, ///< SDL_HINT_OPENGL_ES_DRIVER
    AudioResamplingMode, ///< SDL_HINT_AUDIO_RESAMPLING_MODE
    AudioCategory, ///< SDL_HINT_AUDIO_CATEGORY
    RenderBatching, ///< SDL_HINT_RENDER_BATCHING
    EventLogging, ///< SDL_HINT_EVENT_LOGGING
    WaveRiffChunkSize, ///< SDL_HINT_WAVE_RIFF_CHUNK_SIZE
    WaveTruncation, ///< SDL_HINT_WAVE_TRUNCATION
    WaveFactChunk, ///< SDL_HINT_WAVE_FACT_CHUNK
    DisplayUsableBounds, ///< SDL_HINT_DISPLAY_USABLE_BOUNDS
};

/**
 * \brief convert Hint to its basetype (const char*)
 */
const char* hintToBase(Hint value) noexcept;
#ifdef SDL2WRAP_DEFINITIONS
SDL2WRAP_INLINE const char* hintToBase(Hint value) noexcept
{
    switch (value) {
    case Hint::FramebufferAcceleration:
        return SDL_HINT_FRAMEBUFFER_ACCELERATION;
    case Hint::RenderDriver:
        return SDL_HINT_RENDER_DRIVER;
    case Hint::RenderOpenglShaders:
        return SDL_HINT_RENDER_OPENGL_SHADERS;
    case Hint::RenderDirect3dThreadsafe:
        return SDL_HINT_RENDER_DIRECT3D_THREADSAFE;
    case Hint::RenderDirect3d11Debug:
        return SDL_HINT_RENDER_DIRECT3D11_DEBUG;
    case Hint::RenderLogicalSizeMode:
        return SDL_HINT_RENDER_LOGICAL_SIZE_MODE;
    case Hint::RenderScaleQuality:
        return SDL_HINT_RENDER_SCALE_QUALITY;
    case Hint::RenderVsync:
        return SDL_HINT_RENDER_VSYNC;
    case Hint::VideoAllowScreensaver:
        return SDL_HINT_VIDEO_ALLOW_SCREENSAVER;
    case Hint::VideoExternalContext:
        return SDL_HINT_VIDEO_EXTERNAL_CONTEXT;
    case Hint::VideoX11Xvidmode:
        return SDL_HINT_VIDEO_X11_XVIDMODE;
    case Hint::VideoX11Xinerama:
        return SDL_HINT_VIDEO_X11_XINERAMA;
    case Hint::VideoX11Xrandr:
        return SDL_HINT_VIDEO_X11_XRANDR;
    case Hint::VideoX11WindowVisualid:
        return SDL_HINT_VIDEO_X11_WINDOW_VISUALID;
    case Hint::VideoX11NetWmPing:
        return SDL_HINT_VIDEO_X11_NET_WM_PING;
    case Hint::VideoX11NetWmBypassCompositor:
        return SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR;
    case Hint::VideoX11ForceEgl:
        return SDL_HINT_VIDEO_X11_FORCE_EGL;
    case Hint::WindowFrameUsableWhileCursorHidden:
        return SDL_HINT_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN;
    case Hint::WindowsIntresourceIcon:
        return SDL_HINT_WINDOWS_INTRESOURCE_ICON;
    case Hint::WindowsIntresourceIconSmall:
        return SDL_HINT_WINDOWS_INTRESOURCE_ICON_SMALL;
    case Hint::WindowsEnableMessageloop:
        return SDL_HINT_WINDOWS_ENABLE_MESSAGELOOP;
    case Hint::GrabKeyboard:
        return SDL_HINT_GRAB_KEYBOARD;
    case Hint::MouseDoubleClickTime:
        return SDL_HINT_MOUSE_DOUBLE_CLICK_TIME;
    case Hint::MouseDoubleClickRadius:
        return SDL_HINT_MOUSE_DOUBLE_CLICK_RADIUS;
    case Hint::MouseNormalSpeedScale:
        return SDL_HINT_MOUSE_NORMAL_SPEED_SCALE;
    case Hint::MouseRelativeSpeedScale:
        return SDL_HINT_MOUSE_RELATIVE_SPEED_SCALE;
    case Hint::MouseRelativeModeWarp:
        return SDL_HINT_MOUSE_RELATIVE_MODE_WARP;
    case Hint::MouseFocusClickthrough:
        return SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH;
    case Hint::TouchMouseEvents:
        return SDL_HINT_TOUCH_MOUSE_EVENTS;
    case Hint::MouseTouchEvents:
        return SDL_HINT_MOUSE_TOUCH_EVENTS;
    case Hint::VideoMinimizeOnFocusLoss:
        return SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS;
    case Hint::IdleTimerDisabled:
        return SDL_HINT_IDLE_TIMER_DISABLED;
    case Hint::Orientations:
        return SDL_HINT_ORIENTATIONS;
    case Hint::AppleTvControllerUiEvents:
        return SDL_HINT_APPLE_TV_CONTROLLER_UI_EVENTS;
    case Hint::AppleTvRemoteAllowRotation:
        return SDL_HINT_APPLE_TV_REMOTE_ALLOW_ROTATION;
    case Hint::IosHideHomeIndicator:
        return SDL_HINT_IOS_HIDE_HOME_INDICATOR;
    case Hint::AccelerometerAsJoystick:
        return SDL_HINT_ACCELEROMETER_AS_JOYSTICK;
    case Hint::TvRemoteAsJoystick:
        return SDL_HINT_TV_REMOTE_AS_JOYSTICK;
    case Hint::XinputEnabled:
        return SDL_HINT_XINPUT_ENABLED;
    case Hint::XinputUseOldJoystickMapping:
        return SDL_HINT_XINPUT_USE_OLD_JOYSTICK_MAPPING;
    case Hint::Gamecontrollerconfig:
        return SDL_HINT_GAMECONTROLLERCONFIG;
    case Hint::GamecontrollerconfigFile:
        return SDL_HINT_GAMECONTROLLERCONFIG_FILE;
    case Hint::GamecontrollerIgnoreDevices:
        return SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES;
    case Hint::GamecontrollerIgnoreDevicesExcept:
        return SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT;
    case Hint::GamecontrollerUseButtonLabels:
        return SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS;
    case Hint::JoystickAllowBackgroundEvents:
        return SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS;
    case Hint::JoystickHidapi:
        return SDL_HINT_JOYSTICK_HIDAPI;
    case Hint::JoystickHidapiPs4:
        return SDL_HINT_JOYSTICK_HIDAPI_PS4;
    case Hint::JoystickHidapiPs4Rumble:
        return SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE;
    case Hint::JoystickHidapiSteam:
        return SDL_HINT_JOYSTICK_HIDAPI_STEAM;
    case Hint::JoystickHidapiSwitch:
        return SDL_HINT_JOYSTICK_HIDAPI_SWITCH;
    case Hint::JoystickHidapiXbox:
        return SDL_HINT_JOYSTICK_HIDAPI_XBOX;
    case Hint::JoystickHidapiGamecube:
        return SDL_HINT_JOYSTICK_HIDAPI_GAMECUBE;
    case Hint::EnableSteamControllers:
        return SDL_HINT_ENABLE_STEAM_CONTROLLERS;
    case Hint::AllowTopmost:
        return SDL_HINT_ALLOW_TOPMOST;
    case Hint::TimerResolution:
        return SDL_HINT_TIMER_RESOLUTION;
    case Hint::QtwaylandContentOrientation:
        return SDL_HINT_QTWAYLAND_CONTENT_ORIENTATION;
    case Hint::QtwaylandWindowFlags:
        return SDL_HINT_QTWAYLAND_WINDOW_FLAGS;
    case Hint::ThreadStackSize:
        return SDL_HINT_THREAD_STACK_SIZE;
    case Hint::VideoHighdpiDisabled:
        return SDL_HINT_VIDEO_HIGHDPI_DISABLED;
    case Hint::MacCtrlClickEmulateRightClick:
        return SDL_HINT_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK;
    case Hint::VideoWinD3dcompiler:
        return SDL_HINT_VIDEO_WIN_D3DCOMPILER;
    case Hint::VideoWindowSharePixelFormat:
        return SDL_HINT_VIDEO_WINDOW_SHARE_PIXEL_FORMAT;
    case Hint::WinrtPrivacyPolicyUrl:
        return SDL_HINT_WINRT_PRIVACY_POLICY_URL;
    case Hint::WinrtPrivacyPolicyLabel:
        return SDL_HINT_WINRT_PRIVACY_POLICY_LABEL;
    case Hint::WinrtHandleBackButton:
        return SDL_HINT_WINRT_HANDLE_BACK_BUTTON;
    case Hint::VideoMacFullscreenSpaces:
        return SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES;
    case Hint::MacBackgroundApp:
        return SDL_HINT_MAC_BACKGROUND_APP;
    case Hint::AndroidApkExpansionMainFileVersion:
        return SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION;
    case Hint::AndroidApkExpansionPatchFileVersion:
        return SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION;
    case Hint::ImeInternalEditing:
        return SDL_HINT_IME_INTERNAL_EDITING;
    case Hint::AndroidTrapBackButton:
        return SDL_HINT_ANDROID_TRAP_BACK_BUTTON;
    case Hint::AndroidBlockOnPause:
        return SDL_HINT_ANDROID_BLOCK_ON_PAUSE;
    case Hint::ReturnKeyHidesIme:
        return SDL_HINT_RETURN_KEY_HIDES_IME;
    case Hint::EmscriptenKeyboardElement:
        return SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT;
    case Hint::NoSignalHandlers:
        return SDL_HINT_NO_SIGNAL_HANDLERS;
    case Hint::WindowsNoCloseOnAltF4:
        return SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4;
    case Hint::BmpSaveLegacyFormat:
        return SDL_HINT_BMP_SAVE_LEGACY_FORMAT;
    case Hint::WindowsDisableThreadNaming:
        return SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING;
    case Hint::RpiVideoLayer:
        return SDL_HINT_RPI_VIDEO_LAYER;
    case Hint::VideoDoubleBuffer:
        return SDL_HINT_VIDEO_DOUBLE_BUFFER;
    case Hint::OpenglEsDriver:
        return SDL_HINT_OPENGL_ES_DRIVER;
    case Hint::AudioResamplingMode:
        return SDL_HINT_AUDIO_RESAMPLING_MODE;
    case Hint::AudioCategory:
        return SDL_HINT_AUDIO_CATEGORY;
    case Hint::RenderBatching:
        return SDL_HINT_RENDER_BATCHING;
    case Hint::EventLogging:
        return SDL_HINT_EVENT_LOGGING;
    case Hint::WaveRiffChunkSize:
        return SDL_HINT_WAVE_RIFF_CHUNK_SIZE;
    case Hint::WaveTruncation:
        return SDL_HINT_WAVE_TRUNCATION;
    case Hint::WaveFactChunk:
        return SDL_HINT_WAVE_FACT_CHUNK;
    case Hint::DisplayUsableBounds:
        return SDL_HINT_DISPLAY_USABLE_BOUNDS;

    default:
        break;
    }

    return "";
}
#endif // SDL2WRAP_DEFINITIONS

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
