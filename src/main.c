#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>


#include "gameOfLife.h"

void menu(){
  char opt;

  initall();   
    do{
    move(0,0);attron(A_BOLD);
    printw(" Welcome to game of life !! \n");
    printw(" ------------------------- \n\n");
    printw(" Menu: \n");
    printw("  0. BlinkerP2  Board\n");
    printw("  1. Beacon  Board\n");
    printw("  2. Rpentomino  Board\n");
    printw("  3. DieHard  Board\n");
    printw("  4. Acron  Board\n");
    printw("  5. video1  Board\n");
    printw("  e. Exit \n");
    printw("  Choose an option? ");
    opt = getch();
    attroff(A_BOLD);
    switch(opt){
        case ('0'):run(0,200);  break;
        case ('1'):run(1,200);  break;
        case ('2'):run(2,200);  break;
        case ('3'):run(3,200);  break;
        case ('4'):run(4,200);  break;
        case ('5'):run(5,200);  break;
    }
    clear();
    }while(opt!='e');
  
  enditall();
 }

int main(){
  menu();
  return 0;
}
