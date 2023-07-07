#include <iostream>
#include "stack.h"
#include <cstring>
int main(int argc, char const *argv[])
{
	using namespace std;
	cout << "Please enter A to add a customer,\n" << "P to pop the customer, or Q to quit.\n";
	char ch;
	while (cin >> ch && toupper(ch)!= 'Q')
	{
		while(cin.get() != '\n')
			continue;
		if(!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch(ch) 
		{
			case 'a':
			case 'A':
				дальше лень делать
		}
	}
	return 0;
}