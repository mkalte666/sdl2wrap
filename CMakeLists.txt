# SDL2 C++ Wrapper
# Copyright (c) 2020 Malte Kießling
#
# This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not
#   claim that you wrote the original software. If you use this software
#   in a product, an acknowledgment in the product documentation would be
#   appreciated but is not required.
# 2. Altered source versions must be plainly marked as such, and must not be
#   misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.

# cmake version and paths
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# functions stolen from mkalte666/cpputils
include(cmake/funcEnableStrictOptions.cmake)
include(cmake/funcEnableClangTidy.cmake)

# disable in-source build. found at
# https://stackoverflow.com/questions/1208681/with-cmake-how-would-you-disable-
# in-source-builds
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# development settings
option(buildExamples "Enable build of the example programs under src/examples" OFF)
option(buildEnableClangTidy "Enable clang tidy target to check" OFF)

# enable clang tidy before everything else if wanted
if (buildEnableClangTidy)
    enableClangTidy()
endif()
# other settings
# sdl_image and consorts go here

# includes for the sdl2 target
set(sdl2wrapSDL2Includes
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2wrap/detail/base.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2wrap/detail/generated_hints.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2wrap/detail/result.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2wrap/detail/typewrapper.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2wrap/assert.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2wrap/hints.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2wrap/log.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2wrap/sdl2.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2wrap/sdl2stl.h)

# includes for the sdl2image target
# includes for the sdl2mixer target
# includes for the sdl2net target
# includes for the sdl2ttf target


# project
set(CMAKE_CXX_STANDARD 11)
project(sdl2wrap C CXX)

# the core sdl project
find_package(SDL2 REQUIRED)
add_library(sdl2wrap_sdl2 INTERFACE)
target_include_directories(sdl2wrap_sdl2 INTERFACE include/)
target_link_libraries(sdl2wrap_sdl2 INTERFACE SDL2::SDL2 SDL2::SDL2main)
target_sources(sdl2wrap_sdl2 INTERFACE ${sdl2wrapSDL2Includes})
add_library(sdl2wrap::sdl2 ALIAS sdl2wrap_sdl2)

# everything also gets a target
add_library(sdl2wrap_everything INTERFACE)
target_link_libraries(sdl2wrap_everything INTERFACE sdl2wrap_sdl2)
add_library(sdl2wrap::everything ALIAS sdl2wrap_everything)

# examples enabled? add them!
if (buildExamples)
    add_subdirectory(src/examples)
endif()