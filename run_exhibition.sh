#!/bin/bash
export POPUP_FOLDER=.

x=0
#while :; do
while [ $x -le 0 ]; do
    $POPUP_FOLDER/isaacclarke/bin/isaacclarke.app/Contents/MacOS/isaacclarke
    $POPUP_FOLDER/tommygraven/bin/tommygraven.app/Contents/MacOS/tommygraven
    $POPUP_FOLDER/alexfletcher/bin/alexfletcher.app/Contents/MacOS/alexfletcher
    $POPUP_FOLDER/valerioviperino/bin/valerioviperino.app/Contents/MacOS/valerioviperino
    $POPUP_FOLDER/ecehasdogan/bin/ecehasdogan.app/Contents/MacOS/ecehasdogan
    $POPUP_FOLDER/dorukhasdogan/bin/dorukhasdogan.app/Contents/MacOS/dorukhasdogan
    (( x++ ))
done
