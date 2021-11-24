#!/bin/bash

###############################################################
#
# This script will remove your previous libft header file!
# Make sure you modify this file to fit your needs. For example
#
#
# Make sure you check the awk search parameters to match your
# needs.
#
###############################################################


	rm libft.h
	echo "-------------------"
	echo "Removing old libft.h file."

# Here we add commands to input.keys file for the 42 header.
	touch input.keys
	echo ":Stdheader" >> input.keys
	echo "ddZZ" >> input.keys

# Create new libft.h and add 42 header to it. Chmod might not be necessary.
	echo "Creating new libft.h file."
	echo "Adding the header."
	vim -s input.keys libft.h
	chmod 755 libft.h
	rm input.keys

# Including the stuff we need after the 42 header. Could use another method 
# instead of echo? Add more includes and defines if you need.
	echo "#ifndef LIBFT_H" >> libft.h
	echo "# define LIBFT_H" >> libft.h
	echo >> libft.h
	echo "# include <string.h>" >> libft.h
	echo "# include <unistd.h>" >> libft.h
	echo "# include <stdlib.h>" >> libft.h
	echo >> libft.h

# This will search the prototypes, sort them based on the third column 
# and print them to libft header file adding the semicolon in the end of each protoype.
	echo "Adding the prototypes."
	awk '/void\011ft_/ || /int\011ft_/ || /char\011ft_/ || /size_t\011ft_/ \
	|| /void\011\*ft_/ || /char\011\*ft_/ {print $0";"}' *ft_* | sort -k 3 >> libft.h

# Adds whatever else you need after the prototypes.
	echo >> libft.h
	echo "#endif" >> libft.h
	echo "Finished."
	echo "-------------------"
