#include<time.h>
#include<Windows.h>
#include"Utility.h"
#include"Piece.h"
#include"Chess.h"
#include"Player.h"
#include"Board.h"
#include"King.h"

Chess::Chess()
{
	string n1, n2;
	cout << "Enter Name of 1st player : ";
	cin >> n1;
	cout << "Enter Name of 2nd player : ";
	cin >> n2;
	Ps[0] = new Player(n1, Black);
	Ps[1] = new Player(n2, White);
	B = Board();
	srand(time(0));
	turn = rand() % 2;
}

void Chess::displayTurnMsg(Player* A)
{
	u.gotoRowCol(13, 115);
	cout << A->getName();
	cout << (A->getColor() == Black ? " (Blue) " : " (Red) ");
	cout << "'s Turn!\n";
}

void Chess::selectPiece(int& pri, int& pci, int row, int col)
{
	int r, c;
	u.getRowColbyLeftClick(r, c);
	pri = (r / row) - 1;
	pci = (c / col) - 2;
}

bool Chess::validSrc(Player* A, int r, int c)
{
	if (r < 0 || r > 8 || c < 0 || c > 8)
		return false;
	Piece* P = B.getPiece(r, c);
	return P != nullptr && P->getColor() == A->getColor();
}

bool Chess::validDes(Player* A, int r, int c)
{
	if (r < 0 || r > 8 || c < 0 || c > 8)
		return false;
	Piece* P = B.getPiece(r, c);
	return P == nullptr || P->getColor() != A->getColor();
}

void Chess::changeTurn(Player* A)
{
	if (A->getColor() == White)
		turn = Black;
	else
		turn = White;
}

bool Chess::isLegalMove(Board b, int sr, int sc, int dr, int dc)
{
	Piece* P = b.getPiece(sr, sc);
	if (P->isValidMove(b, sr, sc, dr, dc))
		return true;
	return false;
}

bool** Chess::computeHighlight(Board b, int sr, int sc, int dim, Player* A)
{
	bool** bMap = new bool* [dim];
	for (int bi = 0; bi < dim; bi++)
		bMap[bi] = new bool[dim] {};
	int dr, dc;
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			dr = ri;
			dc = ci;
			if (validDes(A, dr, dc) && isLegalMove(b, sr, sc, dr, dc))
				bMap[ri][ci] = true;
		}
	}
	return bMap;
}

void Chess::BoxHighlight(bool**& M, Board b, int dim, int r, int c, Player* A)
{
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			if (M[ri][ci] == true)
			{
				u.SetClr(2);
				u.drawCell(b, ri * r + r, ci * c + c + c, 8, ri, ci);
			}
		}
	}
	u.SetClr(7);
}

void Chess::BoxUnhighlight(bool**& M, Board b, int dim, int r, int c, Player* A)
{
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			if (M[ri][ci] == true)
			{
				u.SetClr(0);
				u.drawCell(b, ri * r + r, ci * c + c + c, 8, ri, ci);
			}
		}
	}
	u.SetClr(7);
}

void Chess::findKing(Board b, int& dr, int& dc, int dim, Player* A)
{
	if (A->getColor() == White)
	{
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				Piece* P = b.getPiece(i, j);
				King* K = dynamic_cast<King*>(P);
				if (K != nullptr && P->getColor() == Black)
				{
					dr = i;
					dc = j;
				}
			}
		}
	}
	else if (A->getColor() == Black)
	{
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				Piece* P = b.getPiece(i, j);
				King* K = dynamic_cast<King*>(P);
				if (K != nullptr && P->getColor() == White)
				{
					dr = i;
					dc = j;
				}
			}
		}
	}
}

bool Chess::check(Board b, int dim, Player* A)
{
	int dr = 0, dc = 0;
	if (A->getColor() == White)
		A->c = Black;
	else
		A->c = White;
	findKing(B, dr, dc, dim, A);
	if (A->getColor() == White)
		A->c = Black;
	else
		A->c = White;
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			Piece* P = b.getPiece(ri, ci);
			if (P != nullptr && P->getColor() == A->getColor() && P->isValidMove(B, ri, ci, dr, dc))
				return true;
		}
	}
	return false;
}

bool Chess::selfCheck(Board B, int dim, int sr, int sc, int dr, int dc, Player* A)
{
	Board C;
	boardCopy(C, dim);
	C.move(sr, sc, dr, dc);
	if (A->getColor() == White)
		A->c = Black;
	else
		A->c = White;
	bool c = check(C, dim, A);
	/*if (A->getColor() == White)
		A->c = Black;
	else
		A->c = White;*/
	return c;
}

void Chess::boardCopy(Board& C, int dim)
{
	for (int i = 0; i < dim; i++)
		for (int j = 0; j< dim; j++)
			C.Ps[i][j] = B.Ps[i][j];
}

void Chess::play()
{
	int dim = 8, bDim = 10;
	while (true)
	{
		u.drawBoard(B, dim);
		displayTurnMsg(Ps[turn]);
		do
		{
			do
			{
				do
				{
					selectPiece(sri, sci, bDim, bDim);
				} while (!validSrc(Ps[turn], sri, sci));
				map = computeHighlight(B, sri, sci, dim, Ps[turn]);
				BoxHighlight(map, B, dim, bDim, bDim, Ps[turn]);
				selectPiece(dri, dci, bDim, bDim);
				BoxUnhighlight(map, B, dim, bDim, bDim, Ps[turn]); 
				if (selfCheck(B, dim, sri, sci, dri, dci, Ps[turn]))
				{
					u.SetClr(4);
					u.gotoRowCol(17, 115);
					cout << "SELF CHECK!!!";
				}
			} while (!selfCheck(B, dim, sri, sci, dri, dci, Ps[turn]));
			if (!map[dri][dci])
			{
				u.gotoRowCol(15, 115);
				cout << "Invalid MOVE...!!!";
			}
		} while (!map[dri][dci]);
		B.move(sri, sci, dri, dci);
		/*if (check(B, dim, Ps[turn]))
		{
			u.SetClr(4);
			u.gotoRowCol(17, 115);
			cout << "CHECK!!!";
			Sleep(100);
		}*/
		changeTurn(Ps[turn]);
	}
}