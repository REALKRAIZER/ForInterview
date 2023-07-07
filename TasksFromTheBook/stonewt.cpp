#include "stonewt.h"
#include <iostream>
Stonewt::Stonewt(double lbs)
{
	stone = int(lbs / Lbs_per_stn);
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = STN;
}
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	mode = STN;
}
Stonewt::Stonewt()
{
	stone = pds_left = pounds = 0;
	mode = STN;
}
Stonewt Stonewt::operator + (const Stonewt & a) const
{
	Stonewt res(stone + a.stone, 0);
	return res;
}
bool Stonewt::operator < (const Stonewt & b)
{
	return stone < b.stone;
}
bool Stonewt::operator > (const Stonewt & b)
{
	return stone > b.stone;
}
std::ostream & operator << (std::ostream & os, const Stonewt & b)
{
	if (b.mode == Stonewt::STN)
		os << "Stone: " << b.stone;
	else if (b.mode == Stonewt::PDS_INT)
		os << "Pound Int: " << int(b.pounds);
	else if (b.mode == Stonewt::PDS_FLOAT)
		os << "Pound Int: " << b.pounds;
	else
		os << "Error!";
	return os;
}