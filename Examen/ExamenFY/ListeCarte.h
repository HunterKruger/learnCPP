//
// Created by 冯源 on 2018/10/31.
//

#ifndef EXAMENFY_LISTECARTE_H
#define EXAMENFY_LISTECARTE_H

#include "iostream"
using namespace std;
#include "Carte.h"
#include "stdlib.h"
#include "time.h"

class ListeCarte {
private:
    Carte* cartes;
    int taille;
    int nbCartes;
public:
    ListeCarte();
    ListeCarte(int tt);
    ListeCarte(ListeCarte& lc);
    ~ListeCarte();
    void affichage();
    void ajouter(const Carte& ca);
    Carte extraire();
    bool contient(const Carte& ca);
    int getNbCartes() const;
    void melange();
    void inverser(int a,int b);

    ListeCarte operator=(const ListeCarte& lc){
        taille=lc.taille;
        nbCartes=lc.taille;
        cartes=new Carte[taille];
        for(int i=0;i<taille;i++){
            cartes[i]=lc.cartes[i];
        }
    }
};


#endif //EXAMENFY_LISTECARTE_H
