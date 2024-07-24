#include "Player.h"
#include<string>
using namespace std;
Player::Player(string n, Color c)
{
	this->name = n;
	this->c = c;
}
string Player::getName()
{
	return this->name;
}
Color Player::getColor()
{
	return this->c;
}