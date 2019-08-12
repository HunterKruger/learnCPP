#include <iostream>
#include "Carte.h"
#include "Paquet.h"
#include "Joueur.h"
using namespace std;

Joueur::Joueur()
	: paquetCartes()
{
}

void Joueur::prendreCarte(const Carte& ca)
{
	paquetCartes.ajouter(ca);
}

Carte Joueur::jouerCarte()
{
	return paquetCartes.extraire();
}

void Joueur::afficherCartes() const
{
	paquetCartes.afficher();
}

