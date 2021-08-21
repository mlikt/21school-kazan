
#ifndef __POINT_H__
# define __POINT_H__
# include "Fixed.hpp"

class Point
{
private:
	Fixed	const x;
	Fixed	const y;
public:
	Point();
	Point(Point const &copy);
	Point(float const &x, float const &y);
	Point &operator=(Point const &p);
	~Point() {}
	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
#endif

