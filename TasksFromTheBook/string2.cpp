#include "string2.h"
#include <cstring>

String::String() : len(0)
{
	str = nullptr;
	len = 0;
}
String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	std::cout << "HELLO!" << std::endl;
}
String::String(const String & a)
{
	this->len = a.len;
	this->str = new char[len + 1];
	std::strcpy(this->str, a.str);
}
String::~String()
{
	delete [] str;
}
String & String::operator=(const String & a)
{
	if(this == &a)
		return *this;
	this->len = a.len;
	delete [] this->str;
	this->str = new char[this->len + 1];
	std::strcpy(this->str, a.str);
	return *this;
}
char & String::operator[](int i)
{
	return str[i];
}
const char & String::operator[](int i) const
{
	return str[i];
}
bool operator < (const String & a, const String & b)
{
	return (std::strcmp(a.str, b.str) == -1);
}
bool operator>(const String & a, const String & b)
{
	return b < a;
}
bool operator==(const String & a, const String & b)
{
	return (std::strcmp(a.str, b.str) == 0);
}
std::ostream & operator<<(std::ostream & os, const String & b)
{
	return os << b.str;//return os << b.str
	//return os;
}
