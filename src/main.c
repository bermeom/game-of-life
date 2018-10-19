#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "conway.h"

struct GameOfLife{

};
/*
void printBoard(bool *board,int &n,int &m){
  mvaddch(10,100,'X');
}//*/

int main(){
  initall();
  printw("Hello World !!!");	/* Print Hello World		  */
  refresh();			/* Print it on to the real screen */
  mvaddch(10,100,'X');
  mvaddch(20,10,'O');
  refresh();			/* Print it on to the real screen */
  /*
  int n=10,m=10;
  bool *board = (bool *) malloc(n*m*sizeof(bool));
  memset(board,0,n*m);
  //*/
  
  getch();			/* Wait for user input */
  enditall();

  return 0;
}
