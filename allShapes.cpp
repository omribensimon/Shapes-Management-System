

#define _CRT_SECURE_NO_WARNINGS 
#include "allShapes.h"
#include"Circle.h"
#include"Point.h"
#include"Quad.h"
#include"Shape.h"
#include"Square.h" 


allShapes::allShapes() : m_arr(nullptr), m_size(0) {} // constructor, zero elements

allShapes::allShapes(const allShapes& other) //copy c'tor - deep copy
{
	m_arr = nullptr;
	m_size = 0;

	m_arr = new Shape * [other.m_size];
	for (int i = 0; i < other.m_size; i++)
	{
		if (typeid(*other.m_arr[i]) == typeid(Circle))
		{
			m_arr[i] = new Circle(*static_cast<Circle*>(other.m_arr[i]));
		}
		if (typeid(*other.m_arr[i]) == typeid(Square))
		{
			m_arr[i] = new Square(*static_cast<Square*>(other.m_arr[i]));
		}
		if (typeid(*other.m_arr[i]) == typeid(Quad))
		{
			m_arr[i] = new Quad(*static_cast<Quad*>(other.m_arr[i]));
		}
	}
	m_size = other.m_size;
}

allShapes::~allShapes() //destructor to all elements
{
	
		for (int i = 0; i < m_size; ++i)
		{
			delete m_arr[i];
		}

		delete[] m_arr;
	
}

int allShapes::getSize() const	//returns the number of shapes;
{
	return m_size;
}

void allShapes::addShape(Shape* newShape) //add a new shape (deep copy) to the end of array
{
	Shape** NewArray = new Shape * [m_size + 1];
	for (int i = 0; i < m_size; i++)
	{
		NewArray[i] = m_arr[i];
	}
	if (typeid (*newShape) == typeid(Circle))
	{
		NewArray[m_size] = new Circle(*static_cast<Circle*>(newShape));
	}
	if (typeid (*newShape) == typeid(Square))
	{
		NewArray[m_size] = new Square(*static_cast<Square*>(newShape));
	}
	if (typeid (*newShape) == typeid(Quad))
	{
		NewArray[m_size] = new Quad(*static_cast<Quad*>(newShape));

	}
	delete[] m_arr;
	m_arr = NewArray;
	m_size++;
}


void allShapes::removeShape(int index) //remove shape by index
{
	Shape** newArray = new Shape * [m_size - 1];
	for (int i = 0; i < index; i++)
	{
		newArray[i] = m_arr[i];
	}
	delete m_arr[index];
	for (int i = index; i < m_size - 1; i++)
	{
		newArray[i] = m_arr[i + 1];
	}
	delete[] m_arr;
	m_arr = newArray;
	m_size--;
}



int allShapes::totalArea() const //returns the total area of all the shapes (rounded to int)
{
	int totalArea = 0;

	for (int i = 0; i < m_size; ++i)
	{
		totalArea += m_arr[i]->calcArea();
	}
	return totalArea;
}

int allShapes::totalPerimeter() const	//returns the total Perimeter of all the shapes (rounded to int)
{
	int totalPerimeter = 0;

	for (int i = 0; i < m_size; i++)
	{
		totalPerimeter += m_arr[i]->calcPerimeter();
	}
	return totalPerimeter;
}

int allShapes::totalCircleArea() const	//returns the total sum of circle areas (rounded to int)
{
	int totalArea = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (dynamic_cast<Circle*> (m_arr[i]))
		{
			totalArea += m_arr[i]->calcArea();
		}
	}
	return totalArea;
}



int allShapes::totalSquarePerimeter() const //returns the total sum of squar Perimeter (rounded to int)
{
	int totalPerimeter = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (dynamic_cast<Square*> (m_arr[i]))
		{
			totalPerimeter += m_arr[i]->calcPerimeter();
		}
	}
	return totalPerimeter;
}

const allShapes& allShapes::operator+=(Shape* newS) //adds a new shape
{
	this->addShape(newS);
	return *this;
}


Shape* allShapes::operator[](int ind) const //returns the shape located at index ind
{
	if (ind >= 0 || ind < m_size) 
	{
		return m_arr[ind];
	}

	return nullptr;
}

allShapes allShapes::operator+(const allShapes& other) const //returns a new allShape with all elements located at this and other
{
	allShapes newArray(*this);
	for (int i = 0; i < other.m_size; i++)
	{
		newArray.addShape(other.m_arr[i]);
	}
	return newArray;
}

allShapes::operator int() const //returns the number of elements	
{
	return m_size;
}