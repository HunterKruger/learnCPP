//
// Created by 冯源 on 2018/9/9.
//

// ensemble.cpp

#include <iostream>
using namespace std;

#include "math.h"
#include "ensemble.h"


Ensemble::Ensemble ()
{
    nbElem = 0;
}

void Ensemble::ajouter (int x)
{
    // on verifie qu'il y a de la place dans l'ensemble
    if (nbElem < TAILLE)
    {
        // x est ajoute seulement s'il n'est pas deja dans l'ensemble
        if (!contient(x))
        {
            elem [nbElem] = x;
            nbElem++;
        }
    }
}

void Ensemble::retirer (int x)
{
    int indice_x;

    indice_x = chercher (x);

    // si x a ete trouve dans l'ensemble
    if (indice_x >= 0)
    {
        // pour retirer x on peut decaler les elements suivants ou le remplacer
        // par le dernier element (solution retenue)
        elem [indice_x] = elem [nbElem - 1];
        nbElem--;
    }
}

bool Ensemble::contient (int x) const
{
    bool contenance;

    if (chercher(x) >= 0)
        contenance = true;
    else
        contenance = false;

    return contenance;
}

bool Ensemble::estEgal (const Ensemble& ens2) const
{
    // les ensembles sont egaux s'ils ont meme nb d'elements et si l'un des 2
    // contient chaque element de l'autre

    bool egaux;

    if (nbElem != ens2.nbElem)
        egaux = false;
    else
    {
        // test pour savoir si ens2 contient chaque element de l'ensemble
        // courant

        int i = 0;
        while (i < nbElem && ens2.contient(elem[i]))
            i++;

        if (i < nbElem)
            egaux = false;
        else
            egaux = true;
    }

    return egaux;
}

void Ensemble::afficher () const
{
    cout << "( ";

    for (int i = 0; i < nbElem; i++)
        cout << " " << elem[i];

    cout << " )" << endl;
}

int Ensemble::chercher (int x) const
{
    int indice;

    int i = 0;
    while (i < nbElem && x != elem[i])
        i++;

    if (i < nbElem)
        indice = i;
    else
        indice = -1;

    return indice;
}

Ensemble Ensemble::intersection(const Ensemble& ens2) const
{
    Ensemble resultat;

    int i = 0;
    for (int i=0;i<nbElem;i++)
        if (ens2.contient(elem[i]))
            resultat.ajouter(elem[i]);

    return resultat;
}

Ensemble Ensemble::extraitNombresPremiers() const
{
    Ensemble resultat;
    bool divise;

    for (int i = 0; i < nbElem; i++)
        if (elem[i] > 1)
        {
            divise = false;
            for (int j = 2; j <= sqrt(elem[i]); j++)
                if (elem[i] % j == 0) divise = true;
            if (!divise) resultat.ajouter(elem[i]);
        }


    return resultat;
}