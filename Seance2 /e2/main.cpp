// e2.cpp

#include <iostream>
using namespace std;
#include "ensemble.h"

int main ()
{
    Ensemble e1;

    e1.ajouter (2);
    e1.ajouter (8);
    e1.ajouter (6);
    e1.ajouter (5);
    e1.ajouter (2);
    e1.afficher ();
    e1.extraitNombresPremiers().afficher();

    e1.retirer (8);
    e1.retirer (5);
    e1.afficher ();
    e1.extraitNombresPremiers().afficher();

    Ensemble e2, e3;
    e2.ajouter (2);
    e2.ajouter (6);
    e3.ajouter (6);
    e3.ajouter (2);

    if (e1.contient(6) || !e1.contient(5))
        cout << "contient ok" << endl;

    e3.ajouter (7);

    if (e1.estEgal(e2) && !e1.estEgal(e3))
        cout << "estEgal ok" << endl;

    (e1.intersection(e3)).afficher();

    Ensemble e4;
    for (int i = -5; i <= 50; i++)
        e4.ajouter(i);
    e4.extraitNombresPremiers().afficher();

    return 0;
}
