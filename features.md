For the category split up used here, see https://wiki.libsdl.org/APIByCategory
#### Basics
    
##### Initialization and Shutdown
aka SDL.h

| SDL Function | Implemented? | Where | Notes |
|--------------|--------------|-------|-------|
| SDL_Init | yes | SDL2::init | |
|SDL_InitSubSystem | no
|SDL_Quit | yes | ~SDL2 ||
|SDL_QuitSubSystem | no
|SDL_SetMainReady | no
|SDL_WasInit | no
|SDL_WinRTRunApp | no
##### Configuration Variables
aka SDL_hints.h

| SDL Function | Implemented? | Where | Notes |
|--------------|--------------|-------|-------|
|SDL_AddHintCallback | no
|SDL_ClearHints | no
|SDL_DelHintCallback | no
|SDL_GetHint | no
|SDL_GetHintBoolean | no
|SDL_SetHint | no
|SDL_SetHintWithPriority | no
##### Error Handling
aka SDL_error.h

| SDL Function | Implemented? | Where | Notes |
|--------------|--------------|-------|-------|
|SDL_ClearError | no
|SDL_GetError | no
|SDL_SetError | no
##### Log Handling
aka SDL_log.h

| SDL Function | Implemented? | Where | Notes |
|--------------|--------------|-------|-------|
|SDL_Log | no
|SDL_LogCritical | no
|SDL_LogDebug | no
|SDL_LogError | no
|SDL_LogGetOutputFunction | no
|SDL_LogGetPriority | no
|SDL_LogInfo | no
|SDL_LogMessage | no
|SDL_LogMessageV | no
|SDL_LogResetPriorities | no
|SDL_LogSetAllPriority | no
||SDL_LogSetOutputFunction | no
|SDL_LogSetPriority | no
|SDL_LogVerbose | no
|SDL_LogWarn | no
##### Assertions
aka SDL_assert.h

| SDL Function | Implemented? | Where | Notes |
|--------------|--------------|-------|-------|
|SDL_GetAssertionHandler | no
|SDL_GetAssertionReport | no
|SDL_GetDefaultAssertionHandler | no
|SDL_ResetAssertionReport | no
|SDL_SetAssertionHandler | no
|SDL_TriggerBreakpoint | no
|SDL_assert | yes | SDL2WRAP_ASSERT | uses custom assert on release build and always asserts 
|SDL_assert_paranoid | skipped | | redundant due to how SDL2WRAP_ASSERT works; use directly if needed
|SDL_assert_release | skipped | | redundant due to how SDL2WRAP_ASSERT works; use directly if needed
##### Querying SDL Version
aka SDL_version.h

| SDL Function | Implemented? | Where | Notes |
|--------------|--------------|-------|-------|
|SDL_COMPILEDVERSION | no
|SDL_GetRevision | no
|SDL_GetRevisionNumber | no
|SDL_GetVersion | no
|SDL_REVISION | no
|SDL_VERSION | no
|SDL_VERSIONNUM | no
|SDL_VERSION_ATLEAST | no

#### Video
##### Display and Window Management
##### 2D Accelerated Rendering
##### Pixel Formats and Conversion Routines
##### Rectangle Functions
##### Surface Creation and Simple Drawing
##### Platform-specific Window Management
##### Clipboard Handling
##### Vulkan Support
#### Input Events
##### Event Handling
##### Keyboard Support
##### Mouse Support
##### Joystick Support
##### Game Controller Support
##### Sensors
#### Force Feedback
##### Force Feedback Support
#### Audio
##### Audio Device Management, Playing and Recording
#### Threads 	
##### Thread Management
##### Thread Synchronization Primitives
##### Atomic Operations
#### Timers
##### Timer Support
#### File Abstraction
##### Filesystem Paths
##### File I/O Abstraction
#### Shared Object Support
##### Shared Object Loading and Function Lookup