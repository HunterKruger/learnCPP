//
// Created by 冯源 on 2018/10/31.
//

#include "Partie.h"

Partie::Partie() {
    Paquet paquet3;
    paquet3=Paquet::creerPaquetComplet();
    paquet3.affichage();
    paquet3.melange();
    paquet3.affichage();

    for(int i=0;i<26;i++){
        Carte carte5=paquet3.extraire();
        joueur1.prendreCarte(carte5);
    }
    for(int i=0;i<26;i++){
        Carte carte6=paquet3.extraire();
        joueur2.prendreCarte(carte6);
    }
    joueur1.affichage();
    joueur2.affichage();
}



int Partie::jouer() {
    Carte ca1;
    //ca1=joueur1.jouerCarte();
    Carte ca2;
    //ca2=joueur2.jouerCarte();
    //cout<<ca1<<ca2<<endl;

    int joueurVicorieux;
    termine=false;
    while(!termine){
        //cout<<joueur1.nbCarte()<<endl;
        //cout<<joueur2.nbCarte()<<endl;
        ca1=joueur1.jouerCarte();
        ca2=joueur2.jouerCarte();
        cout<<ca1;
        cout<<ca2;
        if(ca1>ca2){
            joueur1.prendreCarte(ca1);
            joueur1.prendreCarte(ca2);
        }
        if(ca1<ca2){
            joueur2.prendreCarte(ca1);
            joueur2.prendreCarte(ca2);
        }
        termine=!(joueur1.nbCarte()>0&&joueur2.nbCarte()>0);
    }
    cout<<"Game over"<<endl;
    joueurVicorieux=0;
    return joueurVicorieux;
}