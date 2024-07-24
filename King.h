#pragma once
#include "Piece.h"
class King :
    public Piece
{
public:
    King(int r, int c, Color clr, Board* b);
    virtual bool isValidMove(Board b, int sr, int sc, int er, int ec);
    virtual void draw(int, int);
};