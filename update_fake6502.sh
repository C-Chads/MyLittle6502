#!/bin/bash
IFS=$'\n' FILES=$(find .. -name "fake6502.h")
ME="../fake6502_cchads/fake6502.h"
for filename in $FILES
do
 if [[ "$filename" != "$ME" ]]; then
 	echo "<SHELL> Copying to $filename"
 	cp "$ME" "$filename"
 else
 	echo "Found ourselves!"
 fi
done
