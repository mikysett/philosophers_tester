#! /bin/bash

nb_tests=${#cmd[@]}

for (( i=0; i < $nb_tests; i++ )); do
	echo -e "$BLU Test    $i:$WHT ${cmd[$i]}"
	output=$(eval ${cmd[$i]} 2>&1)
	echo -e "$BLU Output :$WHT"
	echo "$output"
done
