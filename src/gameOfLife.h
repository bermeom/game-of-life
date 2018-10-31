#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H


#include "boards.h"
//Coder 3
//Functions initiallization
int initall(void);
int enditall(void);
int getPos(int i, int j, int m);
void printBoard(bool *board,int *n,int *m);
bool isValidPos(int i,int j, int *n, int *m);
bool isAlive(bool *board, int *n, int *m, int i, int j);
void updateBoard(bool *currboard,bool *newboard,int *n,int *m);
void run(int board_id,int itrns);

void printBoardV2(int *liveCells,int *tamLC,
                   int *deadCells,int *tamDC,int *m);
void updateBoardV2(bool **board,
                   int *n,int *m,
                   int **liveCells,int *tamLC,
                   int *deadCells,int *tamDC);
void getLiveCells(bool *board,
                   int *n,int *m,
                   int *liveCells,int *tamLC);

void runV2  (int board_id,int itrns);

#endif
