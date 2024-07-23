
#include "Point.h"

Point::Point(int x , int y) : m_x(x) , m_y(y){}




Point::Point(const Point& other) : m_x(other.m_x), m_y(other.m_y) {}


Point::~Point() {}


int Point::getX() const //returns the x
{
	return m_x;
}

int Point::getY() const //returns the y
{
	return m_y;
}

void Point::setX(int x) //sets the x
{
	m_x = x;
}

void Point::setY(int y) //sets the y
{
	m_y = y;
}

void Point::setPoint(int x, int y) //sets the x and y
{
	m_x = x;
	m_y = y;
}

void Point::setPoint(const Point& other) //sets the point with other values
{
	m_x = other.m_x;
	m_y = other.m_y;
}

bool Point::operator==(const Point& other) const //returns true if and only if the two points are equal
{
	return (m_x == other.m_x) && (m_y == other.m_y) == 0;
}

bool Point::operator!=(const Point& other) const //returns true if and only if the two points are not equal
{
	return (m_x != other.m_x) || (m_y != other.m_y);
}

Point Point::operator+(int num) const //returns a new point with updated x(x+num) and y(y+num)
{
	return Point(m_x + num, m_y + num);
}

const Point& Point::operator+=(int num) //updates the point with x(x+num) and y(y+num) and returns the updated point
{
	m_x += num;
	m_y += num;
	return *this;
}

Point::operator int() const //returns the sum of x and y
{
	int sum = 0;
	sum = m_x + m_y;

	return sum;
}

Point Point::operator+(const Point& other) const //adds coordinates (x,y) and returns a new point
{
	return Point(m_x + other.m_x, m_y + other.m_y);

}

Point Point::operator++(int) //adds 1 to x and y and returns the updated point - postfix
{
	Point temp(*this);
	++(*this);
	return temp;
}

const Point& Point::operator++() //adds 1 to x and y and returns the updated point - prefix
{
	++m_x;
	++m_y;
	return *this;
}

Point operator*(int num, const Point& other) //returns a new point with (x,y)*num
{
	return Point(other.m_x * num, other.m_y * num);
}