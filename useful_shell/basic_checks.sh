#!/bin/bash

######################################################################################
# 
# This script does a very basic check of the files. It doesn't test the functions!
# 
# Pay special attention to the last part: check_norm, this part will find unjustified
# header includes. The Norm Version 3 states that all includes in C files and header 
# files must be justified. The norminette check is very handy but it won't catch 
# these types of Norm errors.
# 
# 
# The script will save any errors in results.txt file.
# 
# https://elearning.intra.42.fr/notions/the-norm/subnotions/norm-v3/pdfs/Norm%20V3
# 
#####################################################################################

file_ok="\033[32mOK\033[0m"
file_ko="\033[31mKO\033[0m"

file_found="\033[32mfound\033[0m"
file_not_found="\033[31mnot found\033[0m"

COLOR_FAIL="\033[31m"
COLOR_OK="\033[32m"
COLOR_DEF="\033[0m"
_dFILES="libft/*ft_*"

printf "\n"
printf "_______________________________________________"
printf "\n"
printf "\n"
check_makefile
printf "\n"
printf "_______________________________________________"
printf "\n\n"
check_header
check_author
printf "\n"
check_norm
printf "\n"



check_makefile()
{
	if [ -e "Makefile" ];
	then
		printf "Makefile"
		printf "\033[20G-Wall"
		printf "\033[30G-Wextra"
		printf "\033[40G-Werror\n"
		printf "$file_found"
		printf "\033[20G"
		if [ -z "$(grep -w '\-Wall' Makefile)" ];
		then
			printf "${COLOR_FAIL}missing${COLOR_DEF}"
		else
			printf "${COLOR_OK}OK${COLOR_DEF}"
		fi
		printf "\033[30G"
		if [ -z "$(grep -w '\-Wextra' Makefile)" ];
		then
			printf "${COLOR_FAIL}missing${COLOR_DEF}"
		else
			printf "${COLOR_OK}OK${COLOR_DEF}"
		fi
		printf "\033[40G"
		if [ -z "$(grep -w '\-Werror' Makefile)" ];
		then
			printf "${COLOR_FAIL}missing${COLOR_DEF}"
		else
			printf "${COLOR_OK}OK${COLOR_DEF}"
		fi
	else
		printf "Makefile\n"
		printf "$file_not_found"
	fi
}
check_header()
{
	if [ -f "libft.h" ];
	then
    	printf "Header file\033[15G$file_ok\n"
	else
    	printf "Header file\033[15G$file_ko\n"
	fi


}

check_author()
{
	if [ -f "author" ];
	then
    	printf "Author file\033[15G$file_ok"
	else
	    printf "Author file\033[15G$file_ko"
    fi
}

check_norm()
{
	if [ -f "results.txt" ]; then
		rm results.txt
	else
		touch results.txt
	fi
	touch comp.txt
	touch n_check.txt
	touch forbidden_include.txt

	printf "\nNorm error:\n" > results.txt 
	printf "Norm check:"
	norminette -R CheckForbiddenFlags *ft_* | awk '/Error/ {print}' > n_check.txt
	norminette -R CheckForbiddenFlags *ft_* | awk '/Error/ {print}' >> results.txt
	if cmp -s n_check.txt comp.txt; then
		printf "\033[15G$file_ok\n"
	else
		printf "\033[15G$file_ko\n"
		printf "\033[15GOpen results.txt for more info\n"
	fi
	rm comp.txt

	touch check.txt
	printf "\nForbidden include:\n" >> results.txt 
	printf "Include check:"
	grep '<*.h>' *ft_* > forbidden_include.txt
	grep '<*.h>' *ft_* >> results.txt
	printf "\n" >> results.txt 
	if cmp -s forbidden_include.txt check.txt; then
		printf "\033[15G$file_ok\n"
	else
		printf "\033[15G$file_ko\n"
		printf "\033[15GOpen results.txt for more info\n"
	fi

	rm check.txt
	rm n_check.txt
	rm forbidden_include.txt
}
