#!/bin/bash
sed -e 's/theo1/Wile E. Coyote/gi' | sed -e 's/steven1/Daffy Duck/gi' | sed -e 's/arnaud1/Porky Pig/gi' | sed -e 's/pierre-jean/Marvin the Martian/gi' | grep -Ei 'wile e. coyote|daffy duck|porky pig|marvin the martian' 
