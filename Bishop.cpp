#include "Bishop.h"

Bishop::Bishop(int r, int c, Color clr, Board* b)
	:Piece(r, c, clr, b)
{
	sym = (clr == White) ? 'b' : 'B';
}

bool Bishop::isValidMove(Board b, int sr, int sc, int er, int ec)
{
	return isDiagonal(sr, sc, er, ec) && isDiagonalPathClr(b, sr, sc, er, ec);
}

void Bishop::draw(int r, int c)
{
    Utility u;
    char sym = -37;
    u.gotoRowCol(r - 1, c + 1);
    cout << sym;
    u.gotoRowCol(r, c);
    cout << sym << sym << sym;
    u.gotoRowCol(r + 1, c + 1);
    cout << sym;
    u.gotoRowCol(r + 2, c);
    cout << sym << sym << sym;
    u.gotoRowCol(r + 3, c - 1);
    cout << sym << sym << sym << sym << sym;
}