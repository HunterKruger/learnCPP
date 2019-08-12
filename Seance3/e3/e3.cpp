// e3.cpp

#include <iostream>
using namespace std;
#include "point.h"
#include "segment.h"
#include "polygone.h"


int main ()
{
    Point A(1,2), B(8,5), C(15,20);
    A.setX (3);
    A.setY (4);
    cout << A.getX() << "," << A.getY() << endl;

    Segment S1(A,B);
    S1.afficher ();

    cout << "apres translation en ("<<C.getX()<< ","<<C.getY()<<") :" << endl;
    S1.translation (C);
    S1.afficher ();

	cout << endl << endl;

	Point tableau[6] = { Point(0,0),Point(0,4),Point(2,2),Point(6,4), Point(4,-1), Point(6,-8) };

	Polygone p(tableau, 6);
	cout << p.perimetre();
	p.afficher();

	Polygone env(p.enveloppe());
	cout << env.perimetre();
	env.afficher();

    return 0;
}
