#include "Board.h"
#include"Utility.h"
#include"Pawn.h"
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Queen.h"
#include"Rook.h"
Board::Board()
{
	Dim = 8;
	Ps = new Piece * *[Dim];
	for (int ri = 0; ri < Dim; ri++)
	{
		Ps[ri] = new Piece * [Dim];
		for (int ci = 0; ci < Dim; ci++)
		{
			if (ri == 0 && ci == 3)
				Ps[ri][ci] = new Queen(ri, ci, White, this);
			else if (ri == 0 && (ci == 1 || ci == 6))
				Ps[ri][ci] = new Knight(ri, ci, White, this);
			else if (ri == 0 && ci == 4)
				Ps[ri][ci] = new King(ri, ci, White, this);
			else if (ri == 0 && (ci == 2 || ci == 5))
				Ps[ri][ci] = new Bishop(ri, ci, White, this);
			else if (ri == 0 && (ci == 0 || ci == 7))
				Ps[ri][ci] = new Rook(ri, ci, White, this);
			else if (ri == 1)
				Ps[ri][ci] = new Pawn(ri, ci, White, this);

			else if (ri == 7 && ci == 3)
				Ps[ri][ci] = new Queen(ri, ci, Black, this);
			else if (ri == 7 && (ci == 1 || ci == 6))
				Ps[ri][ci] = new Knight(ri, ci, Black, this);
			else if (ri == 7 && ci == 4)
				Ps[ri][ci] = new King(ri, ci, Black, this);
			else if (ri == 7 && (ci == 2 || ci == 5))
				Ps[ri][ci] = new Bishop(ri, ci, Black, this);
			else if (ri == 7 && (ci == 0 || ci == 7))   
				Ps[ri][ci] = new Rook(ri, ci, Black, this);

			else if (ri == 6)
				Ps[ri][ci] = new Pawn(ri, ci, Black, this);
			else
				Ps[ri][ci] = nullptr;
		}
	}
}

void Board::displayBoard(int r, int c,int dr,int dc)
{
	Utility u;
	if (Ps[r][c] != nullptr)
	{
		if (Ps[r][c]->getColor() == White)
			u.SetClr(4);
		else if (Ps[r][c]->getColor() == Black)
			u.SetClr(9);
		else
			u.SetClr(7);
		Ps[r][c]->draw(dr, dc);
	}
}

Piece* Board::getPiece(int r, int c)
{
	return Ps[r][c];
}

void Board::move(int sri, int sci, int dri, int dci)
{
	Ps[dri][dci] = Ps[sri][sci];
	Ps[sri][sci] = nullptr;
}