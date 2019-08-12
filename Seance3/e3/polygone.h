// polygone.h

#pragma once
using namespace std;
#include "point.h"

class Polygone
{
public:
	Polygone(const Point* t, int n);
	Polygone(const Polygone& pol);
	~Polygone();
	float perimetre() const;
	Polygone enveloppe() const;
	void afficher() const;
private:
	Point extremeGauche() const; // methode privee utile pour enveloppe
	Point autrePoint(const Point& p) const; // methode privee utile pour enveloppe
	Point* tab;
	int nb;
};

