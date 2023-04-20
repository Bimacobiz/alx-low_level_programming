0x0F. C - Function Pointers
Introduction
This project is part of the Holberton School curriculum and focuses on teaching the concept of function pointers in the C programming language. The project contains several C programs that demonstrate the use of function pointers and how they can be used to call different functions at runtime.

Files
The following files are included in this project:

0-print_name.c
A program that takes a string and a function pointer as arguments and uses the function pointer to print the string.

1-array_iterator.c
A program that takes an array, its size, and a function pointer as arguments and uses the function pointer to iterate through the array and perform an action on each element.

2-int_index.c
A program that takes an array, its size, and a function pointer as arguments and uses the function pointer to search for an integer in the array.

3-main.c
A program that performs simple mathematical operations based on user input. The program uses function pointers to dynamically call the appropriate function based on the operator input by the user.

3-op_functions.c
A program that contains the functions used in the 3-main.c program for performing mathematical operations.

3-get_op_func.c
A program that contains a function that returns a function pointer based on the operator input by the user.

3-calc.h
A header file that contains the function prototypes and data structures used in the 3-main.c, 3-op_functions.c, and 3-get_op_func.c programs.

100-main_opcodes.c
A program that prints the opcodes of its own main function. The program uses function pointers to cast the main function to a character array and print its opcode.
