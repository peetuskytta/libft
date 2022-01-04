#!/bin/bash

# This script will update your libft header file with the
# correct prototypes. It will also update the source files in Makefile.
#
# Make sure you modify this file to fit your needs.

	echo "-------------------"
#	Here we create the auxiliary files needed.
	echo "Creating input.keys, func_p.txt and func.txt files "
	touch input.keys
	touch input_l.keys
	touch func_p.txt
	touch func.txt 

# In the section below the script will find the prototypes, sort them based on 
# the first column, save them to func_p.txt file where sort and formatting happens.
# Also, any static function declarations are deleted.
#
# NOTE! Script will erase everything below line 18 in libft.h header file. So, if you
# have anything else below the prototypes make sure to adjust this script.
#
# Another way would be using the vim command {:g/);/d} which deletes all lines containing
# the /PATTERN/.

	echo "Finding and formatting the prototypes."
	awk '/void\011ft_/ || /int\011ft_/ || /char\011ft_/ || /size_t\011ft_/ \
	|| /void\011\*ft_/ || /char\011\*ft_/ || /int\011\*ft_/ || /char\011\**ft/ \
	{print $0";"}' *ft_* > func_p.txt
	vim +':sort | x' func_p.txt
	vim +':%s/int\t/int\t\t/ | x' func_p.txt
	echo "19gg" > input_l.keys
	echo "dG" >> input_l.keys
	echo ":r func_p.txt" >> input_l.keys
	echo ":g/static/d" >> input_l.keys
	echo "ZZ" >> input_l.keys
	echo "Updating the header file."
	vim -s input_l.keys libft.h
	echo "\n#endif" >> libft.h
	echo "Finished."
	echo "-------------------"

# In the section below we update the Makefile contents with the source .c files.
# The script will erase the {SRC =} or whatever you have in the lines you specify
# the source files.
# Adjust the contents below to meet your needs.

	echo "Finding and formatting the source files."
	echo "SRC =" > func.txt
	ls *ft_* | awk '/ft_/ {print $0" \\"}' >> func.txt
	vim +':%s/ft_/\tft_/g | x' func.txt 
	echo "ggJZZ" > input.keys
	vim -s input.keys func.txt
	echo ":g/ft_/d" > input.keys
	echo "15gg" >> input.keys
	echo ":r func.txt" >> input.keys
	echo "ZZ" >> input.keys
	echo "Updating the contents of Makefile"
	vim -s input.keys Makefile
	echo "All .c sources in Makefile updated and formatted."
#	rm func.txt 
#	rm func_p.txt
	rm input.keys
	rm input_l.keys
	echo "Finished."
	echo "-------------------"
	
