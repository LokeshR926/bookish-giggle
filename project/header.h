/* The header library for the chess game.*/
#include<stdio.h>
void clrscr();
void controls(void);
void exitYN(void);
int mainMenu(void);
void startGame(char mat[8][8]);
void display(void);
void matrix(char mat[8][8]);
int c_soilder(int r, int c, int i, int j,char mat[8][8]);
int s_soilder(int r, int c, int i, int j,char mat[8][8]);
int R_rock(int r,int c, int i, int j, char mat[8][8]);
int r_rock(int r,int c, int i, int j,char mat[8][8]);
int B_bishop(int r, int c, int i, int j, char mat[8][8]);
int b_bishop(int r, int c, int i, int j, char mat[8][8]);
int Q_queen(int r, int c, int i, int j, char mat[8][8]);
int q_queen(int r, int c, int i, int j, char mat[8][8]);
int N_knights(int r,int c, int i, int j, char mat[8][8]);
int n_knights(int r,int c, int i, int j, char mat[8][8]);
void input(char mat[8][8]);