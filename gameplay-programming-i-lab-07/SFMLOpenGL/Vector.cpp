#include "Vector.h"



Vector::Vector()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector::Vector(double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;
}


Vector::~Vector()
{
}

void Vector::setX(double newX)
{
	x = newX;
}

void Vector::setY(double newY)
{
	y = newY;
}

void Vector::setZ(double newZ)
{
	z = newZ;
}

double Vector::getX()
{
	return x;
}

double Vector::getY()
{
	return y;
}

double Vector::getZ()
{
	return z;
}

double Vector::getLength()
{
	double length =(double)sqrt((x * x) + (y * y) + (z * z));
	return length;
}

double Vector::getLengthSquared()
{
	double length = (double)((x * x) + (y * y) + (z * z));
	return length;
}

void Vector::normalise()
{
	if (getLength() > 0.0)
	{  // Check for divide by zero
		double magnit = getLength();
		x = x / magnit;
		y = y / magnit;
		z = z / magnit;
	}
}

Vector Vector::operator +(Vector v2) const
{
	return Vector(x + v2.getX(), y + v2.getY(), z + v2.getZ());
}

Vector Vector::operator -(Vector v2) const
{
	return Vector(x - v2.getX(), y - v2.getY(), z - v2.getZ());
}

Vector Vector::operator -() const
{
	Vector v1 = Vector();
	v1.setX(-x);
	v1.setY(-y);
	v1.setZ(-z);
	return v1;
}

double Vector::operator *(Vector v2) const
{
	return (x * v2.getX() + y * v2.getY() + z * v2.getZ());
}

Vector Vector::operator *(double k) const
{
	return Vector(x * (float)k, y * (float)k, z * (float)k);
}

Vector Vector::operator *(float k) const
{
	return Vector(x * k, y * k, z * k);
}

Vector Vector::operator *(int k) const
{
	return Vector(x * k, y * k, z * k);
}

Vector Vector::operator ^(Vector v2) const
{
	return Vector(y * v2.getZ() - z * v2.getY(), z * v2.getX() - x * v2.getZ(), x * v2.getY() - y * v2.getX());
}