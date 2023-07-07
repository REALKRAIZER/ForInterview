#include <iostream>
#include <cstring.h>
Person::Person(const std::string & ln, const char * fn = "Heyyou")
{
	lname = ln;
	strncpy(fname,fn,LIMIT);
}
void Person::show() const
{
	using namespace std;
	cout <<  
}
void Person::FormatShow() const
{

}