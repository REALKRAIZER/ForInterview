#include "classic.h"
#include <iostream>
using namespace std;
void Bravo(const Cd & disk);
int main(int argc, char const *argv[])
{
	test Test;
	Test.report();
	Classic * p = &Test;
	p->report();
	 char * pp = nullptr;
	cout << pp;
	Cd c1("Beatles", "Captol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", Cd("Alfred Brendel", "Philips", 2, 57.17));
	Cd * pcd = &c1;

	cout << "Using object directly:\n";
	c1.report();
	c2.report();

	cout << "Using type cd * pointer to objects:\n";
	pcd->report();
	pcd = &c2;
	pcd->report();

	cout << "Calling a function with a cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment\n";
	Classic copy;
	copy = c2;
	copy.report();

	return 0;
}
void Bravo(const Cd & disk)
{
	disk.report();
}