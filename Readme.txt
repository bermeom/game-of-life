# Game of life
##### Authors (coders)
1. Miguel Angel Bermeo Ayerbe
2. Guillermo Lopez Diest
3. Javier Manjón Prado
4. David Vegas Romero
## Code structure
The code has two libraries, to load the different boards in '/src/boards.h' and '/src/gameOfLife.h' with the logic of the game. In addition, '/src/main.h' has a menu function to interact with the user and choose which table is executed.
## Solution
We explore two solutions, the first using little memory but expensive in time and the second faster but require more memory. To save the board with little memory and since the cell has only two states, the board is represented as an array of booleans. So, the first solution is simple only to evaluate the rules of each cell and generate a new board. The second solution uses an array of living cells to evaluate only that cells and neighboring dead cells.
## Compilation
This project uses a Makefile, creates two folders, 'build' with .o files and 'bin' with executable. To compile, execute this command in the terminal:
```sh
$ make
```
