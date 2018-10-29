#include <stdio.h>
#include <ncurses.h>
// #include <utime.h>

#include "boards.h"

int initall(void)
{
	initscr();			/* Start curses mode 		  */
	return 0;
};

int enditall(void)
{
	endwin();			/* Start curses mode 		  */
	return 0;
};

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

void updateBoard(bool *currboard,bool *newboard,int *n,int *m){
  for (int i = 0; i < *n; i++){
    for (int j = 0; j < *m; j++){
       newboard[getPos(i,j,*m)]=isAlive(currboard,n,m,i,j);
    }
  }
}


void run(int board_id,int itrns){
  int n = 30,m = 60,k0=0,k1=1;    //n = rows  m = columns
  bool **board = (bool **) malloc(2*sizeof(bool*)); 
  board[k0] = (bool *) malloc(n*m*sizeof(bool));  // Create a vector of n by m
  board[k1] = (bool *) malloc(n*m*sizeof(bool));  // Create a vector of n by m
  
  memset(board[k0],0,n*m);
  switch(board_id){
    case(0):setupBlinkerP2(board[k0],&n,&m);break;
    case(1):setupBeacon(board[k0],&n,&m);break;
    case(2):setupRpentomino(board[k0],&n,&m);break;
    case(3):setupDieHard(board[k0],&n,&m);break;
    case(4):setupAcron(board[k0],&n,&m);break;
    case(5):setupvideo1(board[k0],&n,&m);break;
    default: setupAcron(board[k0],&n,&m);
  }
  
  for(int f = 0; f < itrns; ++f){
    printBoard(board[k0],&n,&m);
    move(n+1,0);attron(A_BOLD);
    printw(" Iteration: %d",f);attroff(A_BOLD);
    refresh();
    usleep((int)3e4);
    updateBoard(board[k0],board[k1],&n,&m);
    move(0,0);attron(A_BOLD);
    k0 = (k0+1)%2; 
    k1 = (k1+1)%2; 
  }
  //*/
  free(board[k0]);
  free(board[k1]);
}