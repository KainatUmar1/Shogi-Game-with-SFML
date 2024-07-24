#pragma once
#include "Piece.h"

class Queen :
    public Piece
{
public:
    Queen(int r, int c, Color clr, Board* b);
    virtual bool isValidMove(Board, int, int, int, int);
    virtual void draw(int,int);
};

