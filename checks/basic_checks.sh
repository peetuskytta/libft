#!/bin/bash

file_ok="\033[32mOK\033[0m"
file_ko="\033[31mKO\033[0m"

file_found="\033[32mfound\033[0m"
file_not_found="\033[31mnot found\033[0m"

PATH_LIBFT=$"~/libft"
COLOR_FAIL="\033[31m"
COLOR_OK="\033[32m"
COLOR_DEF="\033[0m"

printf "\n"
printf "_______________________________________________"
printf "\n\n"

check_makefile()
{
	if [ -e "Makefile" ];
	then
		printf "Makefile"
		printf "\033[15G-Wall"
		printf "\033[25G-Wextra"
		printf "\033[35G-Werror\n"
		printf "$file_found"
		printf "\033[15G"
		if [ -z "$(grep -w '\-Wall' Makefile)" ];
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
    	printf "Author file\033[15G$file_ok\n"
	else
	    printf "Author file\033[15G$file_ko\n"
	fi
}

check_makefile
printf "\n"
printf "_______________________________________________"
printf "\n\n"
check_header
printf "\n"
check_author
printf "\n"
