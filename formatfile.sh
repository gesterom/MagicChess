#!/bin/sh
find ./server ./client -name "*.h" -exec astyle {} +
find ./server ./client -name "*.cpp" -exec astyle {} +
