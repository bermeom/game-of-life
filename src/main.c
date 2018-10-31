#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "gameOfLife.h"

/*The team used GitHub to help coordinate the members. Therefor,
it is difficult to determine exactly which member did with part of the code,
as there where updates, merges, etc, made by all.*/


//Coder 4
void menu(){
  char opt;

  initall(); //start ncurses
    do{
    move(0,0);attron(A_BOLD); //cursor to begining of the board
    //Menu to choose the different boards available
    printw(" Welcome to game of life !! \n");
    printw(" ------------------------- \n\n");
    printw(" Menu: \n");
    printw("  0. BlinkerP2 Board\n");
    printw("  1. Beacon Board\n");
    printw("  2. R-pentomino Board\n");
    printw("  3. DieHard Board\n");
    printw("  4. Acron Board\n");
    printw("  5. video1 Board\n");
    printw("  e. Exit\n");
    printw("  Choose an option? ");
    opt = getch();
    attroff(A_BOLD);
    switch(opt){
	//Run with the chosen board
        case ('0'):run(0,200);  break;
        case ('1'):run(1,200);  break;
        case ('2'):run(2,200);  break;
        case ('3'):run(3,200);  break;
        case ('4'):run(4,200);  break;
        case ('5'):run(5,200);  break;
    }
    clear(); //Clear screen
    }while(opt!='e'); //Exit

  enditall(); //return to default terminal screen
 }

void menuV2(){
  char opt;

  initall();   
    do{
    move(0,0);attron(A_BOLD);
    printw(" Welcome to game of life !! \n");
    printw(" ------------------------- \n\n");
    printw(" Menu: \n");
    printw("  0. BlinkerP2 Board\n");
    printw("  1. Beacon Board\n");
    printw("  2. R-pentomino Board\n");
    printw("  3. DieHard Board\n");
    printw("  4. Acron Board\n");
    printw("  5. video1 Board\n");
    printw("  e. Exit\n");
    printw("  Choose an option? ");
    opt = getch();
    attroff(A_BOLD);
    switch(opt){
        case ('0'):runV2(0,200);  break;
        case ('1'):runV2(1,200);  break;
        case ('2'):runV2(2,200);  break;
        case ('3'):runV2(3,200);  break;
        case ('4'):runV2(4,200);  break;
        case ('5'):runV2(5,200);  break;
    }
    clear();
    }while(opt!='e');
  
  enditall();
 }

int main(){
  // Solution 1
  // menu();
  // Solution 2
  menuV2();
  return 0;
}
