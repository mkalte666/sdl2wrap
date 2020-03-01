# SDL2 C++ Wrapper Examples Copyright (c) 2020 Malte Kießling
#
# This software is provided 'as-is', without any express or implied warranty. In
# no event will the authors be held liable for any damages arising from the use
# of this software.
#
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it freely,
# subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not claim
#    that you wrote the original software. If you use this software in a product,
#    an acknowledgment in the product documentation would be appreciated but is
#    not required.
# 2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.

# Testing in the classic sense is kinda hard against SDL What can be done
# however is that certain functionality can be tested by just using it So here
# be examples

# this target is only for linting. It includes everything, uses everything, and
# really only builds when clang-tidy allows it
macro(createExample targetName)
  add_executable(${targetName} ${ARGN})
  target_link_libraries(${targetName} PRIVATE sdl2wrap::everything)
  enablestrictoptions(${targetName})
endmacro()

# this one is a bit special, just leave it
createexample(lint lint/lint.cpp)

# init examples
createexample(init init/init.cpp)

# video example
createexample(video video/video.cpp)

# static linking example
createexample(staticlink static/sharedheader.h static/dosomethings.cpp
              static/dosomeotherthings.cpp static/static.cpp)

# a mini test game to see if things work
createexample(
  testgame
  testgame/objects.h
  testgame/static.cpp
  testgame/shared.h
  testgame/testgame.cpp
  testgame/world.cpp
  testgame/world.h)
