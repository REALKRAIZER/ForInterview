#include "dma.h"
#include <iostream>
const int MAX = 1;
int main(int argc, char const *argv[])
{
	using namespace std;
	int n;
	abcDma * p_obj[MAX];
	cout << "1 - baseDMA\n2 - lacksDMA\n3 - hasDMA\n";
	for (int i = 0; i < MAX; ++i)
	{
		while (cin >> n && n < 1 && n > 3)
			cout << "Введите 1, 2 или 3\n";
		switch (n)
		{
		case 1:
			p_obj[i] = new baseDMA;
			break;
		case 2:
			p_obj[i] = new lacksDMA;
			break;
		case 3:
			p_obj[i] = new hasDMA;
			break;
		}
	}
	for (int i = 0; i < MAX; ++i)
	{
		p_obj[i]->View();
	}
	for (int i = 0; i < MAX; ++i)
	{
		//p_obj[i]->~baseDMA();
		delete p_obj[i];
	}
	return 0;
}