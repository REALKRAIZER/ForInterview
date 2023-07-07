#include "cow.h"
#include <iostream>
#include <cstring>
using std::strcpy;
using std::strlen;
using std::cout;
using std::endl;
Cow::Cow()
{
	name[0] = '\0';
	hobby = nullptr;
	weight = 0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
	strcpy(name, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}
Cow::~Cow()
{
	cout << "Destructor for " << hobby << endl;
	delete [] hobby;
}
Cow & Cow::operator=(const Cow & c)
{
	if(this == &c)
		return *this;
	delete [] hobby;
	this->hobby = new char[strlen(c.hobby) + 1];
	strcpy(this->hobby, c.hobby);
	strcpy(name, c.name);
	weight = c.weight;
	return *this;
}
void Cow::ShowCow() const
{
	cout << name << endl;
	cout << hobby << endl;
	cout << weight << endl;
}

