# funcForceStrictOptions.cmake
#
# Copyright (C) 2020  Malte Kießling
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or any later version.

# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.

# You should have received a copy of the GNU General Public License along with
# this program.  If not, see <https://www.gnu.org/licenses/>.

function(enableClangTidy)
  find_program(ctidy clang-tidy)
  if(ctidy)
    message(STATUS "Clang tidy found at ${ctidy}")
    set(CMAKE_CXX_CLANG_TIDY
        ${ctidy} --config=
        PARENT_SCOPE)
    message(STATUS ${CMAKE_CXX_CLANG_TIDY})
  else()
    message(WARNING "Clang tidy not found!")
  endif()
endfunction()
