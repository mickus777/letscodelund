#!/bin/bash -ue
#
# My relese build and no qtcreator
#

#SRC="../puzzle15/help.cpp  ../puzzle15/main.cpp  ../puzzle15/plan.cpp  ../puzzle15/system.cpp"
#SRC="help.cpp list.cpp main.cpp system.cpp"
SRC="bildaria.cpp  koch.cpp  main.cpp help.cpp"

set -x

g++ -std=c++14 -O2 -s -D SKRIPT_RUN -o mymain  $SRC

./mymain $@

pnmtopng koch.ppm >koch_$1.png
