

#include "Quad.h"
#include "Square.h"

Square::Square(double up, double down, double right, double left, const char* sn) : Quad(up, down, right, left, sn) //constructor. center point = (0,0), name=sn
{}


	
Square::~Square() //destructor
{}

void Square::shiftX(int x)
{
	Point p(this->m_centerPoint.getX(), this->m_centerPoint.getY());
	this->setCenter(p); // Set the new center point.
}
// Shifts the center of the square along the y-axis by the specified amount.
void Square::shiftY(int y)
{

	Point pCenter(this->m_centerPoint.getX(), this->m_centerPoint.getY() + y);
	this->setCenter(pCenter); // Set the new center point.
}