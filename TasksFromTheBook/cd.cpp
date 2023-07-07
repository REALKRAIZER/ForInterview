#include "cd.h"
#include <iostream>
#include <cstring>
Cd::Cd(const char * s1,const char * s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	strcpy(performers,s1);
	strcpy(label,s2);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd & d)
{
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers,d.performers);
	strcpy(label,d.label);
}
Cd & Cd::operator=(const Cd & d)
{
	if(this == &d)
		return *this;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers,d.performers);
	strcpy(label,d.label);
	return *this;
}
Cd::Cd() : selections(0), playtime(0)
{
	performers = nullptr;
	label = nullptr;
}
Cd::~Cd()
{
	std::cout << "CD DESTRUCTOR" << std::endl;
	delete [] performers;
	delete [] label;
}
void Cd::report() const
{
	using std::cout;
	using std::endl;
	cout << "\nCD\nPerformers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Playtime: " << playtime << endl;
}