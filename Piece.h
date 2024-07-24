#pragma once
#include"Utility.h"
#include"Board.h"
#include<iostream>
using namespace std;

class Board;
class Piece
{
	int ri, ci;
	static bool isDiagonalPathClrL2R(Board B, int, int, int, int);
	static bool isDiagonalPathClrR2L(Board B, int, int, int, int);
protected:
	Board *b;
	Color clr;
	char sym;
	static bool isHorizontal(int sr, int er);
	static bool isVertical(int sc, int ec);
	static bool isDiagonal(int sr, int sc, int er, int ec);
	static bool isHorizontalPathClr(Board b, int sr, int sc, int ec);
	static bool isVerticalPathClr(Board b,int sr, int sc, int er);
	static bool isDiagonalPathClr(Board B, int, int, int, int);
public:
	Piece(int r, int c, Color clr, Board* _b);
	virtual bool isValidMove(Board, int, int, int, int) = 0;
	virtual void draw(int, int) = 0;
	void move(int r, int c);
	Color getColor();
};

