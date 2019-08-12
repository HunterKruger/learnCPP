#include <iostream>
#include "Carte.h"
using namespace std;

#pragma once

class ListeCartes
{
public :
	ListeCartes(int tai);
	~ListeCartes();
	ListeCartes(const ListeCartes& liste2);
	ListeCartes& operator=(const ListeCartes& liste2);
	void ajouter(const Carte& ca);
	Carte extraire();
	void afficher() const;
	bool contient(const Carte& ca) const;
	int getNbCartes() const		{ return nbCartes; }
	void melanger();

private :
	Carte *cartes;
	int taille;
	int nbCartes;

	void creerParCopie(const ListeCartes& listeSource);
	void echangerCartes(int indiceCarte1, int indiceCarte2);
};
