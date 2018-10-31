#include <stdio.h>
#include <stdbool.h>


//Definition of the different available boards


//Coder 1
void setupBlinkerP2(bool *board,int *n,int *m){
  board[getPos(4,3,*m)] = true;
  board[getPos(4,4,*m)] = true;
  board[getPos(4,5,*m)] = true;
}
//Coder 1
void setupBeacon(bool *board,int *n,int *m){
  board[getPos(2,2,*m)] = true;
  board[getPos(2,3,*m)] = true;
  board[getPos(3,2,*m)] = true;
  board[getPos(5,5,*m)] = true;
  board[getPos(5,4,*m)] = true;
  board[getPos(4,5,*m)] = true;
}
//Coder 1
void setupRpentomino(bool *board,int *n,int *m){
  board[getPos(10,35,*m)] = true;
  board[getPos(10,36,*m)] = true;
  board[getPos(11,34,*m)] = true;
  board[getPos(11,35,*m)] = true;
  board[getPos(12,35,*m)] = true;
}
//Coder 2
void setupDieHard(bool *board,int *n,int *m){
  board[getPos(10,20,*m)] = true;
  board[getPos(10,21,*m)] = true;
  board[getPos(11,21,*m)] = true;

  board[getPos(11,25,*m)] = true;
  board[getPos(11,26,*m)] = true;
  board[getPos(11,27,*m)] = true;
  board[getPos(9,26,*m)] = true;
}
//Coder 1
void setupAcron(bool *board,int *n,int *m){
  board[getPos(11,20,*m)] = true;
  board[getPos(11,21,*m)] = true;
  board[getPos(9,21,*m)] = true;

  board[getPos(10,23,*m)] = true;
  board[getPos(11,24,*m)] = true;
  board[getPos(11,25,*m)] = true;
  board[getPos(11,26,*m)] = true;
}
//Coder 2
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
