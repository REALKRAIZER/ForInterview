#include "stonewt.h"
int main(int argc, char const *argv[])
{
	using namespace std;
	Stonewt test[6] {
		{3,13},
		{34,13},
		{3,13 3}
	};
	cout << test[0] << endl;
	return 0;
}