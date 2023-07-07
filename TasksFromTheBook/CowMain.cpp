#include "cow.h"
int main(int argc, char const *argv[])
{
	const char * str = "Sleepy sleepy cow:(";
	Cow cow1("Bella", str, 500);
	Cow cow2("Billy", str, 750);
	cow1.ShowCow();
	cow2.ShowCow();
	cow2.operator=(cow1);
	cow2.ShowCow();
	return 0;
}