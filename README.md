# SDL2 C++ Wrapper
![Build](https://github.com/mkalte666/sdl2wrap/workflows/Build/badge.svg)


sdl2wrap is a c++17 wrapper around SDL2 (https://www.libsdl.org/)

### Design Goals
I created this to be used in personal projects. 
 * Exception-free error handling
 * Typesafe wrapping of flags, sdl types, ...
 * C++ features (RAII, class-based ownership modeling for pointer types, ...)
 * Do not use the stl. 
 
### Completion
Completion is work in progress. 
see [features.md](features.md) 

### Naming Policy 
 * Everything lives in the sdl2wrap namespace
 * defines are prefixed with SDL2WRAP_
 * General Workflow for types and functions
     * Strip Prefix, and un-capitalise functions `SDL_VideoInit` =>  `videoInit`
     * Strip Subsytem-Identifier from name if present `SDL_VideoInit` => `Video::init`
     * Put into Subsystem Namespace `SDL_VideoInit` => `Video::videoInit`
        * Put into further Sub-Namespace if still prefixed `SDL_GL_*` => `GL::*`
     * Put into class if (first) parameter is a type activly wrapped 
       and strip that type from the name `SDL_SetSurfaceColorMod` =>  `Video::Surface::setColorMod`
 

### Function signature policy
 * Create/Alloc/... Function? => TypeWrapper inside a Result instead
 * void function with only const/copy args => keep
 * return-code function with only const/copy args => EmptyResult instead
   (This includes quite a few setters!)
 * getter function with value type return => keep 
 * getter function with ptr type return => Result<ptrType> instead 
 * return-code Getter function with single argument to get => Result<getType> instead
 * return-code Getter function with multiple arguments => EmptyResult instead
 
The rule for returned pointers is ignored when the pointer is treated as a value.
As in, when the value 
 * is guaranteed by sdl to be something (const char* mostly)
 * not null or there is no sdl error set when the return is null. (Window data, a void*, to give an example)
