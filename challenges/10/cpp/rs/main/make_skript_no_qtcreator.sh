#!/bin/bash -ue
#
# My relese build and no qtcreator
#

SRC="main.cpp bruijn.cpp"

set -x

g++ -std=c++14 -O2 -s -D SKRIPT_RUN -o mymain  $SRC

set +x

time ./mymain $@

rm mymain
