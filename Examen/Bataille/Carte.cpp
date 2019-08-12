#include <iostream>
#include "Carte.h"
using namespace std;

Carte::Carte()
{
	num = 0;
	couleur = 0;
}
Carte::Carte(int nu, int coul)
{
	num = nu;
	couleur = coul;
}

ostream& operator<<(ostream& flux, const Carte& cart)
{
	if (cart.num == 0 && cart.couleur == 0) {
		flux << "Carte nulle";
		return flux;
	}

	if(cart.num <= 10)
		flux << cart.num;
	else if (cart.num == VALET)
		flux << "Valet";
	else if (cart.num == DAME)
		flux << "Dame";
	else if (cart.num == ROI)
		flux << "Roi";
	else if (cart.num == AS)
		flux << "As";
	else
		flux << "numero inconnu";

	flux << " de ";
	if (cart.couleur == PIQUE)
		flux << "Pique";
	else if (cart.couleur == COEUR)
		flux << "Coeur";
	else if (cart.couleur == CARREAU)
		flux << "Carreau";
	else if (cart.couleur == TREFLE)
		flux << "Trefle";
	else
		flux << "couleur inconnue";

	return flux;
}

bool Carte::operator>(const Carte carte2) const
{
	return num > carte2.num || (num == carte2.num && couleur > carte2.couleur);
}

bool Carte::operator<(const Carte carte2) const
{
	return num < carte2.num || (num == carte2.num && couleur < carte2.couleur);
}

bool Carte::operator==(const Carte carte2) const
{
	return num == carte2.num && couleur == carte2.couleur;
}

bool Carte::operator!=(const Carte carte2) const
{
	return num != carte2.num || couleur != carte2.couleur;
}
