#!/bin/bash
sed -n 2~2p | cut -d":" -f 1 | rev | sort -r | tr '\n' ',' | cut -d "," -f $MY_LINE1-$MY_LINE2 | sed 's/,/, /g' | sed -E 's/$/.\n/'
