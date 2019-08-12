#include <iostream>
#include "Segment.h"
#include "Polygone.h"
using namespace std;

int main() {
    Point p1(3.0,4.0);
    Point p2(5.0,6.0);
    Point p3(5.0,6.0);
    p2.display();
    cout<<p2.isEqual(p3)<<endl;
    cout<<p2.distance(p1)<<endl;

    Segment s1(1.0,2.0,3.0,4.0);
    s1.display();
    Point newP(0.0,1.0);
    s1.translation(newP);

    Point pointTab[3]={Point(0,0),Point(0,4),Point(2,2)};
    Polygone polygone(pointTab,3);
    polygone.display();
    cout<<endl;
    cout<<polygone.perimeter()<<endl;

    return 0;
}