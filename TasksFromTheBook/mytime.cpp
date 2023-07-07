#include "mytime.h"
Time::Time(unsigned int hours, unsigned int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
}
Time::reset(unsigned int hours, unsigned int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
}
void Time::addHr(unsigned int hours)
{
	this->hours += hours;
}
void Time::addMin(unsigned int minutes)
{
	this->minutes += minutes;
	this->hours += this->minutes / 60;
	this->minutes %= 60;
}
Time operator + (const Time & a, const Time & b)
{
	Time sum;
	sum.minutes = a.minutes + b.minutes;
	sum.hours
}