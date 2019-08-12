//
// Created by 冯源 on 2018/9/9.
//

#ifndef E2_ENSEMBLE_H
#define E2_ENSEMBLE_H

#endif //E2_ENSEMBLE_H

// ensemble.h

#pragma once
using namespace std;

const int TAILLE = 100;    // nb max d'elements dans un ensemble

class Ensemble
{
public :
    Ensemble ();
    void ajouter (int x);
    void retirer (int x);
    bool contient (int x) const;
    bool estEgal (const Ensemble& ens2) const;
    void afficher () const;
    Ensemble intersection(const Ensemble& ens2) const;
    Ensemble extraitNombresPremiers() const;

private :
    int elem [TAILLE];    // elements de l'ensemble
    int nbElem;           // nb d'elements presents dans l'ensemble

    int chercher (int x) const; // cherche x dans l'ensemble, retourne son
    // indice dans elem ou -1 si non trouve
};


