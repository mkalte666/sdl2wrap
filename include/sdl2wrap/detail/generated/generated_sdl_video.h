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
    Fullscreen = SDL_WINDOW_FULLSCREEN,
    Opengl = SDL_WINDOW_OPENGL,
    Shown = SDL_WINDOW_SHOWN,
    Hidden = SDL_WINDOW_HIDDEN,
    Borderless = SDL_WINDOW_BORDERLESS,
    Resizable = SDL_WINDOW_RESIZABLE,
    Minimized = SDL_WINDOW_MINIMIZED,
    Maximized = SDL_WINDOW_MAXIMIZED,
    InputGrabbed = SDL_WINDOW_INPUT_GRABBED,
    InputFocus = SDL_WINDOW_INPUT_FOCUS,
    MouseFocus = SDL_WINDOW_MOUSE_FOCUS,
    FullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
    Foreign = SDL_WINDOW_FOREIGN,
    AllowHighdpi = SDL_WINDOW_ALLOW_HIGHDPI,
    MouseCapture = SDL_WINDOW_MOUSE_CAPTURE,
    AlwaysOnTop = SDL_WINDOW_ALWAYS_ON_TOP,
    SkipTaskbar = SDL_WINDOW_SKIP_TASKBAR,
    Utility = SDL_WINDOW_UTILITY,
    Tooltip = SDL_WINDOW_TOOLTIP,
    PopupMenu = SDL_WINDOW_POPUP_MENU,
    Vulkan = SDL_WINDOW_VULKAN,
};

/**
 * \brief Scoped version of SDL_WindowEventID
 * 
 * Generated From SDL_video.h:169
 * \sa SDL_WindowEventID
 */
enum class WindowEventID : Uint32 {
    None = SDL_WINDOWEVENT_NONE,
    Shown = SDL_WINDOWEVENT_SHOWN,
    Hidden = SDL_WINDOWEVENT_HIDDEN,
    Exposed = SDL_WINDOWEVENT_EXPOSED,
    Moved = SDL_WINDOWEVENT_MOVED,
    Resized = SDL_WINDOWEVENT_RESIZED,
    SizeChanged = SDL_WINDOWEVENT_SIZE_CHANGED,
    Minimized = SDL_WINDOWEVENT_MINIMIZED,
    Maximized = SDL_WINDOWEVENT_MAXIMIZED,
    Restored = SDL_WINDOWEVENT_RESTORED,
    Enter = SDL_WINDOWEVENT_ENTER,
    Leave = SDL_WINDOWEVENT_LEAVE,
    FocusGained = SDL_WINDOWEVENT_FOCUS_GAINED,
    FocusLost = SDL_WINDOWEVENT_FOCUS_LOST,
    Close = SDL_WINDOWEVENT_CLOSE,
    TakeFocus = SDL_WINDOWEVENT_TAKE_FOCUS,
    HitTest = SDL_WINDOWEVENT_HIT_TEST,
};

/**
 * \brief Scoped version of SDL_DisplayEventID
 * 
 * Generated From SDL_video.h:178
 * \sa SDL_DisplayEventID
 */
enum class DisplayEventID : Uint32 {
    None = SDL_DISPLAYEVENT_NONE,
    Orientation = SDL_DISPLAYEVENT_ORIENTATION,
};

/**
 * \brief Scoped version of SDL_DisplayOrientation
 * 
 * Generated From SDL_video.h:187
 * \sa SDL_DisplayOrientation
 */
enum class DisplayOrientation : Uint32 {
    Unknown = SDL_ORIENTATION_UNKNOWN,
    Landscape = SDL_ORIENTATION_LANDSCAPE,
    LandscapeFlipped = SDL_ORIENTATION_LANDSCAPE_FLIPPED,
    Portrait = SDL_ORIENTATION_PORTRAIT,
    PortraitFlipped = SDL_ORIENTATION_PORTRAIT_FLIPPED,
};

/**
 * \brief Scoped version of SDL_GLattr
 * 
 * Generated From SDL_video.h:226
 * \sa SDL_GLattr
 */
enum class GLattr : Uint32 {
    RedSize = SDL_GL_RED_SIZE,
    GreenSize = SDL_GL_GREEN_SIZE,
    BlueSize = SDL_GL_BLUE_SIZE,
    AlphaSize = SDL_GL_ALPHA_SIZE,
    BufferSize = SDL_GL_BUFFER_SIZE,
    Doublebuffer = SDL_GL_DOUBLEBUFFER,
    DepthSize = SDL_GL_DEPTH_SIZE,
    StencilSize = SDL_GL_STENCIL_SIZE,
    AccumRedSize = SDL_GL_ACCUM_RED_SIZE,
    AccumGreenSize = SDL_GL_ACCUM_GREEN_SIZE,
    AccumBlueSize = SDL_GL_ACCUM_BLUE_SIZE,
    AccumAlphaSize = SDL_GL_ACCUM_ALPHA_SIZE,
    Stereo = SDL_GL_STEREO,
    Multisamplebuffers = SDL_GL_MULTISAMPLEBUFFERS,
    Multisamplesamples = SDL_GL_MULTISAMPLESAMPLES,
    AcceleratedVisual = SDL_GL_ACCELERATED_VISUAL,
    RetainedBacking = SDL_GL_RETAINED_BACKING,
    ContextMajorVersion = SDL_GL_CONTEXT_MAJOR_VERSION,
    ContextMinorVersion = SDL_GL_CONTEXT_MINOR_VERSION,
    ContextEgl = SDL_GL_CONTEXT_EGL,
    ContextFlags = SDL_GL_CONTEXT_FLAGS,
    ContextProfileMask = SDL_GL_CONTEXT_PROFILE_MASK,
    ShareWithCurrentContext = SDL_GL_SHARE_WITH_CURRENT_CONTEXT,
    FramebufferSrgbCapable = SDL_GL_FRAMEBUFFER_SRGB_CAPABLE,
    ContextReleaseBehavior = SDL_GL_CONTEXT_RELEASE_BEHAVIOR,
    ContextResetNotification = SDL_GL_CONTEXT_RESET_NOTIFICATION,
    ContextNoError = SDL_GL_CONTEXT_NO_ERROR,
};

/**
 * \brief Scoped version of SDL_GLprofile
 * 
 * Generated From SDL_video.h:233
 * \sa SDL_GLprofile
 */
enum class GLprofile : Uint32 {
    ContextProfileCore = SDL_GL_CONTEXT_PROFILE_CORE,
    ContextProfileCompatibility = SDL_GL_CONTEXT_PROFILE_COMPATIBILITY,
    ContextProfileEs = SDL_GL_CONTEXT_PROFILE_ES,
};

/**
 * \brief Scoped version of SDL_GLcontextFlag
 * 
 * Generated From SDL_video.h:241
 * \sa SDL_GLcontextFlag
 */
enum class GLcontextFlag : Uint32 {
    ContextDebugFlag = SDL_GL_CONTEXT_DEBUG_FLAG,
    ContextForwardCompatibleFlag = SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG,
    ContextRobustAccessFlag = SDL_GL_CONTEXT_ROBUST_ACCESS_FLAG,
    ContextResetIsolationFlag = SDL_GL_CONTEXT_RESET_ISOLATION_FLAG,
};

/**
 * \brief Scoped version of SDL_GLcontextReleaseFlag
 * 
 * Generated From SDL_video.h:247
 * \sa SDL_GLcontextReleaseFlag
 */
enum class GLcontextReleaseFlag : Uint32 {
    ContextReleaseBehaviorNone = SDL_GL_CONTEXT_RELEASE_BEHAVIOR_NONE,
    ContextReleaseBehaviorFlush = SDL_GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH,
};

/**
 * \brief Scoped version of SDL_GLContextResetNotification
 * 
 * Generated From SDL_video.h:253
 * \sa SDL_GLContextResetNotification
 */
enum class GLContextResetNotification : Uint32 {
    ContextResetNoNotification = SDL_GL_CONTEXT_RESET_NO_NOTIFICATION,
    ContextResetLoseContext = SDL_GL_CONTEXT_RESET_LOSE_CONTEXT,
};

/**
 * \brief Scoped version of SDL_HitTestResult
 * 
 * Generated From SDL_video.h:1031
 * \sa SDL_HitTestResult
 */
enum class HitTestResult : Uint32 {
    Normal = SDL_HITTEST_NORMAL,
    Draggable = SDL_HITTEST_DRAGGABLE,
    ResizeTopleft = SDL_HITTEST_RESIZE_TOPLEFT,
    ResizeTop = SDL_HITTEST_RESIZE_TOP,
    ResizeTopright = SDL_HITTEST_RESIZE_TOPRIGHT,
    ResizeRight = SDL_HITTEST_RESIZE_RIGHT,
    ResizeBottomright = SDL_HITTEST_RESIZE_BOTTOMRIGHT,
    ResizeBottom = SDL_HITTEST_RESIZE_BOTTOM,
    ResizeBottomleft = SDL_HITTEST_RESIZE_BOTTOMLEFT,
    ResizeLeft = SDL_HITTEST_RESIZE_LEFT,
};

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
