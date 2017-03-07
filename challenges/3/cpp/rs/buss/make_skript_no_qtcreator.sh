#!/bin/bash -ue
#
# My relese build and no qtcreator
#

SRC="group.cpp help.cpp main.cpp"

g++ -std=c++14 -O2 -s -D SKRIPT_RUN -o mybuss  $SRC

for fil in $@
do
  echo "------  $fil  -------"
  ./mybuss $fil
  echo "-------------------"
done
