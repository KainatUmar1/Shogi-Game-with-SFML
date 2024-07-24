#pragma once
#include"Board.h"

#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14

enum Color { Black, White };

class Utility
{
	void label(int r, int c);
public:
	void drawCell(Board b, int sr, int sc, int para, int rdim, int cdim);
	//void drawCell1(Board* b, int sr, int sc, int para, int rdim, int cdim,int);
	void SetClr(int clr);
	void getRowColbyLeftClick(int& rpos, int& cpos);
	void gotoRowCol(int rpos, int cpos);
	void drawBoard(Board b, int dim);
};