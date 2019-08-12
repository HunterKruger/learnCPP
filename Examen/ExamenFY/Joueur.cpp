//
// Created by 冯源 on 2018/10/31.
//

#include "Joueur.h"

Joueur::Joueur() {
}

void Joueur::prendreCarte(const Carte &ca) {
    paquet.ajouter(ca);
}

Carte Joueur::jouerCarte() {
    paquet.extraire();
}

void Joueur::affichage() {
    paquet.affichage();
}

int Joueur::nbCarte(){
    return paquet.getNbCartes();
}
