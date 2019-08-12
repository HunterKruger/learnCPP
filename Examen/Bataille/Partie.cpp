#include <iostream>
#include "Carte.h"
#include "Paquet.h"
#include "Joueur.h"
#include "Partie.h"
using namespace std;

bool Partie::trace = false;
int Partie::nbVictoires[2] = { 0, 0 };
int Partie::nbTotalCoups = 0;
int Partie::nbParties = 0;


Partie::Partie()
	: joueur1(), joueur2()
{
	Paquet paq52 = Paquet::creerPaquetComplet();
	paq52.melanger();
	while (paq52.getNbCartes() > 0) {
		joueur1.prendreCarte(paq52.extraire());
		joueur2.prendreCarte(paq52.extraire());
	}
	termine = false;

	if (trace) {
		cout << "\nDISTRIBUTION JOUEUR 1" << endl;
		joueur1.afficherCartes();
		cout << "\nDISTRIBUTION JOUEUR 2" << endl;
		joueur2.afficherCartes();
	}
	nbParties++;
}

void Partie::jouer()
{
	int vainqueurPli;	// numero du joueur (1 ou 2); utile à la trace

	if (termine) {
		cout << "Partie deja jouee" << endl;
		return;
	}
	cout << "\nDEBUT PARTIE" << endl;
	while (joueur1.nbCartes() != 0 && joueur2.nbCartes() != 0) {
		Carte carte1 = joueur1.jouerCarte();
		Carte carte2 = joueur2.jouerCarte();
		if (carte1 > carte2) {
			joueur1.prendreCarte(carte1);
			joueur1.prendreCarte(carte2);
			vainqueurPli = 1;
		}
		else {
			joueur2.prendreCarte(carte2);
			joueur2.prendreCarte(carte1);
			vainqueurPli = 2;
		}

		if (trace) {
			cout << carte1 << "\t" << carte2;
			cout << "\tjoueur " << vainqueurPli << " ramasse" << endl;
		}
		nbTotalCoups++;
	}

	if (joueur1.nbCartes() == 0) {
		cout << "joueur 2 vainqueur" << endl;
		nbVictoires[1]++;
	}
	else {
		cout << "joueur 1 vainqueur" << endl;
		nbVictoires[0]++;
	}
	termine = true;
}

void Partie::setTrace(bool tra)
{
	trace = tra;
}

void Partie::afficherStats()
{
	cout << "\nSTATISTIQUES" << endl;
	for (int i = 0; i < 2; i++)
		cout << "victoires joueur " << i + 1 << " : " << (100 * nbVictoires[i]) / nbParties << " %" << endl;
	cout << "nb moyen de coups / partie : " << nbTotalCoups / nbParties << endl; 
}
