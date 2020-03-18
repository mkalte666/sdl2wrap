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
#ifndef sdl2wrap_generated_SDL_video
#define sdl2wrap_generated_SDL_video

#include "SDL_video.h"

namespace sdl2wrap {

/**
 * \brief Scoped version of SDL_WindowFlags
 * 
 * Generated From SDL_video.h:122
 * \sa SDL_WindowFlags
 */
enum class WindowFlags : Uint32 {
    Fullscreen = SDL_WINDOW_FULLSCREEN, ///< NOLINT \wrapImpl SDL_WINDOW_FULLSCREEN WindowFlags::Fullscreen autogenerated
    Opengl = SDL_WINDOW_OPENGL, ///< NOLINT \wrapImpl SDL_WINDOW_OPENGL WindowFlags::Opengl autogenerated
    Shown = SDL_WINDOW_SHOWN, ///< NOLINT \wrapImpl SDL_WINDOW_SHOWN WindowFlags::Shown autogenerated
    Hidden = SDL_WINDOW_HIDDEN, ///< NOLINT \wrapImpl SDL_WINDOW_HIDDEN WindowFlags::Hidden autogenerated
    Borderless = SDL_WINDOW_BORDERLESS, ///< NOLINT \wrapImpl SDL_WINDOW_BORDERLESS WindowFlags::Borderless autogenerated
    Resizable = SDL_WINDOW_RESIZABLE, ///< NOLINT \wrapImpl SDL_WINDOW_RESIZABLE WindowFlags::Resizable autogenerated
    Minimized = SDL_WINDOW_MINIMIZED, ///< NOLINT \wrapImpl SDL_WINDOW_MINIMIZED WindowFlags::Minimized autogenerated
    Maximized = SDL_WINDOW_MAXIMIZED, ///< NOLINT \wrapImpl SDL_WINDOW_MAXIMIZED WindowFlags::Maximized autogenerated
    InputGrabbed = SDL_WINDOW_INPUT_GRABBED, ///< NOLINT \wrapImpl SDL_WINDOW_INPUT_GRABBED WindowFlags::InputGrabbed autogenerated
    InputFocus = SDL_WINDOW_INPUT_FOCUS, ///< NOLINT \wrapImpl SDL_WINDOW_INPUT_FOCUS WindowFlags::InputFocus autogenerated
    MouseFocus = SDL_WINDOW_MOUSE_FOCUS, ///< NOLINT \wrapImpl SDL_WINDOW_MOUSE_FOCUS WindowFlags::MouseFocus autogenerated
    FullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP, ///< NOLINT \wrapImpl SDL_WINDOW_FULLSCREEN_DESKTOP WindowFlags::FullscreenDesktop autogenerated
    Foreign = SDL_WINDOW_FOREIGN, ///< NOLINT \wrapImpl SDL_WINDOW_FOREIGN WindowFlags::Foreign autogenerated
    AllowHighdpi = SDL_WINDOW_ALLOW_HIGHDPI, ///< NOLINT \wrapImpl SDL_WINDOW_ALLOW_HIGHDPI WindowFlags::AllowHighdpi autogenerated
    MouseCapture = SDL_WINDOW_MOUSE_CAPTURE, ///< NOLINT \wrapImpl SDL_WINDOW_MOUSE_CAPTURE WindowFlags::MouseCapture autogenerated
    AlwaysOnTop = SDL_WINDOW_ALWAYS_ON_TOP, ///< NOLINT \wrapImpl SDL_WINDOW_ALWAYS_ON_TOP WindowFlags::AlwaysOnTop autogenerated
    SkipTaskbar = SDL_WINDOW_SKIP_TASKBAR, ///< NOLINT \wrapImpl SDL_WINDOW_SKIP_TASKBAR WindowFlags::SkipTaskbar autogenerated
    Utility = SDL_WINDOW_UTILITY, ///< NOLINT \wrapImpl SDL_WINDOW_UTILITY WindowFlags::Utility autogenerated
    Tooltip = SDL_WINDOW_TOOLTIP, ///< NOLINT \wrapImpl SDL_WINDOW_TOOLTIP WindowFlags::Tooltip autogenerated
    PopupMenu = SDL_WINDOW_POPUP_MENU, ///< NOLINT \wrapImpl SDL_WINDOW_POPUP_MENU WindowFlags::PopupMenu autogenerated
    Vulkan = SDL_WINDOW_VULKAN, ///< NOLINT \wrapImpl SDL_WINDOW_VULKAN WindowFlags::Vulkan autogenerated
};
inline bool operator==(SDL_WindowFlags a, WindowFlags b) noexcept
{
    return a == static_cast<SDL_WindowFlags>(b);
}
inline bool operator==(WindowFlags a, SDL_WindowFlags b) noexcept
{
    return a == static_cast<WindowFlags>(b);
}
inline WindowFlags operator|(WindowFlags a, WindowFlags b) noexcept
{
    return static_cast<WindowFlags>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_WindowEventID
 * 
 * Generated From SDL_video.h:169
 * \sa SDL_WindowEventID
 */
enum class WindowEventID : Uint32 {
    None = SDL_WINDOWEVENT_NONE, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_NONE WindowEventID::None autogenerated
    Shown = SDL_WINDOWEVENT_SHOWN, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_SHOWN WindowEventID::Shown autogenerated
    Hidden = SDL_WINDOWEVENT_HIDDEN, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_HIDDEN WindowEventID::Hidden autogenerated
    Exposed = SDL_WINDOWEVENT_EXPOSED, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_EXPOSED WindowEventID::Exposed autogenerated
    Moved = SDL_WINDOWEVENT_MOVED, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_MOVED WindowEventID::Moved autogenerated
    Resized = SDL_WINDOWEVENT_RESIZED, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_RESIZED WindowEventID::Resized autogenerated
    SizeChanged = SDL_WINDOWEVENT_SIZE_CHANGED, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_SIZE_CHANGED WindowEventID::SizeChanged autogenerated
    Minimized = SDL_WINDOWEVENT_MINIMIZED, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_MINIMIZED WindowEventID::Minimized autogenerated
    Maximized = SDL_WINDOWEVENT_MAXIMIZED, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_MAXIMIZED WindowEventID::Maximized autogenerated
    Restored = SDL_WINDOWEVENT_RESTORED, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_RESTORED WindowEventID::Restored autogenerated
    Enter = SDL_WINDOWEVENT_ENTER, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_ENTER WindowEventID::Enter autogenerated
    Leave = SDL_WINDOWEVENT_LEAVE, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_LEAVE WindowEventID::Leave autogenerated
    FocusGained = SDL_WINDOWEVENT_FOCUS_GAINED, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_FOCUS_GAINED WindowEventID::FocusGained autogenerated
    FocusLost = SDL_WINDOWEVENT_FOCUS_LOST, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_FOCUS_LOST WindowEventID::FocusLost autogenerated
    Close = SDL_WINDOWEVENT_CLOSE, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_CLOSE WindowEventID::Close autogenerated
    TakeFocus = SDL_WINDOWEVENT_TAKE_FOCUS, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_TAKE_FOCUS WindowEventID::TakeFocus autogenerated
    HitTest = SDL_WINDOWEVENT_HIT_TEST, ///< NOLINT \wrapImpl SDL_WINDOWEVENT_HIT_TEST WindowEventID::HitTest autogenerated
};
inline bool operator==(SDL_WindowEventID a, WindowEventID b) noexcept
{
    return a == static_cast<SDL_WindowEventID>(b);
}
inline bool operator==(WindowEventID a, SDL_WindowEventID b) noexcept
{
    return a == static_cast<WindowEventID>(b);
}
inline WindowEventID operator|(WindowEventID a, WindowEventID b) noexcept
{
    return static_cast<WindowEventID>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_DisplayEventID
 * 
 * Generated From SDL_video.h:178
 * \sa SDL_DisplayEventID
 */
enum class DisplayEventID : Uint32 {
    None = SDL_DISPLAYEVENT_NONE, ///< NOLINT \wrapImpl SDL_DISPLAYEVENT_NONE DisplayEventID::None autogenerated
    Orientation = SDL_DISPLAYEVENT_ORIENTATION, ///< NOLINT \wrapImpl SDL_DISPLAYEVENT_ORIENTATION DisplayEventID::Orientation autogenerated
};
inline bool operator==(SDL_DisplayEventID a, DisplayEventID b) noexcept
{
    return a == static_cast<SDL_DisplayEventID>(b);
}
inline bool operator==(DisplayEventID a, SDL_DisplayEventID b) noexcept
{
    return a == static_cast<DisplayEventID>(b);
}
inline DisplayEventID operator|(DisplayEventID a, DisplayEventID b) noexcept
{
    return static_cast<DisplayEventID>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_DisplayOrientation
 * 
 * Generated From SDL_video.h:187
 * \sa SDL_DisplayOrientation
 */
enum class DisplayOrientation : Uint32 {
    Unknown = SDL_ORIENTATION_UNKNOWN, ///< NOLINT \wrapImpl SDL_ORIENTATION_UNKNOWN DisplayOrientation::Unknown autogenerated
    Landscape = SDL_ORIENTATION_LANDSCAPE, ///< NOLINT \wrapImpl SDL_ORIENTATION_LANDSCAPE DisplayOrientation::Landscape autogenerated
    LandscapeFlipped = SDL_ORIENTATION_LANDSCAPE_FLIPPED, ///< NOLINT \wrapImpl SDL_ORIENTATION_LANDSCAPE_FLIPPED DisplayOrientation::LandscapeFlipped autogenerated
    Portrait = SDL_ORIENTATION_PORTRAIT, ///< NOLINT \wrapImpl SDL_ORIENTATION_PORTRAIT DisplayOrientation::Portrait autogenerated
    PortraitFlipped = SDL_ORIENTATION_PORTRAIT_FLIPPED, ///< NOLINT \wrapImpl SDL_ORIENTATION_PORTRAIT_FLIPPED DisplayOrientation::PortraitFlipped autogenerated
};
inline bool operator==(SDL_DisplayOrientation a, DisplayOrientation b) noexcept
{
    return a == static_cast<SDL_DisplayOrientation>(b);
}
inline bool operator==(DisplayOrientation a, SDL_DisplayOrientation b) noexcept
{
    return a == static_cast<DisplayOrientation>(b);
}
inline DisplayOrientation operator|(DisplayOrientation a, DisplayOrientation b) noexcept
{
    return static_cast<DisplayOrientation>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_GLattr
 * 
 * Generated From SDL_video.h:226
 * \sa SDL_GLattr
 */
enum class GLattr : Uint32 {
    RedSize = SDL_GL_RED_SIZE, ///< NOLINT \wrapImpl SDL_GL_RED_SIZE GLattr::RedSize autogenerated
    GreenSize = SDL_GL_GREEN_SIZE, ///< NOLINT \wrapImpl SDL_GL_GREEN_SIZE GLattr::GreenSize autogenerated
    BlueSize = SDL_GL_BLUE_SIZE, ///< NOLINT \wrapImpl SDL_GL_BLUE_SIZE GLattr::BlueSize autogenerated
    AlphaSize = SDL_GL_ALPHA_SIZE, ///< NOLINT \wrapImpl SDL_GL_ALPHA_SIZE GLattr::AlphaSize autogenerated
    BufferSize = SDL_GL_BUFFER_SIZE, ///< NOLINT \wrapImpl SDL_GL_BUFFER_SIZE GLattr::BufferSize autogenerated
    Doublebuffer = SDL_GL_DOUBLEBUFFER, ///< NOLINT \wrapImpl SDL_GL_DOUBLEBUFFER GLattr::Doublebuffer autogenerated
    DepthSize = SDL_GL_DEPTH_SIZE, ///< NOLINT \wrapImpl SDL_GL_DEPTH_SIZE GLattr::DepthSize autogenerated
    StencilSize = SDL_GL_STENCIL_SIZE, ///< NOLINT \wrapImpl SDL_GL_STENCIL_SIZE GLattr::StencilSize autogenerated
    AccumRedSize = SDL_GL_ACCUM_RED_SIZE, ///< NOLINT \wrapImpl SDL_GL_ACCUM_RED_SIZE GLattr::AccumRedSize autogenerated
    AccumGreenSize = SDL_GL_ACCUM_GREEN_SIZE, ///< NOLINT \wrapImpl SDL_GL_ACCUM_GREEN_SIZE GLattr::AccumGreenSize autogenerated
    AccumBlueSize = SDL_GL_ACCUM_BLUE_SIZE, ///< NOLINT \wrapImpl SDL_GL_ACCUM_BLUE_SIZE GLattr::AccumBlueSize autogenerated
    AccumAlphaSize = SDL_GL_ACCUM_ALPHA_SIZE, ///< NOLINT \wrapImpl SDL_GL_ACCUM_ALPHA_SIZE GLattr::AccumAlphaSize autogenerated
    Stereo = SDL_GL_STEREO, ///< NOLINT \wrapImpl SDL_GL_STEREO GLattr::Stereo autogenerated
    Multisamplebuffers = SDL_GL_MULTISAMPLEBUFFERS, ///< NOLINT \wrapImpl SDL_GL_MULTISAMPLEBUFFERS GLattr::Multisamplebuffers autogenerated
    Multisamplesamples = SDL_GL_MULTISAMPLESAMPLES, ///< NOLINT \wrapImpl SDL_GL_MULTISAMPLESAMPLES GLattr::Multisamplesamples autogenerated
    AcceleratedVisual = SDL_GL_ACCELERATED_VISUAL, ///< NOLINT \wrapImpl SDL_GL_ACCELERATED_VISUAL GLattr::AcceleratedVisual autogenerated
    RetainedBacking = SDL_GL_RETAINED_BACKING, ///< NOLINT \wrapImpl SDL_GL_RETAINED_BACKING GLattr::RetainedBacking autogenerated
    ContextMajorVersion = SDL_GL_CONTEXT_MAJOR_VERSION, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_MAJOR_VERSION GLattr::ContextMajorVersion autogenerated
    ContextMinorVersion = SDL_GL_CONTEXT_MINOR_VERSION, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_MINOR_VERSION GLattr::ContextMinorVersion autogenerated
    ContextEgl = SDL_GL_CONTEXT_EGL, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_EGL GLattr::ContextEgl autogenerated
    ContextFlags = SDL_GL_CONTEXT_FLAGS, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_FLAGS GLattr::ContextFlags autogenerated
    ContextProfileMask = SDL_GL_CONTEXT_PROFILE_MASK, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_PROFILE_MASK GLattr::ContextProfileMask autogenerated
    ShareWithCurrentContext = SDL_GL_SHARE_WITH_CURRENT_CONTEXT, ///< NOLINT \wrapImpl SDL_GL_SHARE_WITH_CURRENT_CONTEXT GLattr::ShareWithCurrentContext autogenerated
    FramebufferSrgbCapable = SDL_GL_FRAMEBUFFER_SRGB_CAPABLE, ///< NOLINT \wrapImpl SDL_GL_FRAMEBUFFER_SRGB_CAPABLE GLattr::FramebufferSrgbCapable autogenerated
    ContextReleaseBehavior = SDL_GL_CONTEXT_RELEASE_BEHAVIOR, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_RELEASE_BEHAVIOR GLattr::ContextReleaseBehavior autogenerated
    ContextResetNotification = SDL_GL_CONTEXT_RESET_NOTIFICATION, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_RESET_NOTIFICATION GLattr::ContextResetNotification autogenerated
    ContextNoError = SDL_GL_CONTEXT_NO_ERROR, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_NO_ERROR GLattr::ContextNoError autogenerated
};
inline bool operator==(SDL_GLattr a, GLattr b) noexcept
{
    return a == static_cast<SDL_GLattr>(b);
}
inline bool operator==(GLattr a, SDL_GLattr b) noexcept
{
    return a == static_cast<GLattr>(b);
}
inline GLattr operator|(GLattr a, GLattr b) noexcept
{
    return static_cast<GLattr>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_GLprofile
 * 
 * Generated From SDL_video.h:233
 * \sa SDL_GLprofile
 */
enum class GLprofile : Uint32 {
    ContextProfileCore = SDL_GL_CONTEXT_PROFILE_CORE, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_PROFILE_CORE GLprofile::ContextProfileCore autogenerated
    ContextProfileCompatibility = SDL_GL_CONTEXT_PROFILE_COMPATIBILITY, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_PROFILE_COMPATIBILITY GLprofile::ContextProfileCompatibility autogenerated
    ContextProfileEs = SDL_GL_CONTEXT_PROFILE_ES, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_PROFILE_ES GLprofile::ContextProfileEs autogenerated
};
inline bool operator==(SDL_GLprofile a, GLprofile b) noexcept
{
    return a == static_cast<SDL_GLprofile>(b);
}
inline bool operator==(GLprofile a, SDL_GLprofile b) noexcept
{
    return a == static_cast<GLprofile>(b);
}
inline GLprofile operator|(GLprofile a, GLprofile b) noexcept
{
    return static_cast<GLprofile>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_GLcontextFlag
 * 
 * Generated From SDL_video.h:241
 * \sa SDL_GLcontextFlag
 */
enum class GLcontextFlag : Uint32 {
    ContextDebugFlag = SDL_GL_CONTEXT_DEBUG_FLAG, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_DEBUG_FLAG GLcontextFlag::ContextDebugFlag autogenerated
    ContextForwardCompatibleFlag = SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG GLcontextFlag::ContextForwardCompatibleFlag autogenerated
    ContextRobustAccessFlag = SDL_GL_CONTEXT_ROBUST_ACCESS_FLAG, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_ROBUST_ACCESS_FLAG GLcontextFlag::ContextRobustAccessFlag autogenerated
    ContextResetIsolationFlag = SDL_GL_CONTEXT_RESET_ISOLATION_FLAG, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_RESET_ISOLATION_FLAG GLcontextFlag::ContextResetIsolationFlag autogenerated
};
inline bool operator==(SDL_GLcontextFlag a, GLcontextFlag b) noexcept
{
    return a == static_cast<SDL_GLcontextFlag>(b);
}
inline bool operator==(GLcontextFlag a, SDL_GLcontextFlag b) noexcept
{
    return a == static_cast<GLcontextFlag>(b);
}
inline GLcontextFlag operator|(GLcontextFlag a, GLcontextFlag b) noexcept
{
    return static_cast<GLcontextFlag>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_GLcontextReleaseFlag
 * 
 * Generated From SDL_video.h:247
 * \sa SDL_GLcontextReleaseFlag
 */
enum class GLcontextReleaseFlag : Uint32 {
    ContextReleaseBehaviorNone = SDL_GL_CONTEXT_RELEASE_BEHAVIOR_NONE, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_RELEASE_BEHAVIOR_NONE GLcontextReleaseFlag::ContextReleaseBehaviorNone autogenerated
    ContextReleaseBehaviorFlush = SDL_GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH GLcontextReleaseFlag::ContextReleaseBehaviorFlush autogenerated
};
inline bool operator==(SDL_GLcontextReleaseFlag a, GLcontextReleaseFlag b) noexcept
{
    return a == static_cast<SDL_GLcontextReleaseFlag>(b);
}
inline bool operator==(GLcontextReleaseFlag a, SDL_GLcontextReleaseFlag b) noexcept
{
    return a == static_cast<GLcontextReleaseFlag>(b);
}
inline GLcontextReleaseFlag operator|(GLcontextReleaseFlag a, GLcontextReleaseFlag b) noexcept
{
    return static_cast<GLcontextReleaseFlag>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_GLContextResetNotification
 * 
 * Generated From SDL_video.h:253
 * \sa SDL_GLContextResetNotification
 */
enum class GLContextResetNotification : Uint32 {
    ContextResetNoNotification = SDL_GL_CONTEXT_RESET_NO_NOTIFICATION, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_RESET_NO_NOTIFICATION GLContextResetNotification::ContextResetNoNotification autogenerated
    ContextResetLoseContext = SDL_GL_CONTEXT_RESET_LOSE_CONTEXT, ///< NOLINT \wrapImpl SDL_GL_CONTEXT_RESET_LOSE_CONTEXT GLContextResetNotification::ContextResetLoseContext autogenerated
};
inline bool operator==(SDL_GLContextResetNotification a, GLContextResetNotification b) noexcept
{
    return a == static_cast<SDL_GLContextResetNotification>(b);
}
inline bool operator==(GLContextResetNotification a, SDL_GLContextResetNotification b) noexcept
{
    return a == static_cast<GLContextResetNotification>(b);
}
inline GLContextResetNotification operator|(GLContextResetNotification a, GLContextResetNotification b) noexcept
{
    return static_cast<GLContextResetNotification>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

/**
 * \brief Scoped version of SDL_HitTestResult
 * 
 * Generated From SDL_video.h:1031
 * \sa SDL_HitTestResult
 */
enum class HitTestResult : Uint32 {
    Normal = SDL_HITTEST_NORMAL, ///< NOLINT \wrapImpl SDL_HITTEST_NORMAL HitTestResult::Normal autogenerated
    Draggable = SDL_HITTEST_DRAGGABLE, ///< NOLINT \wrapImpl SDL_HITTEST_DRAGGABLE HitTestResult::Draggable autogenerated
    ResizeTopleft = SDL_HITTEST_RESIZE_TOPLEFT, ///< NOLINT \wrapImpl SDL_HITTEST_RESIZE_TOPLEFT HitTestResult::ResizeTopleft autogenerated
    ResizeTop = SDL_HITTEST_RESIZE_TOP, ///< NOLINT \wrapImpl SDL_HITTEST_RESIZE_TOP HitTestResult::ResizeTop autogenerated
    ResizeTopright = SDL_HITTEST_RESIZE_TOPRIGHT, ///< NOLINT \wrapImpl SDL_HITTEST_RESIZE_TOPRIGHT HitTestResult::ResizeTopright autogenerated
    ResizeRight = SDL_HITTEST_RESIZE_RIGHT, ///< NOLINT \wrapImpl SDL_HITTEST_RESIZE_RIGHT HitTestResult::ResizeRight autogenerated
    ResizeBottomright = SDL_HITTEST_RESIZE_BOTTOMRIGHT, ///< NOLINT \wrapImpl SDL_HITTEST_RESIZE_BOTTOMRIGHT HitTestResult::ResizeBottomright autogenerated
    ResizeBottom = SDL_HITTEST_RESIZE_BOTTOM, ///< NOLINT \wrapImpl SDL_HITTEST_RESIZE_BOTTOM HitTestResult::ResizeBottom autogenerated
    ResizeBottomleft = SDL_HITTEST_RESIZE_BOTTOMLEFT, ///< NOLINT \wrapImpl SDL_HITTEST_RESIZE_BOTTOMLEFT HitTestResult::ResizeBottomleft autogenerated
    ResizeLeft = SDL_HITTEST_RESIZE_LEFT, ///< NOLINT \wrapImpl SDL_HITTEST_RESIZE_LEFT HitTestResult::ResizeLeft autogenerated
};
inline bool operator==(SDL_HitTestResult a, HitTestResult b) noexcept
{
    return a == static_cast<SDL_HitTestResult>(b);
}
inline bool operator==(HitTestResult a, SDL_HitTestResult b) noexcept
{
    return a == static_cast<HitTestResult>(b);
}
inline HitTestResult operator|(HitTestResult a, HitTestResult b) noexcept
{
    return static_cast<HitTestResult>(static_cast<Uint32>(a) | static_cast<Uint32>(b));
}

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
