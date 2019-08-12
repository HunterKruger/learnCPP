// point.h

#pragma once
#include <iostream>
#include "math.h"
using namespace std;

class Point
{
public :
	Point()						{ x = 0; y = 0; }
    Point (float x0, float y0)	{ x= x0; y = y0; }
    float getX () const			{ return x; }
    float getY () const			{ return y; }
	void setX (float nx)		{ x = nx; }
    void setY (float ny)		{ y = ny; }
	bool egal(const Point& p) const			{ return x == p.x && y == p.y; }
	float distance(const Point& p) const	{ return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y)); }
	void afficher() const					{ cout << "(" << x << ";" << y << ")"; }
private :
    float x, y;
};

