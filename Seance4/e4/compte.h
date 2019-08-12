// compte.h

#pragma once
using namespace std;
#include "str.h"

// il y a un seul taux et une seule tete de liste pour tous les Compte, ces
// donnees sont donc statiques

// de meme, les fonctions de la classe qui ne s'appliquent pas sur un objet
// Compte sont statiques : c'est le cas des fonctions qui agissent sur le taux
// ou qui parcourent la liste

class Compte
{
public :
    Compte (const char* no, float montantIni = 0);
    ~Compte ();
    void verser (float montantVerse);
    void actualiser ();
    void afficher () const;
    static void modifierTaux (float nouveauTaux);
    static void actualiserTous ();
    static void afficherTous ();

private :
    String nom;
    float montant;
    Compte* suiv;    // pour le dernier compte du chainage : suiv = 0

    static float taux;    // valeur exprimee en pourcentage
    static Compte* tete;
};
