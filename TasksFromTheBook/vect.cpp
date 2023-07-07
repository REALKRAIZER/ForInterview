#include <iostream>
#include <cmath>
#include "vect.h"
namespace VECTOR
{
	const double RadToDeg = 45.0 / atan(1.0);
	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode mode)
	{
		setCoord(n1,n2,mode);
	}
	void Vector::reset(double n1, double n2, Mode mode)
	{
		setCoord(n1,n2,mode);
	}
	void Vector::setCoord(double n1, double n2, Mode mode)
	{
		this->mode = mode;
		if (mode == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (mode == POL)
		{
			double angle = n2 / RadToDeg;
			setX(n1, angle);
			setY(n1, angle);
		}
		else
		{
			std::cout << "Неккоректный 3 ий аргумент" << std::endl;
			x = y = 0.0;
			this->mode = RECT;
		}
	}
	void Vector::setX(double length, double angle)
	{	
		x = length * cos(angle);
	}
	void Vector::setY(double length, double angle)
	{
		y = length * sin(angle);
	}
	double Vector::getLength() const 
	{
		if (x == 0 && y == 0)
			return 0;
		else
			return sqrt(x * x + y * y);
	}
	double Vector::getAngle() const
	{
		if (x == 0 && y == 0)
			return 0;
		else
			return atan2(y, x);
	}
	Vector Vector::operator + (const Vector & b) const 
	{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator - (const Vector & b) const 
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator * (const double n) const 
	{
		return Vector(x * n, y * n);
	}
	Vector operator * (const double n, const Vector & b) 
	{
		return b * n;
	}
	Vector Vector::operator - () const
	{
		return Vector(-x, -y);
	}
	std::ostream & operator << (std::ostream & os, const Vector & b)
	{
		if (b.mode == Vector::RECT){
			os << "X: " << b.x << std::endl << "Y: " << b.y;
		}
		else if (b.mode == Vector::POL) {
			os << "Length: " << b.getLength() << std::endl
			<< "Angle: " << b.getAngle();
		}
		else {
			os << "Неккоректный режим объекта Vector\n";
		}
		return os;
	}
}