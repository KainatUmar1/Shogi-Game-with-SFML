#include "King.h"
King::King(int r, int c, Color clr, Board* b)
	:Piece(r, c, clr, b)
{
	sym = (clr == White) ? 'k' : 'K';
}

bool King::isValidMove(Board b, int sr, int sc, int er, int ec)
{
    int dr = abs(sr - er);
    int dc = abs(sc - ec);
    bool h = isHorizontal(sr, er) && isHorizontalPathClr(b, sr, sc, ec);
    bool v = isVertical(sc, ec) && isVerticalPathClr(b, sr, sc, er);
    bool r = h || v;
    bool bi = isDiagonal(sr, sc, er, ec) && isDiagonalPathClr(b, sr, sc, er, ec);
    bool q = r || bi;
    return q && dr <= 1 && dc <= 1;
}

void King::draw(int r, int c)
{
    Utility u;
    char sym = -37;
    u.gotoRowCol(r, c - 1);
    cout << sym;
    u.gotoRowCol(r, c + 1);
    cout << sym;
    u.gotoRowCol(r, c + 3);
    cout << sym;
    u.gotoRowCol(r + 1, c - 1);
    cout << sym << sym << sym << sym << sym;
    u.gotoRowCol(r + 2, c - 1);
    cout << sym;
    u.gotoRowCol(r + 2, c + 1);
    cout << sym;
    u.gotoRowCol(r + 2, c + 3);
    cout << sym;
    u.gotoRowCol(r + 3, c - 1);
    cout << sym << sym << sym << sym << sym;
}