// e7.cpp

#include <iostream>
#include "Animaux.h"
#include "ListeAnimaux.h"
using namespace std;

int main()
{
    Chien monChien ("Medor");
    Cheval monCheval ("Crin blanc");
    Pigeon monPigeon ("Petit Pigeon");
    Corbeau monCorbeau ("Petit Corbeau");
    Rossignol monRossignol ("Petit Rossignol");

    ListeAnimaux liste;

    liste.ajouter (&monChien);
    liste.ajouter (&monCheval);
    liste.ajouter (&monPigeon);
    liste.ajouter (&monCorbeau);
    liste.ajouter (&monRossignol);

    liste.afficher();

    return 0;
}
