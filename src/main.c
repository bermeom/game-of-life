#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utime.h>
#include <ncurses.h>

#include "conway.h"

int getPos(int i, int j, int m){
  return m*i+j;
}


void printBoard(bool *board,int *n,int *m){
  move(0,0);
  for (int i = 0; i < *n; i++){
    for (int j = 0; j < *m; j++){
      mvaddch(i,j,board[getPos(i,j,*m)]?( 'O'):' ');   // position 10 10, put an X
    }
  }
}

int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValidPos(int i,int j, int *n, int *m){
  return 0 <= i && i < *n && 0 <= j && j < *m;
}

bool isAlive(bool *board, int *n, int *m, int i, int j){
  int aliveCounter = 0;
  for(int k = 0; k < 8; k++){
    if(isValidPos(i+x[k],j+y[k],n,m)){
      aliveCounter += (int)board[getPos(i+x[k],j+y[k],*m)] ;
    }
  }
  if (board[getPos(i,j,*m)] && 1 < aliveCounter && aliveCounter < 4){
    return true;
  }
  else if (!board[getPos(i,j,*m)] && aliveCounter == 3){
    return true;
  }
  return false;

}

void updateBoard(bool **board,int *n,int *m){
  bool *newBoard = (bool *) malloc((*n)*(*m)*sizeof(bool));
  for (int i = 0; i < *n; i++){
    for (int j = 0; j < *m; j++){
       newBoard[getPos(i,j,*m)]=isAlive(*board,n,m,i,j);
    }
  }
  remove(*board);
  *board=newBoard;
}

void setupBlinkerP2(bool *board,int *n,int *m){
  board[getPos(4,3,*m)] = true;
  board[getPos(4,4,*m)] = true;
  board[getPos(4,5,*m)] = true;
}

void setupBeacon(bool *board,int *n,int *m){
  board[getPos(2,2,*m)] = true;
  board[getPos(2,3,*m)] = true;
  board[getPos(3,2,*m)] = true;
  board[getPos(5,5,*m)] = true;
  board[getPos(5,4,*m)] = true;
  board[getPos(4,5,*m)] = true;
}

void setupRpentomino(bool *board,int *n,int *m){
  board[getPos(10,35,*m)] = true;
  board[getPos(10,36,*m)] = true;
  board[getPos(11,34,*m)] = true;
  board[getPos(11,35,*m)] = true;
  board[getPos(12,35,*m)] = true;
}

void setupDieHard(bool *board,int *n,int *m){
  board[getPos(10,20,*m)] = true;
  board[getPos(10,21,*m)] = true;
  board[getPos(11,21,*m)] = true;

  board[getPos(11,25,*m)] = true;
  board[getPos(11,26,*m)] = true;
  board[getPos(11,27,*m)] = true;
  board[getPos(9,26,*m)] = true;
}

void setupAcron(bool *board,int *n,int *m){
  board[getPos(11,20,*m)] = true;
  board[getPos(11,21,*m)] = true;
  board[getPos(9,21,*m)] = true;

  board[getPos(10,23,*m)] = true;
  board[getPos(11,24,*m)] = true;
  board[getPos(11,25,*m)] = true;
  board[getPos(11,26,*m)] = true;
}

void setupvideo1(bool *board,int *n,int *m){
  board[getPos(10,10,*m)] = true;
  board[getPos(10,11,*m)] = true;
  board[getPos(11,11,*m)] = true;
  board[getPos(11,10,*m)] = true;
  board[getPos(10,14,*m)] = true;
  board[getPos(9,15,*m)] = true;
  board[getPos(10,15,*m)] = true;
  board[getPos(11,15,*m)] = true;
  board[getPos(8,16,*m)] = true;
  board[getPos(12,16,*m)] = true;
  board[getPos(10,17,*m)] = true;
  board[getPos(7,18,*m)] = true;
  board[getPos(13,18,*m)] = true;
  board[getPos(7,19,*m)] = true;
  board[getPos(13,19,*m)] = true;
  board[getPos(8,20,*m)] = true;
  board[getPos(12,20,*m)] = true;
  board[getPos(9,21,*m)] = true;
  board[getPos(10,21,*m)] = true;
  board[getPos(11,21,*m)] = true;

  board[getPos(12,26,*m)] = true;

  board[getPos(12,29,*m)] = true;
  board[getPos(12,30,*m)] = true;
  board[getPos(12,31,*m)] = true;
  board[getPos(11,31,*m)] = true;
  board[getPos(10,30,*m)] = true;

  board[getPos(10,35,*m)] = true;
  board[getPos(11,35,*m)] = true;
  board[getPos(6,35,*m)] = true;
  board[getPos(5,35,*m)] = true;
  board[getPos(6,37,*m)] = true;
  board[getPos(10,37,*m)] = true;

  board[getPos(7,38,*m)] = true;
  board[getPos(7,39,*m)] = true;
  board[getPos(8,38,*m)] = true;
  board[getPos(8,39,*m)] = true;
  board[getPos(9,38,*m)] = true;
  board[getPos(9,39,*m)] = true;

  board[getPos(8,44,*m)] = true;
  board[getPos(9,44,*m)] = true;
  board[getPos(8,45,*m)] = true;
  board[getPos(9,45,*m)] = true;

}


int main(){
  initall();    //

  int n = 30,m = 60;    //n = rows  m = columns
  bool *board = (bool *) malloc(n*m*sizeof(bool));  // Create a vector of n by m
  memset(board,0,n*m);    // Set all the vector to 0
  //setupBlinkerP2(board,&n,&m);
  //setupBeacon(board,&n,&m);
  //setupRpentomino(board,&n,&m);
  //setupDieHard(board,&n,&m);
  setupAcron(board,&n,&m);
  //setupvideo1(board,&n,&m);

  for(int f = 0; f < 200; f++){
    printBoard(board,&n,&m);
    move(m+1,0);attron(A_BOLD);
    printw("Iteration: %d",f);attroff(A_BOLD);
    refresh();
    usleep((int)3e5);
    updateBoard(&board,&n,&m);
  }
  //*/
  getch();			/* Wait for user input */
  enditall();
  return 0;
}
