//
// Created by 冯源 on 2018/10/31.
//

#ifndef EXAMENFY_CARTE_H
#define EXAMENFY_CARTE_H

#include "iostream"
using namespace std;
class Carte {
private:
    int numero;
    int couleur;
public:
    Carte(int nn,int cc);
    Carte();

    int getNumero() const;

    int getCouleur() const;

    void setNumero(int numero);

    void setCouleur(int couleur);

    friend ostream& operator<<(ostream& os, Carte& carte);

    friend bool operator==(const Carte& c1,const Carte& c2);

    friend bool operator!=(const Carte& c1,const Carte& c2);

    friend bool operator>(const Carte& c1,const Carte& c2);

    friend bool operator<(const Carte& c1,const Carte& c2);
};


#endif //EXAMENFY_CARTE_H
