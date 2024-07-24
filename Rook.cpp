#include "Rook.h"

Rook::Rook(int r, int c, Color clr, Board* b)
	:Piece(r, c, clr, b)
{
	sym = (clr == White) ? 'r' : 'R';
}

void Rook::draw(int r, int c)
{
    Utility u;
    char sym = -37;
    u.gotoRowCol(r - 1, c - 1);
    cout << sym;
    u.gotoRowCol(r - 1, c + 1);
    cout << sym;
    u.gotoRowCol(r - 1, c + 3);
    cout << sym;
    u.gotoRowCol(r, c - 1);
    cout << sym << sym << sym << sym << sym;
    u.gotoRowCol(r + 1, c);
    cout << sym;
    u.gotoRowCol(r + 1, c + 2);
    cout << sym;
    u.gotoRowCol(r + 2, c);
    cout << sym << sym << sym;
    u.gotoRowCol(r + 3, c - 1);
    cout << sym << sym << sym << sym << sym;
}

bool Rook::isValidMove(Board b, int sr, int sc, int er, int ec)
{
    bool h = isHorizontal(sr, er) && isHorizontalPathClr(b, sr, sc, ec);
    bool v = isVertical(sc, ec) && isVerticalPathClr(b, sr, sc, er);
    return h || v;
}