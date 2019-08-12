//
// Created by 冯源 on 2018/10/31.
//

#include "ListeCarte.h"

ListeCarte::ListeCarte(int tt) {
    taille=tt;
    cartes=new Carte[taille];
    nbCartes=0;
}

ListeCarte::ListeCarte(ListeCarte& lc){
    taille=lc.taille;
    nbCartes=lc.nbCartes;
    cartes=new Carte[taille];
    for(int i=0;i<taille;i++){
        cartes[i]=lc.cartes[i];
    }
}



ListeCarte::~ListeCarte() {
    delete []cartes;
}

void ListeCarte::affichage() {
    cout<<"**********************"<<endl;
    for(int i=0;i<nbCartes;i++){
        cout<<cartes[i];
    }
    cout<<"**********************"<<endl;

}

void ListeCarte::ajouter(const Carte &ca) {
    if(nbCartes==taille){
        cout<<"The ListeCarte is full!"<<endl;
    }else{
        cartes[nbCartes]=ca;
        nbCartes++;
    }
}

Carte ListeCarte::extraire() {
    if(nbCartes>=1){
        Carte premiere=cartes[0];
        for(int i=0;i<taille-1;i++){
            cartes[i]=cartes[i+1];
        }
        nbCartes--;
        Carte null(0,0);
        cartes[taille-1]=null;
        return premiere;
    } else{
        cout<<"There is no carte in the ListeCarte"<<endl;
    }
}

bool ListeCarte::contient(const Carte &ca) {
    bool isContient= false;
    for(int i=0;i<nbCartes;i++){
        if(ca==cartes[i]){
            isContient=true;
            break;
        }
    }
    return isContient;
}

int ListeCarte::getNbCartes() const {
    return nbCartes;
}

void ListeCarte::inverser(int a,int b) {
    Carte temp=cartes[b];
    cartes[b]=cartes[a];
    cartes[a]=temp;
}

void ListeCarte::melange() {
    for(int i=0;i<1000;i++){
        int a=rand()%(nbCartes);
        int b=rand()%(nbCartes);
        while(a==b){
            b=rand()%(nbCartes);
        }
        inverser(a,b);
    }
}
