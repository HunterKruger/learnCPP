#include <iostream>
#include "Carte.h"
#include "ListeCartes.h"
#include "Paquet.h"
using namespace std;

Paquet::Paquet()
	: ListeCartes(52)
{
}

void Paquet::ajouter(const Carte &ca)
{
	if (!contient(ca))
		ListeCartes::ajouter(ca);
}

Paquet Paquet::creerPaquetComplet()
{
	Paquet paquet52;
	for (int num = 2; num <= 14; num++) {
		for (int couleur = 1; couleur <= 4; couleur++) {
			Carte ca(num, couleur);
			paquet52.ajouter(ca);
		}
	}
	return paquet52;
}
