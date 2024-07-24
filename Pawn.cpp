#include "Pawn.h"

Pawn::Pawn(int r, int c, Color clr, Board* b)
	:Piece(r, c, clr, b)
{
    sym = (clr == White) ? 'P' : 'p';
}

bool Pawn::isValidMove(Board b, int sr, int sc, int er, int ec)
{
    if ((sym == 'P' && sr > 6) || (sym == 'p' && sr < 1))
        Promotion(sr, sc);

    bool v = isVertical(sc, ec) && isVerticalPathClr(b, sr, sc, er);
    bool h = isHorizontal(sr, er) && isHorizontalPathClr(b, sr, sc, ec);
    bool d = isDiagonalPathClr(b, sr, sc, er, ec);
    bool B = isDiagonal(sr, sc, er, ec) && d;
    bool r = h || v;
    int dr = abs(er - sr);
    int dc = abs(sc - ec);

    if (sym == 'p' || sym == 'P')
    {
        if (clr == White)
        {
            if (sr == 1)
            {
                if (isDiagonalPathClr(b, sr, sc, dr, ec))
                    return dr <= 2 && (er > sr) && v;
                else if (!isDiagonalPathClr(b, sr, sc, dr, ec))
                    return dr <= 1 && (er > sr) && isDiagonal(sr, sc, dr, ec);
            }
            //if (sr>1)
            //{
            //    Piece* S = b.getPiece(sr, sc);
            //    Piece* D = b.getPiece(er, ec);// && (S->getColor() != D->getColor());
            //}
            return dr <= 1 && (er > sr) && v;
        }
        else
        {
            if (sr == 6)
            {
                if (isDiagonalPathClr(b, sr, sc, dr, ec))
                    return dr <= 2 && (er < sr) && v;
                else if (!isDiagonalPathClr(b, sr, sc, dr, ec))
                    return dr <= 1 && (er < sr) && isDiagonal(sr, sc, dr, ec);
            }
            /*{
                Piece* S = b->getPiece(sr, sc);
                Piece* D = b->getPiece(er, ec);
                return dr <= 1 && (er < sr) && isDiagonal(sr, sc, dr, ec) && (S->getColor() != D->getColor());
            }*/
            return dr <= 1 && (er < sr) && v;
        }
    }

    else if (sym == 'q' || sym == 'Q')
    {
        bool r = h || v;
        return r || B;
    }

    else if (sym == 'K' || sym == 'k')
    {
        bool q = r || B;
        return q && dr <= 1 && dc <= 1;
    }

    else if (sym == 'r' || sym == 'R')
        return r;

    else if (sym == 'n' || sym == 'N')
        return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
}

void Pawn::draw(int r, int c)
{
    Utility u;
    char s = -37;
    if(sym=='P'||sym=='p')
    {
        u.gotoRowCol(r - 1, c + 1);
        cout << s;
        u.gotoRowCol(r, c - 1);
        cout << s << s << s << s << s;
        u.gotoRowCol(r + 1, c);
        cout << s << s << s;
        u.gotoRowCol(r + 2, c - 1);
        cout << s << s << s << s << s;
    }
    else if (sym == 'k' || sym == 'K')
    {
        u.gotoRowCol(r, c - 1);
        cout << s;
        u.gotoRowCol(r, c + 1);
        cout << s;
        u.gotoRowCol(r, c + 3);
        cout << s;
        u.gotoRowCol(r + 1, c - 1);
        cout << s << s << s << s << s;
        u.gotoRowCol(r + 2, c - 1);
        cout << s;
        u.gotoRowCol(r + 2, c + 1);
        cout << s;
        u.gotoRowCol(r + 2, c + 3);
        cout << s;
        u.gotoRowCol(r + 3, c - 1);
        cout << s << s << s << s << s;
    }
    else if (sym == 'q' || sym == 'Q')
    {
        u.gotoRowCol(r - 1, c + 1);
        cout << s;
        u.gotoRowCol(r, c);
        cout << s;
        u.gotoRowCol(r, c + 2);
        cout << s;
        u.gotoRowCol(r + 1, c - 1);
        cout << s << s << s << s << s;
        u.gotoRowCol(r + 2, c);
        cout << s;
        u.gotoRowCol(r + 2, c + 2);
        cout << s;
        u.gotoRowCol(r + 3, c - 1);
        cout << s << s << s << s << s;
    }
    else if (sym == 'r' || sym == 'R')
    {
        u.gotoRowCol(r - 1, c - 1);
        cout << s;
        u.gotoRowCol(r - 1, c + 1);
        cout << s;
        u.gotoRowCol(r - 1, c + 3);
        cout << s;
        u.gotoRowCol(r, c - 1);
        cout << s << s << s << s << s;
        u.gotoRowCol(r + 1, c);
        cout << s;
        u.gotoRowCol(r + 1, c + 2);
        cout << s;
        u.gotoRowCol(r + 2, c);
        cout << s << s << s;
        u.gotoRowCol(r + 3, c - 1);
        cout << s << s << s << s << s;
    }
    else if (sym == 'n' || sym == 'N')
    {
        u.gotoRowCol(r - 1, c + 1);
        cout << s;
        u.gotoRowCol(r, c);
        cout << s << s << s;
        u.gotoRowCol(r + 1, c - 1);
        cout << s << s;
        u.gotoRowCol(r + 1, c + 3);
        cout << s;
        u.gotoRowCol(r + 2, c - 1);
        cout << s << s << s;
        u.gotoRowCol(r + 3, c - 1);
        cout << s << s << s << s;
    }
}

void Pawn::Promotion(int sri,int sci)
{
    Utility u;
    Piece* S = b->getPiece(sri, sci);
    if (S->getColor() == White)
        u.SetClr(4);
    if (S->getColor() == Black)
        u.SetClr(9);
    u.gotoRowCol(19, 115);
    cout << "To which piece you want to promote your PAWN?";
    u.gotoRowCol(20, 115);
    cout << "\tK (King)\t\tQ (Queen)";
    u.gotoRowCol(21, 115);
    cout << "\tR (Rook)\t\tN (Knight)";
    u.gotoRowCol(22, 115);
    cin >> sym;
}