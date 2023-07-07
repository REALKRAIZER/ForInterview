#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long int n, m;
	cin >> n;
	cin >> m;
	int i = 0;

	for(; n > 0 && m > 0; ++i)
	{
		if((i+1) % 2)
		{
			n -= (i + 1);
			m += (i + 1);
		}
		else
		{
			m -= (i + 1);
			n += (i + 1);
		}
	}
	cout << i;
	return 0;
}