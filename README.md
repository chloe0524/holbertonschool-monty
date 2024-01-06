![Design sans titre (1)](https://github.com/chloe0524/holbertonschool-monty/assets/127857895/6af77bf9-2116-489a-826c-6c67aba9af9f)


# Monty Language Interpreter


This is an interpreter for the Monty programming language.

## Details

- Each Monty bytecode command is implemented as a separate function.
- The `main` function reads Monty bytecode from a file, tokenizes the commands, and executes them accordingly.

## Files :open_file_folder:

- `monty.h`: Header file containing function prototypes, data structures, and necessary includes.
- `main_monty.c`: Main file with the `main` function for Monty interpreter execution.
- `run_instructions.c`: Executes Monty bytecode instructions based on parameters.


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
|  sub    |  subtracts top element of the stack from the second top element of the stack |
|  mul   | multiplies second top element of the stack with top element of the stack |
|  mod    | Adds the top two elements of the stack. |
|  div    | computes remainder of division, second top by top stack element. |

## Authors
- Chloe Correia
- Clement Mascret 
