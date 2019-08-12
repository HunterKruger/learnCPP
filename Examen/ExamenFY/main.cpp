#include <iostream>
#include "Carte.h"
#include "ListeCarte.h"
#include "Paquet.h"
#include "Joueur.h"
#include "Partie.h"
using namespace std;
int main() {

//    Carte carte1(14,4);
//    cout<<carte1;
//    Carte carte2(5,3);
//    cout<<carte2;
//    Carte carte3(6,4);
//    cout<<carte3;
//
//    bool result1=(carte1==carte3);
//    cout<<result1<<endl;
//
//    bool result2=(carte1!=carte3);
//    cout<<result2<<endl;
//
//    bool result3=(carte1>carte3);
//    cout<<result3<<endl;
//
//    bool result4=(carte1<carte3);
//    cout<<result4<<endl;
//
//    Carte carte4(9,3);
//    Carte carte5(4,2);
//
//    ListeCarte ls(5);
//    ls.ajouter(carte1);
//    ls.ajouter(carte2);
//    ls.ajouter(carte3);
//    ls.affichage();

//    Carte ex=ls.extraire();
//    cout<<ex<<endl;
//    ls.affichage();

//    ls.ajouter(carte4);
//    ls.ajouter(carte5);
//    ls.affichage();
//
//    ls.melange();
//    ls.affichage();
//
//
//    Carte carte6(10,1);
//    ls.ajouter(carte6);
//
//    cout<<ls.contient(carte2)<<endl;
//
//    Carte ex=ls.extraire();
//    cout<<ex;
//    ls.affichage();
//
//    Paquet::creerPaquetComplet();
//
//
//    Carte carte99(7,3);
//    Joueur joueur1;
//    joueur1.affichage();
//    joueur1.prendreCarte(carte99);
//    joueur1.affichage();
//    cout<<joueur1.nbCarte()<<endl;
//
    Partie partie;
    partie.jouer();

    return 0;
}