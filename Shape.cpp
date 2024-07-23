

#include "Shape.h"

int	Shape::s_totalNumOfShapes = 0;

Shape::Shape(const char* sn) //Creates a new shape (name=sn,centerPoint = (0,0))
{
	m_centerPoint = (0, 0);
	m_shapeName = new char[strlen(sn) + 1];
	strcpy(m_shapeName, sn);
	s_totalNumOfShapes++;
}

Shape::Shape(const Shape& other) //copy constructor of shape
{
	m_shapeName = new char[strlen(other.m_shapeName) + 1];
	strcpy(m_shapeName, other.m_shapeName);
	m_centerPoint = Point(other.m_centerPoint);
	s_totalNumOfShapes++;
	
}

Shape::~Shape() //shape destructor
{
	delete[] m_shapeName;
	m_shapeName = nullptr;
	s_totalNumOfShapes--;
	
}


void Shape::setName(const char* name)	//sets the shape's name
{
	if (m_shapeName != nullptr)
	{
		delete[] m_shapeName;
	}
	this->m_shapeName = new char[strlen(name) + 1];
	strcpy(m_shapeName, name);
	
}

void Shape::setCenter(const Point& p) 	//sets the center point
{
	m_centerPoint = p;
}

const char* Shape::getName() const //returns the shape's name
{
	return m_shapeName;
}

Point Shape::getCenter() const //returns the center point
{
	return m_centerPoint;
}

void Shape::setShape(const char* sn, const Point& other) //set the shape's name and the center point
{
	setName(sn);
	setCenter(other);

}

int Shape::numOfShapes() //returnS the total number of shapes
{
	return s_totalNumOfShapes;
}

const Shape& Shape::operator=(const Shape& other) //operator=
{
	if (this != &other)
	{
		delete[] m_shapeName;
		m_shapeName = new char[strlen(other.m_shapeName) + 1];
		strcpy(m_shapeName, other.m_shapeName);
		m_centerPoint = other.m_centerPoint;
	}
	return *this;
}
