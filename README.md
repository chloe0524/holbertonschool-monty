![Design sans titre (1)](https://github.com/chloe0524/holbertonschool-monty/assets/127857895/6af77bf9-2116-489a-826c-6c67aba9af9f)


# Monty Language Interpreter


This is an interpreter for the Monty programming language.

## Details

- Each Monty bytecode command is implemented as a separate function.
- The `main` function reads a Monty bytecode from a file and execute it accordingly.

| Requirements           |                    |
|------------------------|--------------------|
| Language               | C                  |
| OS                     | Ubuntu 20.04 LTS   |
| Compiler               | gcc                |
| Style guidelines       | Betty style        |
| Editors                | vi, vim, emacs     |


## Files :open_file_folder:

- `monty.h`: Header file containing function prototypes, data structures, and necessary includes.
- `main_monty.c`: Main file with the `main` function for Monty interpreter execution.
- `run_instructions.c`: Executes Monty bytecode instructions based on parameters.
- `push_op.c`: Implements the push command
- `pall_op.c`: Implements the pall command
- `pint_op.c`: Implements the pint command
- `pop_op.c`: Implements the pop command
- `nop_op.c`: Implements the nop command
- `swap_op.c`: Implements the swap command
- `add_op.c`: Implements the add command
- `sub_op.c`: Implements the sub command
- `mod_op.c`: Implements the mod command
- `div_op.c`: Implements the div command
- `mul_op.c`: Implements the mul command

### Compilation
````
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
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
