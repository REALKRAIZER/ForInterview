#ifndef VECT_H_
#define VECT_H_
#include <iostream>
namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode {RECT, POL};
	private:
		double x;
		double y;
		Mode mode;
		void setX(double length, double angle);
		void setY(double length, double angle);
	public:
		Vector();
		Vector(double n1, double n2, Mode mode = RECT);
		void reset(double n1, double n2, Mode mode = RECT);
		void setCoord(double n1, double n2, Mode mode = RECT);
		Vector operator + (const Vector & b) const;
		Vector operator - (const Vector & b) const;
		Vector operator * (const double n) const;
		friend Vector operator * (const double n, const Vector & b);
		Vector operator - () const;
		friend std::ostream & operator << (std::ostream & os, const Vector & b);
		~Vector() {};

		double getLength() const;
		double getAngle() const;
	};
}
#endif