#!bin/bash

#############________NORMINETTE SPACE/TAB CLEANER________#############
# This is a very basic .c file norminette cleaner for the most common
# tab and whitespace mistakes. It will
# The following are considered:
# 	1.
# 	2.
# 	3.
# 	4.
# 
#	This will not work well with files containing static functions.
#	It will not check the prototype.

	# Name the file you want to run this script on. e.g. ft_atoi.c
	echo "Write the name of the file to be cleaned:"
	read filename

	#echo "Norm check before:"
	#norminette -R CheckForbiddenHeaders $filename

	# Start by creating our vim input file called cleaner.keys
	touch cleaner.keys
	chmod 755 cleaner.keys

	# The first command will erase your header (it will be added back)
	echo "ggd11j" > cleaner.keys
	echo ":%s/    /\t/g" >> cleaner.keys
	echo ":%s/return(/return (/g" >> cleaner.keys
	echo ":%s/return\t(/return (/g" >> cleaner.keys
	echo ":%s/; /;/g" >> cleaner.keys
	echo ":%s/;\t/;/g" >> cleaner.keys
	echo ":%s/while(/while (/g" >> cleaner.keys
	echo ":%s/if(/if (/g" >> cleaner.keys

	# Checking for space after a variable type and changing it to \t.
	# Note that we start at line 16 to protect the prototype.
	echo ":4,10s/size_t /size_t\t/g" >> cleaner.keys
	echo ":4,10s/char /char\t/g" >> cleaner.keys
	echo ":4,10s/int /int\t/g" >> cleaner.keys
	echo ":v/\n*./d" >> cleaner.keys
	echo ":Stdheader" >> cleaner.keys
	echo "ZZ" >> cleaner.keys
	vim -s cleaner.keys $filename
	rm cleaner.keys

	# Adding the header
	echo "Norm check after:"
	norminette -R CheckForbiddenHeaders $filename
