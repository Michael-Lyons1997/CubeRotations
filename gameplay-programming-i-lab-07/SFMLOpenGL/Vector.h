#pragma once
#include <cmath>
class Vector
{
public:
	Vector();
	Vector(double x1, double y1, double z1);
	~Vector();
	void setX(double newX);
	void setY(double newY);
	void setZ(double newZ);
	double getX();
	double getY();
	double getZ();
	double getLength();
	double getLengthSquared();
	void normalise();
	Vector operator +(Vector v2) const;
	Vector operator -(Vector v2) const;
	Vector operator -() const;
	double operator *(Vector v2) const;
	Vector operator *(double k) const;
	Vector operator *(float k) const;
	Vector operator *(int k) const;
	Vector operator ^(Vector v2) const;
protected:
	double x;
	double y;
	double z;
};

