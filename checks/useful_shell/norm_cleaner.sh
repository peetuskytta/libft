#!bin/bash

###############________NORMINETTE SPACE/TAB CLEANER________###############
#
# This is a very basic .c file norminette cleaner for the most common
# tab and whitespace mistakes.
#
# The following is considered:
#	
# 	1. whitespaces instead of tabs in the beginning of line.
# 	2. space/tab before newline after ';'.
# 	3. no space after return.
# 	4. tab after return.
#	5. no space after if()/while().
#	6. four spaces before variable type instead of tab.
#	7. empty lines after the function.
# 
#	NOTE! Works only with files containing single function!
#	NOTE! It will not check the prototype.
#
##########################################################################

	# The script reads stdin first argument and assigns that to the variable
	# filename.
	if [[ "$1" != "" ]]; then
		filename="$1"
	fi	

	echo "Norminette check before:"
	norminette -R CheckForbiddenHeaders $filename

	# Start by creating our vim input file called cleaner.keys
	touch cleaner.keys
	chmod 755 cleaner.keys

	# The first command will erase your header (it will be added back)
	echo "ggd11j" > cleaner.keys
	echo ":%s/    /\t/g" >> cleaner.keys
	echo ":%s/   /\t/g" >> cleaner.keys
	echo ":%s/  /\t/g" >> cleaner.keys
	echo ":%s/return(/return (/g" >> cleaner.keys
	echo ":%s/return\t(/return (/g" >> cleaner.keys
	echo ":%s/; /;/g" >> cleaner.keys
	echo ":%s/;\t/;/g" >> cleaner.keys
	echo ":%s/while(/while (/g" >> cleaner.keys
	echo ":%s/if(/if (/g" >> cleaner.keys

	# Checking for space after a variable type and changing it to \t.
	# Note that we start at line 16 to protect the prototype.
	echo ":4,10s/size_t    /size_t\t/g" >> cleaner.keys
#	echo ":4,10s/size_t /size_t\t/g" >> cleaner.keys
	echo ":4,10s/char    /char\t/g" >> cleaner.keys
	echo ":4,10s/int    /int\t/g" >> cleaner.keys
#	echo ":4,10s/int /int\t/g" >> cleaner.keys
	echo ":v/\n*./d" >> cleaner.keys
	# Adding the header back
	echo ":Stdheader" >> cleaner.keys
	echo "ZZ" >> cleaner.keys
	vim -s cleaner.keys $filename
	rm cleaner.keys

	echo "Norm check after:"
	norminette -R CheckForbiddenHeaders $filename
