#ifndef STRING2_INCLUDED
#define STRING2_INCLUDED
#include <iostream>
class String
{
private:
	char * str;
	unsigned int len;
public:
	String();
	explicit String(const char *);//explicit
	String(const String &);
	~String();
	unsigned int length() {return len;};
	
	String & operator=(const String &);
	char & operator[](int i);
	const char & operator[](int i) const;

	friend bool operator < (const String & a, const String & b);
	friend bool operator>(const String & a, const String & b);
	friend bool operator==(const String & a, const String & b);
	friend std::ostream & operator<<(std::ostream &, const String & b);
};

#endif