#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Carte.h"
#include "ListeCartes.h"
#include "Paquet.h"
#include "Joueur.h"
#include "Partie.h"
using namespace std;

int main()
{
	freopen( "out.txt", "w", stdout );	// rediriger la sortie du programme vers out.txt
	srand((unsigned int)time(NULL));

	Carte c1, c2(ROI, COEUR), c3(AS, TREFLE), c4(10, CARREAU), c5(VALET, PIQUE),
		c6(DAME, CARREAU), c7 = c2;
	cout << c1 << ", " << c2 << ", " << c3 << endl;
	cout << c4 << ", " << c5 << ", " << c6 << endl;
	if (c2 > c4 && c2 == c7)
		cout << "comparaisons cartes ok" << endl;

	//Paquet paq52 = Paquet::creerPaquetComplet();
	//paq52.afficher();

	//Partie::setTrace(true);
	Partie part1;
	part1.jouer();
	part1.jouer();

	Partie::setTrace(false);
	for (int i = 0; i < 10; i++) {
		Partie part;
		part.jouer();
	}

	Partie::afficherStats();

	return 0;
}
