#include "Knight.h"
Knight::Knight(int r, int c, Color clr, Board* b)
	:Piece(r, c, clr, b)
{
	sym = (clr == White) ? 'n' : 'N';
}

bool Knight::isValidMove(Board b, int sr, int sc, int er, int ec)
{
    int dr = abs(sr - er);
    int dc = abs(sc - ec);
    return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
}

void Knight::draw(int r, int c)
{
    Utility u;
    char sym = -37;
    u.gotoRowCol(r - 1, c + 1);
    cout << sym;
    u.gotoRowCol(r, c);
    cout << sym << sym << sym;
    u.gotoRowCol(r + 1, c - 1);
    cout << sym << sym;
    u.gotoRowCol(r + 1, c + 3);
    cout << sym;
    u.gotoRowCol(r + 2, c - 1);
    cout << sym << sym << sym;
    u.gotoRowCol(r + 3, c - 1);
    cout << sym << sym << sym << sym;
}