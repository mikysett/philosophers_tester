#! /bin/bash

nb_tests=${#cmd[@]}

for (( i=0; i < $nb_tests; i++ )); do
	output=$(eval ${cmd[$i]} 2>&1)
	echo -e "$BLU Test    $i:$WHT ${cmd[$i]}"
	echo -e "$BLU Output :$WHT"
	echo "$output"
done
