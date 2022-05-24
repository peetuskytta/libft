# libft

42's libft project's objective is to re-code some of the most useful libc functions to create our own static library. This library is used in all of the projects during studies at 42 school. 

## Sources

In [sources](./sources) you will find all the `.c` files of this library project. In total there were more than 50 functions to be recoded, e.g.: [strcmp](./sources/ft_strcmp.c), [split](./sources/ft_strsplit.c).

## Bash Scripts

During the project I felt the need to automate some tasks. I achieved this by learning about bash scripts. Click here to see the [bash scripts](./useful_shell). The most useful was the [proto](./useful_shell/proto), which updates the protoypes to the header file and `.c` files to the Makefile.

Some of these scripts might be useful for someone doing this project. 

**NOTE: make sure you understand what they do before you use them!**

## Status

- ✅ Graded on 12/30/2021
- ✅ Score: **100**
- ✅ Retry: **1** after two peer evaluations. Found edge cases for ft_strjoin.c and memory leaks in ft_strsplit.c for which I gave up and retried.
