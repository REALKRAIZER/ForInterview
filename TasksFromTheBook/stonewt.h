#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
public:
	enum Mode{STN, PDS_INT, PDS_FLOAT};
private:
	static const int Lbs_per_stn = 14;
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
public:
	 explicit Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	void setMode(Mode mode) {this->mode = mode;};
	Stonewt operator + (const Stonewt & a) const;
	bool operator < (const Stonewt & b);
	bool operator > (const Stonewt & b);
	friend std::ostream & operator << (std::ostream & os, const Stonewt & b);
};
#endif