#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

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


struct Coordinate{
  int i; // row
  int j; // column
};

//Obtaining the index for the representation of the board from an array using i and j
int getPos(int i, int j, int m){
  return m*i+j;
}
// Obtaining i and j coordinate form index
struct Coordinate getCor(int id, int m){
  struct Coordinate coord;
  coord.i = id/m; // i
  coord.j = id-coord.i*m; // j
  return coord;
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

// New version to show the board from the terminal, using only live cells and the new dead 
// cells with complexity:
// O (n) = I + D,
// where, L is the number of living cells and D the number of dead cells
void printBoardV2(int *liveCells,int *tamLC,
                   int *deadCells,int *tamDC,int *m){
  move(0,0);
  int i;
  struct Coordinate coord;
  // print live cells
  for (i = 0; i < *tamLC; ++i){
      coord = getCor(liveCells[i],*m);
      mvaddch(coord.i,coord.j,('O'));
  }
  // erase live cells or print dead cells
  for (i = 0; i < *tamDC; ++i){
      coord = getCor(deadCells[i],*m);
      mvaddch(coord.i,coord.j,(' '));
  }
}

// The new version of the code to update the board requires two more arrays,
// liveCells and deadCells. Evaluate each living cell if it is kept alive or
// not, and the vicinities of the dead cells, then the liveCells array and 
// the deadCells array are updated as the case may be.
//  The complexity is:
//  O(L) = L
//  where, L is the number of living cells.
void updateBoardV2(bool **board,
                   int *n,int *m,
                   int **liveCells,int *tamLC,
                   int *deadCells,int *tamDC){
  int i,k,newtamLC = 0;
  struct Coordinate coord;
  *tamDC=0;
  move(0,0);
  for (i = 0; i < *tamLC; ++i){
      coord = getCor(liveCells[0][i],*m);
      board[1][liveCells[0][i]]=isAlive(board[0],n,m,coord.i,coord.j);
      if (board[1][liveCells[0][i]]){
         liveCells[1][newtamLC] = liveCells[0][i];
         ++newtamLC;
      }else{
        deadCells[(*tamDC)]=liveCells[0][i];
        (*tamDC)++;
      }
      // Evaluation of dead cells around the live cell
      for(k = 0; k < 8; k++){
        if(isValidPos(coord.i+x[k],coord.j+y[k],n,m)){
          if(!board[0][getPos(coord.i+x[k],coord.j+y[k],*m)] 
              && !board[1][getPos(coord.i+x[k],coord.j+y[k],*m)] ){
            board[1][getPos(coord.i+x[k],coord.j+y[k],*m)]=isAlive(board[0],n,m,coord.i+x[k],coord.j+y[k]);
            if (board[1][getPos(coord.i+x[k],coord.j+y[k],*m)]){
              liveCells[1][newtamLC] = getPos(coord.i+x[k],coord.j+y[k],*m);
              ++newtamLC;
            }
          }
        }
      }
  }
  // Swapping pointers
  int *aux = liveCells[0];  
  liveCells[0] = liveCells[1];
  liveCells[1] = aux; 
  bool *auxb = board[0];  
  board[0] = board[1];
  board[1] = auxb;
  memset(board[1],0,(*n)*(*m)); 
  // Update new length of the live cells array 
  *tamLC = newtamLC;
}

// This function is used the first time to find live cells and is added to
//  the liveCells array.
void getLiveCells(bool *board,
                   int *n,int *m,
                   int *liveCells,int *tamLC){
  int i,j;
  (*tamLC)=0;
  for ( i = 0; i < *n; i++){
    for ( j = 0; j < *m; j++){
      if (board[getPos(i,j,*m)]){
          liveCells[(*tamLC)]=getPos(i,j,*m);
          ++(*tamLC);
      }
    }
  }
}

// The new version of the run function using the new solution.
void runV2  (int board_id,int itrns){
  move(0,0);
  int n = 30,m = 60,tamLC=0,tamDC=0;    //n = rows  m = columns
  bool **board = (bool **) malloc((2)*sizeof(bool*)); 
  int **liveCells =  (int **) malloc((2)*sizeof(int*)); 
  int *deadCells = (int *) malloc(n*m*sizeof(int));
  board[0] = (bool *) malloc(n*m*sizeof(bool));  // Create a vector of n by m
  board[1] = (bool *) malloc(n*m*sizeof(bool));  // Create a vector of n by m
  liveCells[0] = (int *) malloc(n*m*sizeof(int));  // Create a vector 
  liveCells[1] = (int *) malloc(n*m*sizeof(int));  // Create a vector 
  

  memset(board[0],0,n*m);
  switch(board_id){
    case(0):setupBlinkerP2(board[0],&n,&m);break;
    case(1):setupBeacon(board[0],&n,&m);break;
    case(2):setupRpentomino(board[0],&n,&m);break;
    case(3):setupDieHard(board[0],&n,&m);break;
    case(4):setupAcron(board[0],&n,&m);break;
    case(5):setupvideo1(board[0],&n,&m);break;
    default: setupAcron(board[0],&n,&m);
  }
  getLiveCells(board[0],&n,&m,liveCells[0],&tamLC);
  printBoard(board[0],&n,&m);
    
  for(int f = 0; f < itrns; ++f){
    printBoardV2(liveCells[0],&tamLC,deadCells,&tamDC,&m);
    attron(A_BOLD); move(n+1,0);
    printw(" Iteration: %d",f);    attroff(A_BOLD);
    refresh();
    usleep((int)3e4);
    updateBoardV2(board,&n,&m,liveCells,&tamLC,deadCells,&tamDC);
  }
  
  free(board[0]);
  free(board[1]);
  free(board);
  free(liveCells[0]);
  free(liveCells[1]);
  free(liveCells);
  free(deadCells);
  
}