//
// Created by 冯源 on 2018/10/31.
//

#include "Paquet.h"

Paquet::Paquet():ListeCarte(52) {
}

void Paquet::ajouter(const Carte &ca) {
    if(contient(ca)){
        cout<<"This card is already in the Paquet!"<<endl;
    } else{
        ListeCarte::ajouter(ca);
    }
}

Paquet Paquet::creerPaquetComplet() {
    Paquet paquet;
    for(int j=2;j<=14;j++){
        for(int i=1;i<=4;i++){
            Carte carte(j,i);
            paquet.ajouter(carte);
        }
    }
    //paquet.affichage();
    return paquet;
}

