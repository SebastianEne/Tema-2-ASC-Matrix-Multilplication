#!/bin/bash

[[ -z $COMPILER ]] && COMPILER="gcc"

if [[ $COMPILER="gcc" ]]; then
   ./quad 10000
fi
