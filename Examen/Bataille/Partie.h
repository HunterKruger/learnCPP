#include <iostream>
#include "Carte.h"
#include "Paquet.h"
#include "Joueur.h"
using namespace std;

#pragma once

class Partie
{
public :
	Partie();
	void jouer();
	static void setTrace(bool tra);
	static void afficherStats();

private :
	Joueur joueur1, joueur2;
	bool termine;

	static bool trace;

	// pour les statistiques
	static int nbVictoires[2];
	static int nbTotalCoups;
	static int nbParties;
};
