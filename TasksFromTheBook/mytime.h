#ifndef MYTIME_INCLUDED
#define MYTIME_INCLUDED
class Time
{
private:
	unsigned int hours;
	unsigned int minutes;
public:
	Time(unsigned int hours = 0, unsigned int minutes = 0);
	reset(unsigned int hours = 0, unsigned int minutes = 0);
	void addMin(unsigned int minutes = 0);
	void addHr(unsigned int hours = 0);
	friend unsigned int operator + (const Time & a, const Time & b);
}
#endif