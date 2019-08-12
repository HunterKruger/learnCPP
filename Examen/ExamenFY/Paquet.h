//
// Created by 冯源 on 2018/10/31.
//

#ifndef EXAMENFY_PAQUET_H
#define EXAMENFY_PAQUET_H


#include "ListeCarte.h"

class Paquet: public ListeCarte {
public:
    Paquet();
    void ajouter(const Carte& ca);
    static Paquet creerPaquetComplet();
};


#endif //EXAMENFY_PAQUET_H
