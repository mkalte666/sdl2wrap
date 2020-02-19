#!/bin/env python3
import sys
import os
from enumParser import *
from defineParser import *

if len(sys.argv) != 3:
    print("usage: " + sys.argv[0] + "<sdl2 include dir> <output dir>")

print("In case of segfault, delete the pycache")

headers = [
    ["SDL.h", [
        DefineToEnumSettings("SDL_INIT_", "InitFlags")
    ]],
    ["SDL_blendmode.h", []],
    ["SDL_hints.h", [
        DefineToEnumSettings("SDL_HINT_", "Hint", "const char*", True, "\"\"")
    ]],
    ["SDL_log.h", []],
    ["SDL_pixels.h", []],
    ["SDL_rwops.h", [
        DefineToEnumSettings("SDL_RWOPS_", "RWType"),
        DefineToEnumSettings("RW_SEEK_", "RWSeek")
    ]],
    ["SDL_surface.h", []],
    ["SDL_video.h", []]
]

for header in headers:
    headerFilename = header[0]
    headerDefines = header[1]
    inName = sys.argv[1]+"/"+headerFilename
    outName = sys.argv[2]+"/generated_"+headerFilename.lower()

    print("Parsing " + inName)
    enums = findEnums(inName)
    defines = []
    for defineSettings in headerDefines:
        defines.append(defineToEnum(inName,defineSettings))

    fileBody = ""
    for enum in enums:
        fileBody += enum.makeScoped()
    for define in defines:
        fileBody += define.makeScoped()

    fileContents = """\
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
#ifndef sdl2wrap_generated_%(safeName)s
#define sdl2wrap_generated_%(safeName)s

#include "%(headerBasename)s"

namespace sdl2wrap {
%(fileBody)s
}; // namespace sdl2wrap 

#endif // sdl2wrap_generated_*
""" \
    % {
        "safeName": os.path.splitext(headerFilename)[0],
        "headerBasename": headerFilename,
        "fileBody": fileBody
                   }

    open(outName, "w").write(fileContents)
    print("Wrote " + outName)

# generated impl header file
print("Collecting impl files")
implincludes = ""
implfiles = os.listdir('include/sdl2wrap/detail/impl')
implfiles.sort()
for filename in implfiles:
    implincludes += "#include \"../impl/" + os.path.basename(filename) + "\"\n"

implfileContents="""
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
#ifndef sdl2wrap_generated_implfiles
#define sdl2wrap_generated_implfiles

%s

#endif // sdl2wrap_generated_implfiles
""" % implincludes
implfileName = sys.argv[2]+"/impl.h"
open(implfileName, 'w').write(implfileContents)
print("Wrote %s" % implfileName)
