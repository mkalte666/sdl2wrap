#!/bin/bash

if [ "$#" -lt 1 ]; then
  echo "usage: buildFeaturelist.bash <sdl include dir>"
  exit 1
fi

includeDir=$1

./scripts/generator.py "$includeDir" ./include/sdl2wrap/detail/generated/
./scripts/buildFeaturelist.bash "$includeDir" features.md
./scripts/format.bash .