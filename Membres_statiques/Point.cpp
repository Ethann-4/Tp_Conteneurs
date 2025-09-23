#include "Point.h"

int Point::nbPoints = 0;

Point::Point()
{
	x = 0;
	y = 0;
	nbPoints++;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
	nbPoints++;
}

Point::~Point()
{
	nbPoints--;
}

int Point::compte()
{
	return nbPoints;
}

double Point::distance(Point& a, Point& b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - a.y) * (b.y - b.y));
}

Point Point::milieu(Point& a, Point& b)
{
	return Point((a.x + b.x) / 2 , (a.y + b.y) / 2);
}

