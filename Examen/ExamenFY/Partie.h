//
// Created by 冯源 on 2018/10/31.
//

#ifndef EXAMENFY_PARTIE_H
#define EXAMENFY_PARTIE_H


#include "Joueur.h"

class Partie {
private:
    Joueur joueur1,joueur2;
    bool termine;
public:
    Partie();
    int jouer();
};


#endif //EXAMENFY_PARTIE_H
