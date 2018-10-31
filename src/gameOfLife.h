#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H


#include "boards.h"

// Function headers 

int initall(void);
int enditall(void);
// Coder: 4
int getPos(int i, int j, int m);
// Coder: 4
void printBoard(bool *board,int *n,int *m);
// Coder: 4
bool isValidPos(int i,int j, int *n, int *m);
// Coder: 1 and 2
bool isAlive(bool *board, int *n, int *m, int i, int j);
// Coder: 4 and 3
void updateBoard(bool *currboard,bool *newboard,int *n,int *m);
// Coder: 4 and 3
void run(int board_id,int itrns);

// Coder: 1
void printBoardV2(int *liveCells,int *tamLC,
                   int *deadCells,int *tamDC,int *m);
// Coder: 1 and 2
void updateBoardV2(bool **board,
                   int *n,int *m,
                   int **liveCells,int *tamLC,
                   int *deadCells,int *tamDC);
// Coder: 1
void getLiveCells(bool *board,
                   int *n,int *m,
                   int *liveCells,int *tamLC);
// Coder: 1
void runV2  (int board_id,int itrns);

#endif
