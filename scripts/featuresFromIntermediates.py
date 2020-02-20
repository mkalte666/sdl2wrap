import sys
import re

ignoreList = [
    ".*_h_$",
    "^SDL_test.*",
    "^SDLTest_.*",
    "SDLCALL",
    "^SDL_$",
    ".*_$",
    "SDL_INLINE",
    "^SDL$",
    "^SDL_Read.*$",
    "^SDL_Write.*$",
]

class ImplInfo:
    def __init__(self):
        self.implemented = "NO"
        self.implName = ""
        self.comment = ""

if len(sys.argv) != 5:
    print("do not use this directly!!!")

def calcCoverage(knownSymbols):
    count = len(knownSymbols)
    countYes = 0
    for key in knownSymbols:
        value = knownSymbols[key]
        if value.implemented != "NO":
            countYes+=1

    return "%.2f %% (%d/%d)" % (float(countYes)/float(count)*100.0, countYes, count)

wrapImplName = sys.argv[1]
wrapWontfixName = sys.argv[2]
sdlGrepName = sys.argv[3]
outfileName = sys.argv[4]

wrapImplFile = open(wrapImplName, "r").read().splitlines(False)
wrapWontfixFile = open(wrapWontfixName, "r").read().splitlines(False)
sdlGrepFile = open(sdlGrepName, "r").read().splitlines(False)

knownSymbols = {}
for name in sdlGrepFile:
    needIgnore = False
    for ignore in ignoreList:
        if re.match(rf"{ignore}", name):
            needIgnore = True
            break
    if needIgnore:
        continue
    knownSymbols[name] = ImplInfo()

for line in wrapImplFile:
    parts = line.split(" ", 2)
    what = parts[0]
    info = ImplInfo()
    info.implemented = "YES"
    if len(parts) > 1:
        info.implName = parts[1]
        if len(parts) > 2:
            info.comment = parts[2]
    knownSymbols[what] = info

for line in wrapWontfixFile:
    parts = line.split(" ", 1)
    what = parts[0]
    info = ImplInfo()
    info.implemented = "WONTFIX"
    if len(parts) > 1:
        info.comment = parts[1]
    knownSymbols[what] = info

outfile = open(outfileName, "w")
outfile.write("This list is generated and might not be reflect the truth to 100%\n")
outfile.write("Estimated coverage: %s\n" % calcCoverage(knownSymbols))
outfile.write("\n")
outfile.write("| SDL Symbol | Implemented? | New Name | Comment |\n")
outfile.write("| ---------- | ------------ | -------- | ------- |\n")

for key in sorted(knownSymbols):
    info = knownSymbols[key]
    line = "| {} | {} | {} | {} |\n".format(key, info.implemented, info.implName, info.comment)
    outfile.write(line)

outfile.close()