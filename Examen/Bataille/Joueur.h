#include <iostream>
#include "Carte.h"
#include "Paquet.h"
using namespace std;

#pragma once

class Joueur
{
public :
	Joueur();
	void prendreCarte(const Carte& ca);
	Carte jouerCarte();
	void afficherCartes() const;
	int nbCartes() const		{ return paquetCartes.getNbCartes(); }

private :
	Paquet paquetCartes;
};
