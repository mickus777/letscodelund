#!/bin/bash -uex
#
# My relese build and no qtcreator
#

SRC="help.cpp  main.cpp  plan.cpp  system.cpp"

g++ -std=c++14 -O2 -s -D SKRIPT_RUN -o puzzle15  $SRC

for fil in $@
do
  ./puzzle15 $fil
done
