#pragma once
#include"Utility.h"
class Board;
class Piece;
class Player;
class Chess
{
	int sri, sci, dri, dci;
	int turn;
	Player* Ps[2];
	Board B;
	Utility u;
	bool** map;
	void boardCopy(Board&, int dim);
	bool** computeHighlight(Board b, int sr, int sc, int dim, Player*);
	void BoxHighlight(bool**& M, Board b, int dim, int row, int col, Player*);
	void BoxUnhighlight(bool**& M, Board b, int dim, int row, int col, Player*);
	void findKing(Board b, int&, int&, int dim, Player* A);
	void displayTurnMsg(Player* A);
	void selectPiece(int&, int&, int, int);
	bool validSrc(Player* A, int r, int c);
	bool validDes(Player* A, int r, int c);
	void changeTurn(Player* A);
	bool isLegalMove(Board b, int, int, int, int);
	bool check(Board B, int dim, Player* A);
	bool selfCheck(Board B, int dim,int, int, int, int, Player* A);
public:
	Chess();
	void play();
};

