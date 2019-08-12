//
// Created by 冯源 on 2018/10/31.
//

#include "Carte.h"

Carte::Carte() {
    numero=0;
    couleur=0;
}


Carte::Carte(int nn, int cc) {
//    if(nn>14||nn<2){
//        cout<<"Invalid numero!"<<endl;
//    } else{
        numero=nn;
//    }
//    if(cc>4||cc<1){
//        cout<<"Invalid couleur!"<<endl;
//    } else{
        couleur=cc;
//    }

}

ostream& operator<<(ostream &os, Carte &carte) {
    string displayCouleur;
    string displayNumero;
    if(carte.numero==0 || carte.couleur==0){
        displayNumero="Carte";
        displayCouleur=" nulle";
    }else{
        switch (carte.couleur){
            case 1: displayCouleur=" de Trefle";
                break;
            case 2: displayCouleur=" de Carreau";
                break;
            case 3: displayCouleur=" de Coeur";
                break;
            case 4: displayCouleur=" de Pique";
                break;
        }
        switch (carte.numero){
            case 14: displayNumero="As";
                break;
            case 13: displayNumero="Roi";
                break;
            case 12: displayNumero="Dame";
                break;
            case 11: displayNumero="Valet";
                break;
            default: displayNumero=to_string(carte.numero) ;
                break;
        }
    }
    os<<displayNumero<<displayCouleur<<endl;
    return os;
}

bool operator==(const Carte& c1,const Carte& c2){
    if(c1.couleur==c2.couleur&&c1.numero==c2.numero){
        return true;
    } else{
        return false;
    }
}

bool operator!=(const Carte& c1,const Carte& c2){
    return !(c1==c2);
}

bool operator<(const Carte& c1,const Carte& c2){
    if(c1.numero<c2.numero){
        return true;
    }
    if(c1.numero==c2.numero){
        if(c1.couleur<c2.couleur){
            return true;
        } else{
            return false;
        }
    }
    if(c1.numero>c2.numero){
        return false;
    }
}

bool operator>(const Carte& c1,const Carte& c2){
    if(c1.numero>c2.numero){
        return true;
    }
    if(c1.numero==c2.numero){
        if(c1.couleur>c2.couleur){
            return true;
        } else{
            return false;
        }
    }
    if(c1.numero<c2.numero){
        return false;
    }
}

int Carte::getNumero() const {
    return numero;
}

int Carte::getCouleur() const {
    return couleur;
}

void Carte::setNumero(int numero) {
    Carte::numero = numero;
}

void Carte::setCouleur(int couleur) {
    Carte::couleur = couleur;
}
