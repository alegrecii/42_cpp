#include "Fixed.hpp"


class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &original);
	Point	&operator=(const Point &original);
	float	getFloatX() const;
	float	getFloatY() const;
	~Point();
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);


