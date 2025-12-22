*This project has been created as part of the 42 curriculum by `rayan`*

# get_next_line
## Description
`get_next_line` is a C function that reads a line from a file descriptor, returning it as a dynamically allocated string. Each call to `get_next_line` returns the next line from the file, including the newline character (`\n`) if it exists, or `NULL` when the end of the file (EOF) is reached. 

This project demonstrates mastery of:

- File reading using `read()` system call.
- Dynamic memory allocation (`malloc` and `free`) for strings of unknown length.
- Static variables to preserve state between function calls.
- Utility functions for string manipulation (`ft_strlen`, `ft_strjoin`, `ft_strchr`, `ft_strdup`, `ft_substr`).


	
## Instructions
### Compilation

To compile the project, use:
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o test

## Resources
### Documentation & References
read() system call

malloc() / free() documentation

42 School get_next_line Subject

C String handling functions

Valgrind Documentation: https://valgrind.org/docs/manual/mc-manual.html


### AI Usage Declaration

AI (ChatGPT) was used only for:

Clarifying formatting edge cases and standard behavior

Generating this README in proper 42 format

Debugging explanations and LLDB advice (not code)

Improving documentation clarity

All code, algorithms, and implementation decisions were written manually.
