# SDL2 C++ Wrapper
sdl2wrap is a c++17 wrapper around SDL2 (https://www.libsdl.org/)

### Design Goals
I created this to be used in personal projects. 
 * Exception-free error handling
 * Typesafe wrapping of flags, sdl types, ...
 * C++ features (RAII, class-based ownership modeling for pointer types, ...)
 * Do not use the stl. 
 
### Completion
Completion is work in progress. 
For the category split up used here, see https://wiki.libsdl.org/APIByCategory
#### Basics
##### Initialization and Shutdown
##### Configuration Variables
##### Error Handling
##### Log Handling
##### Assertions
##### Querying SDL Version
#### Basics
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