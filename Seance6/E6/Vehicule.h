//
// Created by 冯源 on 2018/10/1.
//

#ifndef E6_VEHICULE_H
#define E6_VEHICULE_H


// Vehicule.h

#pragma once

enum Couleur {ROUGE, VERT, BLEU};

class Vehicule
{
public :
    Vehicule (const char* no, Couleur coul, int pui, int nbr = 4);
    void afficher () const;
    //virtual void afficher () const;

private :
    char nom[20];
    int puiss;
    int nbRoues;
    Couleur couleur;
};



#endif //E6_VEHICULE_H
