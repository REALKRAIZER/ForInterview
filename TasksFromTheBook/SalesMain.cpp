#include <iostream>
#include "sales.h"

int main(int argc, char const *argv[])
{
	using namespace SALES;
	double a[] {2.0, 2.0,4.0,4.0};
	SALES::Sales s1;
	SALES::setSales(s1, a, 4);
	SALES::showSales(s1);
	return 0;
}