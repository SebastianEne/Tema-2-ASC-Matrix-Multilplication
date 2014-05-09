#!/bin/bash

[[ -z $COMPILER ]] && COMPILER="gcc"

if [[ $COMPILER="gcc" ]]; then
   ./nehalem 10000
fi
