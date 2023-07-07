#include <iostream>
#include <valarray>
#define MAX 32000
#define MIN -32000
int main(int argc, char const *argv[])
{
	std::valarray<long int> arr(5);
	long int n;
	for(int i = 0; i < 2; ++i)
	{
		std::cin >> n;
		if(n >= -32000 && n <= 32000)
			arr[i] = n;
	}
	std::cout << arr.sum();

	return 0;
}