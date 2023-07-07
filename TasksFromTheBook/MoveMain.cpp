#include <iostream>
#include "Move.h"
int main(int argc, char const *argv[])
{
	 Move a(2.2, 3.3);
    a.showmove();
 
    a.add(a);
    a.showmove();
 
    a.reset();
    a.showmove();

	return 0;
}