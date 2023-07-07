#include <iostream>
#include "Move.h"
Move::Move(double a, double b)
{
	x = a;
	y = b;
}
void Move::showmove() const
{
	using namespace std;
	cout << x << endl << y << endl;
}
Move Move::add(const Move & m) 
{
	*this = m;
	return *this;
}
void Move::reset(double a, double b)
{
	x = a;
	y = b;
}