#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H


#include "boards.h"

int initall(void);
int enditall(void);
int getPos(int i, int j, int m);
void printBoard(bool *board,int *n,int *m);
bool isValidPos(int i,int j, int *n, int *m);
bool isAlive(bool *board, int *n, int *m, int i, int j);
void updateBoard(bool *currboard,bool *newboard,int *n,int *m);
void run(int board_id,int itrns);

#endif
