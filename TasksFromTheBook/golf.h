#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
class golf {
private:
	static const int Len = 40;
	char m_fullname[Len];
	int m_handicap;
public:
	golf(const char * name, int hc);
	golf() {}
	int setgolf();
	void handicap(int hc);
	void showgolf() const;
};
#endif