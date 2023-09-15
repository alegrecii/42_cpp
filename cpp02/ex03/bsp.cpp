#include "Point.hpp"

bool	borderChecker(Point const a, Point const b, Point const p)
{
	float	m = (b.getFloatY() - a.getFloatY()) / (b.getFloatX() - a.getFloatX());
	if (p.getFloatY() == a.getFloatY() + m * (p.getFloatX() - a.getFloatX()))
	{
		if ((p.getFloatY() >= a.getFloatY() && p.getFloatY() <= b.getFloatY()) || (p.getFloatY() >= b.getFloatY() && p.getFloatY() <= a.getFloatY()))
			return (false);
	}
	return (true);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float u, v, w;


	u = ((b.getFloatY() - c.getFloatY()) * (point.getFloatX() - c.getFloatX()) +
		(c.getFloatX() - b.getFloatX()) * (point.getFloatY() - c.getFloatY())) /
		((b.getFloatY() - c.getFloatY()) * (a.getFloatX() - c.getFloatX()) +
		(c.getFloatX() - b.getFloatX()) * (a.getFloatY() - c.getFloatY()));

	v = ((c.getFloatY() - a.getFloatY()) * (point.getFloatX() - c.getFloatX()) +
		(a.getFloatX() - c.getFloatX()) * (point.getFloatY() - c.getFloatY())) /
		((b.getFloatY() - c.getFloatY()) * (a.getFloatX() - c.getFloatX()) +
		(c.getFloatX() - b.getFloatX()) * (a.getFloatY() - c.getFloatY()));

	w = 1 - u - v;
	if (borderChecker(a,c,point) && borderChecker(a,b,point) && borderChecker(b,c,point))
		return ((u >= 0) && (v >= 0) && (w >= 0));
	else
		return (false);
}
