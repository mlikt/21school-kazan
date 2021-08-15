#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point (Point const &copy)
{
	*this = copy;
}

Point::Point (float const &x, float const &y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Fixed Point::getX( void ) const
{
	return (this->x);
}

Fixed Point::getY( void ) const
{
	return (this->y);
}

Point &Point::operator=(Point const &p)
{
	this->x = p.getX();
	this->y = p.getY();
	return (*this);
}

Fixed	LeftOrRightOrOnLine(Point const a, Point const b, Point const point)
{
	Fixed check;
	Fixed res;

	res = (a.getX() - point.getX()) * (b.getY() - a.getY()) - ((b.getX() - a.getX()) * (a.getY() - point.getY()));
	if (res > 0)
		check = check + 1;
	else if (res != 0)
		check = check - 1;
	else
		check = check + 0;
	return (check);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed check;

	check = check + LeftOrRightOrOnLine(a, b, point);
	check = check + LeftOrRightOrOnLine(b, c, point);
	check = check + LeftOrRightOrOnLine(c, a, point);
	if (check == 3 || check == -3)
		return (true);
	return (false);
}