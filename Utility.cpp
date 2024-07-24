#include"Utility.h"
#include<Windows.h>
#include<iostream>
using namespace std;

void Utility::getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}

void Utility::gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void Utility::SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}

void Utility::label(int r, int c)
{
	int X[] = { 1,2,3,4,5,6,7,8 };
	char Y[] = { 'A','B','C','D','E','F','G','H' };
	SetClr(7);
	for (int i = 0; i < 8; i++)
	{
		gotoRowCol(r - 3, c + 6);
		cout << Y[i];
		c += 10;
	}
	for (int i = 0; i < 8; i++)
	{
		gotoRowCol(r + 5, c - 82);
		cout << X[i];
		r += 10;
	}
}

void Utility::drawCell(Board b, int sr, int sc, int para, int a, int c)
{
	char sym = -37;
	if (para == 8)
	{
		for (int i = 0; i < para + 1; i++)
		{
			gotoRowCol(sr, sc++);
			cout << sym;
		}

		for (int i = 0; i < para + 1; i++)
		{
			gotoRowCol(sr++, sc);
			cout << sym;
		}

		for (int i = 0; i < para + 1; i++)
		{
			gotoRowCol(sr, sc--);
			cout << sym;
		}

		for (int i = 0; i < para + 1; i++)
		{
			gotoRowCol(sr--, sc);
			cout << sym;
		}
	}
	if (para == 10)
	{
		int p = sc;
		for (int i = 0; i < para; i++)
		{
			sc = p;
			for (int j = 0; j < para; j++)
			{
				gotoRowCol(sr, sc++);
				cout << sym;
			}
			cout << endl;
			sr++;
		}
		b.displayBoard(a, c, sr - para / 2 - 1, sc - para / 2 - 1);
	}
}

void Utility::drawBoard(Board b, int dim)
{
	system("cls");
	label(dim + 2, dim + 10);
	char sym = -37;
	for (int r = 1; r <= dim; r++)
	{
		for (int c = 1; c <= dim; c++)
		{
			if ((r + c) % 2 == 0)
				SetClr(0);
			else
				SetClr(15);
			drawCell(b, r * 10, c * 10 + 10, 10, r - 1, c - 1);
		}
		cout << endl;
	}
	SetClr(7);
}