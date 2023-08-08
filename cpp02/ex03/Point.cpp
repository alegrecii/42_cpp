#include "Point.hpp"

Point::Point() : _x(), _y()
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Point::Point(const Point &original) : _x(original._x), _y(original._y)
{
}

Point &Point::operator=(const Point &original)
{
	(void) original;
	return (*this);
}

float Point::getFloatX() const
{
	return (this->_x.toFloat());
}

float Point::getFloatY() const
{
	return (this->_y.toFloat());
}
