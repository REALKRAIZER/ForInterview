#include "classic.h"
#include <iostream>
#include <cstring>
Classic::Classic() : Cd()
{
	mainLabel = nullptr;
}
Classic::Classic(const char * s1,const Cd & d) : Cd(d)
{
	mainLabel = new char[strlen(s1) + 1];
	strcpy(mainLabel, s1);
}
Classic::Classic(const Classic & d) : Cd(d)
{
	mainLabel = new char[strlen(d.mainLabel) + 1];
	strcpy(mainLabel, d.mainLabel);
}
Classic & Classic::operator=(const Classic & d)
{
	if(this == &d)
		return *this;
	Cd::operator=(d);
	mainLabel = new char[strlen(d.mainLabel) + 1];
	strcpy(mainLabel, d.mainLabel);
	return *this;
}
void Classic::report() const
{
	using std::cout;
	using std::endl;
	Cd::report();
	cout << "CLASSIC\nMain label: " << mainLabel << endl;
}
Classic::~Classic()
{
	std::cout << "CLASSIC DESTRUCTOR" << std::endl;
	delete [] mainLabel;
}

test::test() : Classic()
{

}
void test::report() const
{
	std::cout << "\n\nTEST\n\n";
}