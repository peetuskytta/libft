#!/bin/bash

	if [ -e "input.keys" ]
	then
		rm input.keys
	fi

	touch input.keys
	echo ":Stdheader" >> input.keys
	echo "ddZZ" >> input.keys
	echo "Name the function you want to create:"
	read filename
	vim -s input.keys $filename
	echo "#include \"libft.h\"" >> $filename
	echo >> $filename
	vim $filename
	rm input.keys
