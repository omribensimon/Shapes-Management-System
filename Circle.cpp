

#include "Circle.h"



Circle::Circle(double r , const char* sn)  //create a circle with radius=1, name=sn and center=(0,0)
{
	sn = nullptr;
	m_radius = r;
	m_centerPoint = (0, 0);
}

Circle::Circle(const Circle& other) : Shape(other), m_radius(other.m_radius) //copy constructor
{}




double Circle::getRadius() const //returns the circle's radius
{
	return m_radius;
}

void Circle::setRadius(double r) //set the radius
{
	m_radius = r;
}

int Circle::calcArea() const //returns the circle's area (rounded to int)
{
	return PI * m_radius * m_radius;  
}

int Circle::calcPerimeter() const //returns the circle's Perimeter (rounded to int)
{
	return 2 * PI * m_radius;  

}

Circle operator+(int r, const Circle& other)	//returns a new Circle with added radius
{
	return Circle(other.m_radius + r);
}

const Circle& Circle::operator=(const Circle& other) //operator= that copies all
{
	if (this != &other)
	{
		setName(other.getName());
		setCenter(other.getCenter());
		m_radius = other.m_radius;
	}
	return *this;
}
const Circle& Circle::operator=(const char* name)	//updates only the name of the shape and returns the updated shape
{
	setName(name);
	return *this;
}

