//
// Created by 冯源 on 2018/10/1.
//

#ifndef E6_MOTO_H
#define E6_MOTO_H

// Moto.h

#pragma once
#include "Vehicule.h"

class Moto : public Vehicule
{
public :
    Moto (const char* no, Couleur coul, int pui, int cyl);
    void afficher () const;

private :
    int cylindree;
};


#endif //E6_MOTO_H
