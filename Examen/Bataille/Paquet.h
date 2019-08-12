#include <iostream>
#include "Carte.h"
#include "ListeCartes.h"
using namespace std;

#pragma once

class Paquet : public ListeCartes
{
public :
	Paquet();
	void ajouter(const Carte& ca);
	static Paquet creerPaquetComplet();

private :
};
