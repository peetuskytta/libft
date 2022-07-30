# libft

42's libft project's objective is to re-code some of the most useful libc functions to create our own static library. This library is used in all of the projects during studies at 42 school.

## Sources

In [sources](./sources) you will find all the `.c` source files of this project. In total there were more than 50 functions to be recoded, e.g.: [strcmp](./sources/ft_strcmp.c), [split](./sources/ft_strsplit.c).

### How to use?

run the following command in terminal of your choice `make` which will compile the project and create `libft.a` library archive.

### What did I learn?

1. To `free()` all dynamically allocated memory.
2. Bash scripting for running tests.
3. Basics of pointer arithmetics.
4. Making sure that `char` arrays end in `\0`.
5. Basics of Makefile.
6. Writing clean and readable code.

### What did I struggle with?
1. Pointers, as it was hard to understand them at first.
2. Memory leaks.
3. Documenting the code.

## Bash Scripts

During the project I felt the need to automate some tasks. I achieved this by learning about bash scripts. Click here to see the [bash scripts](./useful_shell). The most useful was the [proto](./useful_shell/proto.sh), which updates the protoypes to the header file and `.c` files to the Makefile.

Some of these scripts might be useful for someone doing this project. 

**NOTE: make sure you understand what they do before you use them!**

## Status

- ✅ Graded on 12/30/2021
- ✅ Score: **100**
- ✅ Retry: **1** after two peer evaluations. Peer evaluator found edge cases for ft_strjoin.c and memory leaks in ft_strsplit.c for which I gave up and retried.
