#!/bin/sh

astylerc="-T4 -n -A14 -xV -C -S -N -L -xW -w -Y -f -p -xg -D -k1 -y -xb -j -xy -xp "

find ./server ./client -name "*.h" -exec astyle $astylerc {} +
find ./server ./client -name "*.cpp" -exec astyle $astylerc {} +
