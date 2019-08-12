// polygone.cpp

#include <iostream>
using namespace std;
#include "point.h"
#include "polygone.h"

Polygone::Polygone(const Point* t, int n)
{
	nb = n;
	tab = new Point[nb];
	for (int i = 0; i < nb; i++)
		tab[i] = t[i];
}
	
Polygone::Polygone(const Polygone& pol)
{
	nb = pol.nb;
	tab = new Point[nb];
	for (int i = 0; i < nb; i++)
		tab[i] = pol.tab[i];
}

Polygone::~Polygone()
{
	delete[] tab;
}


float Polygone::perimetre() const
{
	float perim=0;
	for (int i = 0; i < nb-1; i++)
		perim = perim + tab[i].distance(tab[i+1]);
	perim = perim + tab[nb - 1].distance(tab[0]);
	return perim;
}

void Polygone::afficher() const
{
	for (int i = 0; i < nb; i++)
	{
		tab[i].afficher();
		cout << "--";
	}
	tab[0].afficher();
	cout << endl;
}

Polygone Polygone::enveloppe() const
{
	Point* R;
	Point p, p0, q;
	int i=0;

	R = new Point[nb];
	p0 = extremeGauche();
	p = p0;
	do
	{
		R[i] = p;
		i++;
		q = autrePoint(p);
		for (int u = 0; u < nb; u++)
			if ((q.getX() - p.getX())*(tab[u].getY() - p.getY()) - (tab[u].getX() - p.getX())*(q.getY() - p.getY()) < 0)
				q = tab[u];
		p = q;
	} while (!p.egal(p0));

	Polygone res(R,i);
	delete[] R;
	return res;
}

Point Polygone::autrePoint(const Point& p) const
{
	if (!p.egal(tab[0]))
		return tab[0];
	else
		return tab[1];
}

Point Polygone::extremeGauche() const
{
	Point pt(tab[0]);

	for (int i = 1; i < nb; i++)
		if (tab[i].getX() < pt.getX() || (tab[i].getX() == pt.getX() && tab[i].getY() > pt.getY()))
			pt = tab[i];

	return pt;
}



