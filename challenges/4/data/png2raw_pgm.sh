#!/bin/bash -ue

for fil in $@
do
  pgmfil="${fil%\.png}.pgm"
#  echo "pgm: $pgmfil"

  echo "pngtopnm -mix -background 1,1,1 $fil | ppmtopgm | pnmtoplainpnm  >$pgmfil"
  pngtopnm -mix -background 1,1,1 "$fil" | ppmtopgm | pnmtoplainpnm  >$pgmfil

  # Ta bort P2 så det bara är nummer
  grep -v 'P2' $pgmfil >pgm.tmp
  mv pgm.tmp $pgmfil

done

