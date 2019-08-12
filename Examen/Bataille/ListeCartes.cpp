#include <iostream>
#include <stdlib.h>
#include "Carte.h"
#include "ListeCartes.h"
using namespace std;

ListeCartes::ListeCartes(int tai)
{
	cartes = new Carte[tai];
	taille = tai;
	nbCartes = 0;
}

ListeCartes::~ListeCartes()
{
	delete [] cartes;
}

ListeCartes::ListeCartes(const ListeCartes &liste2)
{
	creerParCopie(liste2);
}

ListeCartes& ListeCartes::operator=(const ListeCartes& liste2)
{
	if (this != &liste2) {
		delete [] cartes;
		creerParCopie(liste2);
	}
	return *this;
}

void ListeCartes::ajouter(const Carte &ca)
{
	if (nbCartes < taille)
	{
		cartes[nbCartes] = ca;
		nbCartes++;
	}
}

Carte ListeCartes::extraire()
{
	Carte premCarte = cartes[0];
	for (int i = 0; i < nbCartes - 1; i++)
		cartes[i] = cartes[i + 1];
	nbCartes--;
	return premCarte;
}

void ListeCartes::afficher() const
{
	for (int i = 0; i < nbCartes; i++)
		cout << cartes[i] << endl;
}

bool ListeCartes::contient(const Carte& ca) const
{
	int i = 0;
	while (i < nbCartes && cartes[i] != ca)
		i++;
	return i < nbCartes;
}

void ListeCartes::melanger()
{
	for (int i = 0; i < 1000; i++) {
		int numCarte1 = rand() % nbCartes;
		int numCarte2 = rand() % nbCartes;
		echangerCartes(numCarte1, numCarte2);
	}
}

void ListeCartes::creerParCopie(const ListeCartes& listeSource)
{
	cartes = new Carte[listeSource.taille];
	taille = listeSource.taille;
	nbCartes = listeSource.nbCartes;
	for (int i = 0; i < nbCartes; i++)
		cartes[i] = listeSource.cartes[i];
}

void ListeCartes::echangerCartes(int indiceCarte1, int indiceCarte2)
{
	Carte savCarte1 = cartes[indiceCarte1];
	cartes[indiceCarte1] = cartes[indiceCarte2];
	cartes[indiceCarte2] = savCarte1;
}
