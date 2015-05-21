#!/bin/bash

	n=$1
	nm=$2
	s=$3
	p=$4

	while [ $n -le $nm ]
	do
		if [ "$p" == "p" ]
		then
			./sort -t int -d -p -O results.csv -r $n 0 99999999
		else
			./sort -t int -d -O results.csv -r $n 0 99999999
		fi
		n=$(($n + $s))
	done
