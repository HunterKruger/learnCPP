// segment.h

#pragma once
using namespace std;
#include "point.h"

class Segment
{
public :
    Segment (const Point& a, const Point& b);
    void translation (const Point& nouvOrg);
    void afficher () const;

private :
    Point org, ext;
};

