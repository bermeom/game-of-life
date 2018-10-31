#include <stdio.h>
#include <ncurses.h>
// #include <utime.h>

#include "boards.h"

//Start curses mode

//Coder 3
int initall(void)
{
	initscr();
	return 0;
};

//Restore terminal
int enditall(void)
{
	endwin();
	return 0;
};

//Obtaining the cell position
int getPos(int i, int j, int m){
  return m*i+j;
}


void printBoard(bool *board,int *n,int *m){
  move(0,0); //Move the cursor at the begining
  for (int i = 0; i < *n; i++){
    for (int j = 0; j < *m; j++){
      //Print the character to the live cells of the board
      mvaddch(i,j,board[getPos(i,j,*m)]?( 'O'):' ');
    }
  }
}

//Coder 1&2
//Neighbors vector
int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

//Check if the position given is inside the limits
bool isValidPos(int i,int j, int *n, int *m){
  return 0 <= i && i < *n && 0 <= j && j < *m;
}

//Check if the cell is alive
bool isAlive(bool *board, int *n, int *m, int i, int j){
  int aliveCounter = 0;
  for(int k = 0; k < 8; k++){
    if(isValidPos(i+x[k],j+y[k],n,m)){ //We run the 8 neighbours of the cell counting alive cells
      aliveCounter += (int)board[getPos(i+x[k],j+y[k],*m)] ;
    }
  }
  //Live conditions
  if (board[getPos(i,j,*m)] && 1 < aliveCounter && aliveCounter < 4){
    return true;
  }
  else if (!board[getPos(i,j,*m)] && aliveCounter == 3){
    return true;
  }
  //Death
  return false;

}

//Update the board with the new cells
void updateBoard(bool *currboard,bool *newboard,int *n,int *m){
  for (int i = 0; i < *n; i++){
    for (int j = 0; j < *m; j++){
       newboard[getPos(i,j,*m)]=isAlive(currboard,n,m,i,j); //Check for each position if it's alive
    } //Save the results in the new board
  }
}

//Coder 3&4
void run(int board_id,int itrns){
  int n = 30,m = 60,k0=0,k1=1;    //n = rows  m = columns
  // We create two boards which will update each other in order to save memory
  bool **board = (bool **) malloc(2*sizeof(bool*));
  board[k0] = (bool *) malloc(n*m*sizeof(bool));  // Create a vector of n by m
  board[k1] = (bool *) malloc(n*m*sizeof(bool));  // Create a vector of n by m

  memset(board[k0],0,n*m); //Initialize the board
  switch(board_id){ //Choose the board
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
    move(n+1,0);attron(A_BOLD); //Move the cursor outside the board
    printw(" Iteration: %d",f);attroff(A_BOLD);
    refresh();
    usleep((int)3e4);
    updateBoard(board[k0],board[k1],&n,&m);
    move(0,0);attron(A_BOLD); //Return the cursor to the board
    //We exchange the two boards avoiding to create a new one for updating, saving memory
    k0 = (k0+1)%2;
    k1 = (k1+1)%2;
  }
  //Once the iterations have finished, we free the space of the two boards
  free(board[k0]);
  free(board[k1]);
	free(board);
}
