#ifndef EXCMEAN_H_
#define EXCMEAN_H_
#include <iostream>
#include <stdexcept>
class mean_error : public std::expection
{
private:
	double v1;
	double v2;
	string errorStr;
public:
	mean_error(double a = 0, double b = 0, string er = "none") : v1(a), v2(b), errorStr(er) ;

	int getV1() { return v1; };
	int getV2() { return v2; };
	const char * what() = 0 const override { return errorStr.c_str(); };
	
};
class bad_hmean : public mean_error
{
public:
	bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {};
	const char * what();
};
const char * bad_hmean::what()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): "
		<< "invalid arguments: a = -b\n";
		return errorStr.c_str();
}
class bad_gmean : public mean_error
{
	bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {};
	const char * what();
};
const char * bad_gmean::what()
{
	return "gmean() arguments should be >= 0\n";
}
#endif