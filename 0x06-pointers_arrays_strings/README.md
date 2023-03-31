0x06. C - Pointers, Arrays, and Strings
This directory contains programs written in C that demonstrate the use of pointers, arrays, and strings.
Table of Contents
Files
Description
Usage
Technologies Used
Author
Files
The following files are included in this directory:

main.h
0-strcat.c
1-strncat.c
2-strncpy.c
3-strcmp.c
4-rev_array.c
5-string_toupper.c
6-cap_string.c
7-leet.c
100-rot13.c
101-print_number.c
102-magic.c
103-infinite_add.c
104-print_buffer.c
Description
Each program in this directory demonstrates a different use case for pointers, arrays, and/or strings in C. The programs perform the following tasks:

0-strcat.c - concatenates two strings
1-strncat.c - concatenates two strings, but will use at most n bytes from src
2-strncpy.c - copies a string, but will use at most n bytes from src
3-strcmp.c - compares two strings
4-rev_array.c - reverses the content of an array of integers
5-string_toupper.c - changes all lowercase letters of a string to uppercase
6-cap_string.c - capitalizes all words of a string
7-leet.c - encodes a string into 1337
100-rot13.c - encodes a string using rot13
101-print_number.c - prints an integer
102-magic.c - prints a message using pointers
103-infinite_add.c - adds two numbers
104-print_buffer.c - prints a buffer
Usage
To compile each program, run the following command:

php
Copy code
gcc -Wall -pedantic -Werror -Wextra <filename.c> -o <output-file>
To run the compiled program, use the following command:

lua
Copy code
./<output-file>
Replace <filename.c> with the name of the program file you want to compile (e.g., 0-strcat.c) and replace <output-file> with the name you want to give to the compiled executable.

Technologies Used
These programs were written in C and compiled using gcc version 9.3.0.

Author
This directory was written by Collins Mahigi
