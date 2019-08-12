// ListeAnimaux.h

#pragma once
#include <iostream>
#include "Animaux.h"
using namespace std;

const int TAILLE = 100;

class ListeAnimaux
{
public :
    ListeAnimaux ();
    void ajouter (Animal* pAnim);
    void afficher () const;

private :
    Animal* animaux[TAILLE];  // tableau de pointeurs
    int nb;                   // nombre d'elements ajoutes au tableau
};
