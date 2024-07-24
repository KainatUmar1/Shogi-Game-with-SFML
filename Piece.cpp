#include"Board.h"
#include"Piece.h"
#include<math.h>

Piece::Piece(int r, int c, Color _clr, Board* _b)
{
	this->ri = r;
	this->ci = c;
	this->clr = _clr;
	this->b = _b;
}

bool Piece::isHorizontal(int sr, int er)
{
	return sr == er;
}

bool Piece::isVertical(int sc, int ec)
{
	return sc == ec;
}

bool Piece::isDiagonal(int sr, int sc, int er, int ec)
{
	return abs(sr - er) == abs(sc - ec);
}

bool Piece::isHorizontalPathClr(Board b, int sr, int sc, int ec)
{
    int cs, ce;
    if (sc < ec)
    {
        cs = sc + 1;
        ce = ec - 1;
    }
    else
    {
        cs = ec + 1;
        ce = sc - 1;
    }
    for (int c = cs; c <= ce; c++)
        if (b.getPiece(sr, c) != nullptr)
            return false;
    return true;
}

bool Piece::isVerticalPathClr(Board b, int sr, int sc, int er)
{
    int cs, ce;
    if (sr < er)
    {
        cs = sr + 1;
        ce = er - 1;
    }
    else
    {
        cs = er + 1;
        ce = sr - 1;
    }
    for (int r = cs; r <= ce; r++)
        if (b.getPiece(r, sc) != nullptr)
            return false;
    return true;
}

bool Piece::isDiagonalPathClrL2R(Board b, int sr, int sc, int er, int ec)
{
    if (sr < er)
    {
        int Dr = er - sr - 1;
        for (int i = 1; i <= Dr; i++)
            if (b.getPiece(sr + i, sc + i) != nullptr)
                return false;
        return true;
    }
    else if (sr > er)
    {
        int Dr = sr - er - 1;
        for (int i = 1; i <= Dr; i++)
            if (b.getPiece(sr - i, sc + i) != nullptr)
                return false;
        return true;
    }
    return false;
}

bool Piece::isDiagonalPathClrR2L(Board b, int sr, int sc, int er, int ec)
{
    if (sr < er)
    {
        int Dr = er - sr - 1;
        for (int i = 1; i <= Dr; i++)
            if (b.getPiece(sr + i, sc - i) != nullptr)
                return false;
        return true;
    }
    else if (sr > er)
    {
        int Dr = sr - er - 1;
        for (int i = 1; i <= Dr; i++)
            if (b.getPiece(sr - i, sc - i) != nullptr)
                return false;
        return true;
    }
    return false;
}

bool Piece::isDiagonalPathClr(Board b, int sr, int sc, int er, int ec)
{
    return isDiagonalPathClrL2R(b, sr, sc, er, sc) || isDiagonalPathClrR2L(b, sr, sc, er, sc);
}

void Piece::move(int r, int c)
{
	this->ri = r;
	this->ci = c;
}

Color Piece::getColor()
{
	return clr;
}

bool Piece::isValidMove(Board, int, int, int, int)
{
    return true;
}

void Piece::draw(int r, int c)
{
    Utility u;
    char sym = -37;
    u.gotoRowCol(r + 1, c + 1);
    cout << sym;
    u.gotoRowCol(r + 2, c + 1);
    cout << sym;
    u.gotoRowCol(r + 1, c + 2);
    cout << sym;
    u.gotoRowCol(r + 2, c + 2);
    cout << sym;
}