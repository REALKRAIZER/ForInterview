#include <iostream>
#include "golf.h"
int main(int argc, char const *argv[])
{
	const int ARR_SIZE = 3;

	golf ann = golf("Ann Birdfree", 24);
	ann.showgolf();

	golf players[ARR_SIZE];
	int k = 0;
	for (; k < ARR_SIZE; ++k) 
	{
		if (!players[k].setgolf()) break;
	}
	for (int i = 0; i < k; ++i) 
	{
		players[i].showgolf();
	}
	return 0;
}