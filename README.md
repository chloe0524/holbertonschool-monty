![Black and White Modern Thunder Twitch Panel](https://github.com/chloe0524/holbertonschool-monty/assets/127857895/ecd0988e-2c7d-4409-bd91-b8cc501ea8c1)
# Monty Language Interpreter


This is an interpreter for the Monty programming language.

## Details

- Each Monty bytecode command is implemented as a separate function.
- The `main` function reads Monty bytecode from a file, tokenizes the commands, and executes them accordingly.

## Files :open_file_folder:

- `monty.h`: Header file containing function prototypes, data structures, and necessary includes.
- `monty.c`: Main file with the `main` function for Monty interpreter execution.
- `instructions.c`: Contains functions for each Monty bytecode command.
- `stack_operations.c`: Implements stack-related operations.
- `run_instruct.c`: Executes Monty bytecode instructions based on parameters.
- `Makefile`: Makefile for compilation.

### Compilation
````
~/holbertonschool-monty# gcc -Wall -Werror -Wextra -pedantic *.c -o monty
````
### Execution
Run the interpreter with a Monty bytecode file as an argument:
```bash
./monty bytecodes/file.m
```
### Example of use
````
~/holbertonschool-monty# cat bytecodes/00.m
push 1
push 2
push 3
pall
~/holbertonschool-monty# ./monty bytecodes/00.m
3
2
1
````

## Monty Bytecode Commands :snake:
=========================================

| Command | Description |
| :-----: | :---------: |
|  push   | Pushes an integer onto the stack. |
|  pall   | Prints all the values on the stack, starting from the top. |
|  pint   | Prints the value at the top of the stack. |
|  pop    | Removes the top element of the stack. |
|  nop    | Does nothing. |
|  swap   | Swaps the top two elements of the stack. |
|  add    | Adds the top two elements of the stack. |

## Authors
- Chloe Correia
- Clement Mascret 
