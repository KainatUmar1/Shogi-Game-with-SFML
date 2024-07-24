#pragma once
#include "Piece.h"

class Pawn :
    public Piece
{
    char sym;
public:
    Pawn(int r, int c, Color clr, Board* b);
    virtual bool isValidMove(Board, int, int, int, int);
    virtual void draw(int, int);
    void Promotion(int sri,int);
};