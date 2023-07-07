#ifndef PERSON_H
#define PERSON_H
#include <iostream>
class Person
{
private:
	std::string name;
	std::string surname;
protected:
	virtual void Data() const;
public:
	Person(const std::string & n, const std::string & sn) : name(n), surname(sn);
	virtual void Show() const;
	virtual ~Person() {};
};
class Gunslinger : virtual public Person
{
private:
	int nutchCount;
	double time;
protected:
	void Data() const;
public:
	Gunslinger(const std::string & n, const std::string & sn, int nutch, int t) : Person(n, sn), nutchCount(nutch), time(t);
	void Show() const;
	double Draw() { return time; } const;
}
#endif