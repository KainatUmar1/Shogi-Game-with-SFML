#pragma once
#include "Piece.h"
class Rook :
    public Piece
{
public:
    Rook(int r, int c, Color clr, Board* b);
    virtual void draw(int,int);
    virtual bool isValidMove(Board, int, int, int, int);
};