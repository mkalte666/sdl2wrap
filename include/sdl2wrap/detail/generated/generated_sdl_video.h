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
 * Generated From SDL_video.h:122
 */
enum class WindowFlags {
    WindowFullscreen = SDL_WINDOW_FULLSCREEN,
    WindowOpengl = SDL_WINDOW_OPENGL,
    WindowShown = SDL_WINDOW_SHOWN,
    WindowHidden = SDL_WINDOW_HIDDEN,
    WindowBorderless = SDL_WINDOW_BORDERLESS,
    WindowResizable = SDL_WINDOW_RESIZABLE,
    WindowMinimized = SDL_WINDOW_MINIMIZED,
    WindowMaximized = SDL_WINDOW_MAXIMIZED,
    WindowInputGrabbed = SDL_WINDOW_INPUT_GRABBED,
    WindowInputFocus = SDL_WINDOW_INPUT_FOCUS,
    WindowMouseFocus = SDL_WINDOW_MOUSE_FOCUS,
    WindowFullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
    WindowForeign = SDL_WINDOW_FOREIGN,
    WindowAllowHighdpi = SDL_WINDOW_ALLOW_HIGHDPI,
    WindowMouseCapture = SDL_WINDOW_MOUSE_CAPTURE,
    WindowAlwaysOnTop = SDL_WINDOW_ALWAYS_ON_TOP,
    WindowSkipTaskbar = SDL_WINDOW_SKIP_TASKBAR,
    WindowUtility = SDL_WINDOW_UTILITY,
    WindowTooltip = SDL_WINDOW_TOOLTIP,
    WindowPopupMenu = SDL_WINDOW_POPUP_MENU,
    WindowVulkan = SDL_WINDOW_VULKAN,
};

/**
 * \brief Scoped version of SDL_WindowEventID
 * Generated From SDL_video.h:169
 */
enum class WindowEventID {
    WindoweventNone = SDL_WINDOWEVENT_NONE,
    WindoweventShown = SDL_WINDOWEVENT_SHOWN,
    WindoweventHidden = SDL_WINDOWEVENT_HIDDEN,
    WindoweventExposed = SDL_WINDOWEVENT_EXPOSED,
    WindoweventMoved = SDL_WINDOWEVENT_MOVED,
    WindoweventResized = SDL_WINDOWEVENT_RESIZED,
    WindoweventSizeChanged = SDL_WINDOWEVENT_SIZE_CHANGED,
    WindoweventMinimized = SDL_WINDOWEVENT_MINIMIZED,
    WindoweventMaximized = SDL_WINDOWEVENT_MAXIMIZED,
    WindoweventRestored = SDL_WINDOWEVENT_RESTORED,
    WindoweventEnter = SDL_WINDOWEVENT_ENTER,
    WindoweventLeave = SDL_WINDOWEVENT_LEAVE,
    WindoweventFocusGained = SDL_WINDOWEVENT_FOCUS_GAINED,
    WindoweventFocusLost = SDL_WINDOWEVENT_FOCUS_LOST,
    WindoweventClose = SDL_WINDOWEVENT_CLOSE,
    WindoweventTakeFocus = SDL_WINDOWEVENT_TAKE_FOCUS,
    WindoweventHitTest = SDL_WINDOWEVENT_HIT_TEST,
};

/**
 * \brief Scoped version of SDL_DisplayEventID
 * Generated From SDL_video.h:178
 */
enum class DisplayEventID {
    DisplayeventNone = SDL_DISPLAYEVENT_NONE,
    DisplayeventOrientation = SDL_DISPLAYEVENT_ORIENTATION,
};

/**
 * \brief Scoped version of SDL_DisplayOrientation
 * Generated From SDL_video.h:187
 */
enum class DisplayOrientation {
    OrientationUnknown = SDL_ORIENTATION_UNKNOWN,
    OrientationLandscape = SDL_ORIENTATION_LANDSCAPE,
    OrientationLandscapeFlipped = SDL_ORIENTATION_LANDSCAPE_FLIPPED,
    OrientationPortrait = SDL_ORIENTATION_PORTRAIT,
    OrientationPortraitFlipped = SDL_ORIENTATION_PORTRAIT_FLIPPED,
};

/**
 * \brief Scoped version of SDL_GLattr
 * Generated From SDL_video.h:226
 */
enum class GLattr {
    GlRedSize = SDL_GL_RED_SIZE,
    GlGreenSize = SDL_GL_GREEN_SIZE,
    GlBlueSize = SDL_GL_BLUE_SIZE,
    GlAlphaSize = SDL_GL_ALPHA_SIZE,
    GlBufferSize = SDL_GL_BUFFER_SIZE,
    GlDoublebuffer = SDL_GL_DOUBLEBUFFER,
    GlDepthSize = SDL_GL_DEPTH_SIZE,
    GlStencilSize = SDL_GL_STENCIL_SIZE,
    GlAccumRedSize = SDL_GL_ACCUM_RED_SIZE,
    GlAccumGreenSize = SDL_GL_ACCUM_GREEN_SIZE,
    GlAccumBlueSize = SDL_GL_ACCUM_BLUE_SIZE,
    GlAccumAlphaSize = SDL_GL_ACCUM_ALPHA_SIZE,
    GlStereo = SDL_GL_STEREO,
    GlMultisamplebuffers = SDL_GL_MULTISAMPLEBUFFERS,
    GlMultisamplesamples = SDL_GL_MULTISAMPLESAMPLES,
    GlAcceleratedVisual = SDL_GL_ACCELERATED_VISUAL,
    GlRetainedBacking = SDL_GL_RETAINED_BACKING,
    GlContextMajorVersion = SDL_GL_CONTEXT_MAJOR_VERSION,
    GlContextMinorVersion = SDL_GL_CONTEXT_MINOR_VERSION,
    GlContextEgl = SDL_GL_CONTEXT_EGL,
    GlContextFlags = SDL_GL_CONTEXT_FLAGS,
    GlContextProfileMask = SDL_GL_CONTEXT_PROFILE_MASK,
    GlShareWithCurrentContext = SDL_GL_SHARE_WITH_CURRENT_CONTEXT,
    GlFramebufferSrgbCapable = SDL_GL_FRAMEBUFFER_SRGB_CAPABLE,
    GlContextReleaseBehavior = SDL_GL_CONTEXT_RELEASE_BEHAVIOR,
    GlContextResetNotification = SDL_GL_CONTEXT_RESET_NOTIFICATION,
    GlContextNoError = SDL_GL_CONTEXT_NO_ERROR,
};

/**
 * \brief Scoped version of SDL_GLprofile
 * Generated From SDL_video.h:233
 */
enum class GLprofile {
    GlContextProfileCore = SDL_GL_CONTEXT_PROFILE_CORE,
    GlContextProfileCompatibility = SDL_GL_CONTEXT_PROFILE_COMPATIBILITY,
    GlContextProfileEs = SDL_GL_CONTEXT_PROFILE_ES,
};

/**
 * \brief Scoped version of SDL_GLcontextFlag
 * Generated From SDL_video.h:241
 */
enum class GLcontextFlag {
    GlContextDebugFlag = SDL_GL_CONTEXT_DEBUG_FLAG,
    GlContextForwardCompatibleFlag = SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG,
    GlContextRobustAccessFlag = SDL_GL_CONTEXT_ROBUST_ACCESS_FLAG,
    GlContextResetIsolationFlag = SDL_GL_CONTEXT_RESET_ISOLATION_FLAG,
};

/**
 * \brief Scoped version of SDL_GLcontextReleaseFlag
 * Generated From SDL_video.h:247
 */
enum class GLcontextReleaseFlag {
    GlContextReleaseBehaviorNone = SDL_GL_CONTEXT_RELEASE_BEHAVIOR_NONE,
    GlContextReleaseBehaviorFlush = SDL_GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH,
};

/**
 * \brief Scoped version of SDL_GLContextResetNotification
 * Generated From SDL_video.h:253
 */
enum class GLContextResetNotification {
    GlContextResetNoNotification = SDL_GL_CONTEXT_RESET_NO_NOTIFICATION,
    GlContextResetLoseContext = SDL_GL_CONTEXT_RESET_LOSE_CONTEXT,
};

/**
 * \brief Scoped version of SDL_HitTestResult
 * Generated From SDL_video.h:1031
 */
enum class HitTestResult {
    HittestNormal = SDL_HITTEST_NORMAL,
    HittestDraggable = SDL_HITTEST_DRAGGABLE,
    HittestResizeTopleft = SDL_HITTEST_RESIZE_TOPLEFT,
    HittestResizeTop = SDL_HITTEST_RESIZE_TOP,
    HittestResizeTopright = SDL_HITTEST_RESIZE_TOPRIGHT,
    HittestResizeRight = SDL_HITTEST_RESIZE_RIGHT,
    HittestResizeBottomright = SDL_HITTEST_RESIZE_BOTTOMRIGHT,
    HittestResizeBottom = SDL_HITTEST_RESIZE_BOTTOM,
    HittestResizeBottomleft = SDL_HITTEST_RESIZE_BOTTOMLEFT,
    HittestResizeLeft = SDL_HITTEST_RESIZE_LEFT,
};

}; // namespace sdl2wrap

#endif // sdl2wrap_generated_*
