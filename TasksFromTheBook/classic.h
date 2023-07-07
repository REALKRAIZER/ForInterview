#ifndef CLASSIC_INCLUDED
#define CLASSIC_INCLUDED
#include "cd.h"
class Classic : public Cd
{
private:
	char * mainLabel;
public:
	Classic();
	Classic(const char * s1,const Cd & d);
	Classic(const Classic & d);
	Classic & operator=(const Classic & d);
	void report() const override;
	virtual ~Classic();
};
class test : public Classic
{
private:
	int n;
public:
	test();
	void report() const override;
};
#endif