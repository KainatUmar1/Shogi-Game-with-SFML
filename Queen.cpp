#include"Queen.h"
Queen::Queen(int r, int c, Color clr, Board* b)
	:Piece(r, c, clr, b)
{
	sym = (clr == White) ? 'q' : 'Q';
}

bool Queen::isValidMove(Board B, int sr, int sc, int er, int ec)
{
    bool h = isHorizontal(sr, er) && isHorizontalPathClr(B, sr, sc, ec);
    bool v = isVertical(sc, ec) && isVerticalPathClr(B, sr, sc, er);
    bool r = h || v;
    bool b = isDiagonal(sr, sc, er, ec) && isDiagonalPathClr(B, sr, sc, er, ec);
    return r || b;
}

void Queen::draw(int r, int c)
{
    Utility u;
    char sym = -37;
    u.gotoRowCol(r - 1, c + 1);
    cout << sym;
    u.gotoRowCol(r, c);
    cout << sym;
    u.gotoRowCol(r, c + 2);
    cout << sym;
    u.gotoRowCol(r + 1, c - 1);
    cout << sym << sym << sym << sym << sym;
    u.gotoRowCol(r + 2, c);
    cout << sym;
    u.gotoRowCol(r + 2, c + 2);
    cout << sym;
    u.gotoRowCol(r + 3, c - 1);
    cout << sym << sym << sym << sym << sym;
}