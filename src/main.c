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
      mvaddch(i,j,board[getPos(i,j,*m)]?( 'o'):' ');   // position 10 10, put an X
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


int main(){
  initall();    //

  int n = 10,m = 10;    //n = rows  m = columns
  bool *board = (bool *) malloc(n*m*sizeof(bool));  // Create a vector of n by m
  memset(board,0,n*m);    // Set all tehe vector to 0
  //setupBlinkerP2(board,&n,&m);
  setupBeacon(board,&n,&m);
  
  for(int f = 0; f < 50; f++){
    printBoard(board,&n,&m);
    move(m+1,0);attron(A_BOLD);	
    printw("Iteration: %d",f);attroff(A_BOLD);
    refresh();
    usleep((int)1e5);
    updateBoard(&board,&n,&m);
  }
  //*/
  getch();			/* Wait for user input */
  enditall();
  return 0;
}
