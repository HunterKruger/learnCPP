#include <iostream>
using namespace std;

#pragma once

const int VALET = 11;
const int DAME = 12;
const int ROI = 13;
const int AS = 14;

const int TREFLE = 1;
const int CARREAU = 2;
const int COEUR = 3;
const int PIQUE = 4;

class Carte
{
public :
	Carte();
	Carte(int nu, int coul);
	friend ostream& operator<<(ostream& flux, const Carte& cart);
	int getNumero() const				{ return num; }
	int getCouleur() const				{ return couleur; }
	void setNumero(int nouvNum)			{ num = nouvNum; }
	void setCouleur(int nouvCouleur)	{ num = nouvCouleur; }
	bool operator>(const Carte carte2) const;
	bool operator<(const Carte carte2) const;
	bool operator==(const Carte carte2) const;
	bool operator!=(const Carte carte2) const;

private :
	int num;
	int couleur;
};