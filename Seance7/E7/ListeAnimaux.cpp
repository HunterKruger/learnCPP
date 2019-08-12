// ListeAnimaux.cpp

#include <iostream>
#include "Animaux.h"
#include "ListeAnimaux.h"
using namespace std;

ListeAnimaux::ListeAnimaux ()
{
    nb = 0;
}

void ListeAnimaux::ajouter (Animal* pAnim)
{
    if (nb < TAILLE) {
        animaux[nb] = pAnim;
        nb++;
    }
}

void ListeAnimaux::afficher () const
{
    for (int i = 0; i < nb; i++) {
        cout << "**********" << endl;
        animaux[i]->afficher();
        animaux[i]->parler();
    }
}
