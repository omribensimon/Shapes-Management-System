

#include "Quad.h"
#include "Shape.h"


Quad::Quad(double up, double down, double right, double left, const char* sn) : m_up(up) , m_down(down) , m_right(right),m_left(left) , Shape(sn) {} //constructor. center point = (0,0), name=sn

Quad::Quad(const Quad& other) : m_up(other.m_up), m_down(other.m_down), m_right(other.m_right), m_left(other.m_left), Shape(other) {}  //copy constructr


Quad::~Quad() {} //destructor

int Quad::calcArea() const //returns the quad's area (right*up) (rounded to int)
{
	return m_up * m_right;
	
}
	
 int Quad::calcPerimeter() const //returns the quad's Perimeter (the sum of the four ribs) (rounded to int)
 {
	
	 return  m_up + m_down + m_right + m_left;
	
 }