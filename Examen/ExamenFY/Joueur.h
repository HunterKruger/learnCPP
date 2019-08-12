//
// Created by 冯源 on 2018/10/31.
//

#ifndef EXAMENFY_JOUEUR_H
#define EXAMENFY_JOUEUR_H


#include "Paquet.h"

class Joueur {
private:
    Paquet paquet;
public:
    Joueur();
    void prendreCarte(const Carte& ca);
    Carte jouerCarte();
    void affichage();
    int nbCarte();
};


#endif //EXAMENFY_JOUEUR_H
