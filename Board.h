#pragma once
class Piece;
class Board
{
	int Dim;
public:
	Board();
	Piece* ** Ps;
	void displayBoard(int r, int c, int dr, int dc);
	Piece* getPiece(int r, int c);
	void move(int sri, int sci, int dri, int dci);
};