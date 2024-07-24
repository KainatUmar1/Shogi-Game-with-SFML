#pragma once
#include<string>
#include"Utility.h"
using namespace std;
class Player
{
	string name;
public:
	Color c;
	Player(string n,Color c);
	string getName();
	Color getColor();
};

