#!/bin/bash -ue
#
# My relese build and no qtcreator
#

#SRC="../puzzle15/help.cpp  ../puzzle15/main.cpp  ../puzzle15/plan.cpp  ../puzzle15/system.cpp"
SRC="help.cpp list.cpp main.cpp system.cpp"

set -x

g++ -std=c++14 -O2 -s -D SKRIPT_RUN -o mymain  $SRC

./mymain $@
