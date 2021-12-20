#!/bin/bash

#########################################################################################
#
# This Shell script will create a [NAME].c based on your input. It will also 
# add the 42 header and [#include "libft.h"].
#
# Let's assume you want to start coding the ft_memset.c funtion. Running this script
# will ask you to name your function and after hitting enter the ft_memset.c file with
# your 42 header is created and you are ready to edit your file.
#
# I recommend creating an alias to run this script, as it makes it so much faster.
# 
# Mine looks like this: [alias new='source ../checks/useful_shell/./newfile.sh']
# Whenever I run the script it will create the file in the current directory.
# 
# Feel free to modify this file to your own needs. 
# 
#########################################################################################

	echo "Name the function you want to create:"
	read filename
	echo "#include \"libft.h\"" >> $filename
	chmod 755 $filename
	vim +:Stdheader $filename

# This code below creates a copy to eval/ directory for later use in tests.	
	cp -v $filename ./eval/test_$filename
	vim +':%d | x' ./eval/test_$filename
