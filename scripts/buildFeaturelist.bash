#!/bin/bash

if [ "$#" -lt 2 ]; then
  echo "usage: buildFeaturelist.bash <sdl include dir> <outfile.md>"
  exit 1
fi

includeDir=$1
outfile=$2

grep -Roh "\\wrapImpl.*" include/ | sed s/wrapImpl\\s*//g > .wrapImpl.txt
grep -Roh "\\wrapWontfix.*" include/ | sed s/wrapImpl\\s*//g > .wrapWontfix.txt
grep -Roh "SDL[_A-Za-z0-9]*" "$includeDir" > .sdlList.txt

python3 ./scripts/featuresFromIntermediates.py .wrapImpl.txt .wrapWontfix.txt .sdlList.txt "$outfile"

rm -f .wrapImpl.txt .wrapWontfix.txt .sdlList.txt
