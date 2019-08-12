// e12.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Personne.h"
#include "foncteurs_personne.h"
#include "foncteurs_mot.h"
using namespace std;

#define NOM_FIC_PERS    "pers.txt"
#define NOM_FIC_MOTS    "mots.txt"

void tp_personnes();
void lireFicPers();
void afficherVectPers();
void afficherVectPersParIter();
void afficherMapPers();
void tp_mots();
void lireFicMots();

vector<Personne> vectPers;
map<string, Personne> mapPers;
vector<string> vectMots;

void tp_personnes()
{
    lireFicPers();

    cout << "AFFICHAGE VECTEUR PAR INDICE :" << endl;
    afficherVectPers();

    cout << "AFFICHAGE VECTEUR PAR ITERATEUR :" << endl;
    afficherVectPersParIter();

    cout << "AFFICHAGE MAP :" << endl;
    afficherMapPers();

    cout << "TRI AGE :" << endl;
    sort(vectPers.begin(), vectPers.end(), ComparePersParAge());
    afficherVectPers();

    cout << "TRI NOM :" << endl;
    sort(vectPers.begin(), vectPers.end(), ComparePersParNom());
    afficherVectPers();
}

void lireFicPers()
{
    ifstream fic(NOM_FIC_PERS);
    bool finFic  = false;

    while (!finFic) {
        string nom;
        int age;
        fic >> nom >> age;
        if (fic.eof())
            finFic = true;
        else {
            Personne pers(nom, age);
            vectPers.push_back(pers);

            pair<string, Personne> paireNomPers(nom, pers);
            pair<map<string, Personne>::iterator, bool> cr;
            cr = mapPers.insert(paireNomPers);
            if (cr.second == false)
                cout << paireNomPers.first << " deja present" << endl;
        }
    }
}

void afficherVectPers()
{
    int nbPers = vectPers.size();

    for (int i = 0; i < nbPers; i++)
        vectPers[i].afficher();
}

void afficherVectPersParIter()
{
    vector<Personne>::iterator it;

    for (it = vectPers.begin(); it != vectPers.end(); it++)
        it->afficher();
}

void afficherMapPers()
{
    map<string, Personne>::iterator it;

    for (it = mapPers.begin(); it != mapPers.end(); it++)
        it->second.afficher();
}

void tp_mots()
{
    lireFicMots();

    cout << "AFFICHAGE VECTEUR MOTS :" << endl;
    int nbMots = vectMots.size();
    for (int i = 0; i < nbMots; i++)
        cout << vectMots[i] << endl;

    cout << "AFFICHAGE FOR_EACH :" << endl;
    for_each(vectMots.begin(), vectMots.end(), Affichage(true));
    for_each(vectMots.begin(), vectMots.end(), Affichage(false));
    cout << endl;

    cout << "TRI SIMPLE (ALPHABETIQUE) :" << endl;
    sort(vectMots.begin(), vectMots.end());
    for_each(vectMots.begin(), vectMots.end(), Affichage(true));

    cout << "TRI PAR LONGUEUR :" << endl;
    sort(vectMots.begin(), vectMots.end(), CompareLongueur());
    for_each(vectMots.begin(), vectMots.end(), Affichage(true));

    string mot;
    cout << "mot a compter : ";
    cin >> mot;
    cout << "nb = " << count(vectMots.begin(), vectMots.end(), mot) << endl;

    int lg;
    cout << "longueur : ";
    cin >> lg;
    cout << "nb de mots de lg inferieure = "
         << count_if(vectMots.begin(), vectMots.end(), LongueurMax(lg))
         << endl;

    vector<string>::iterator it;
    it = find_if(vectMots.begin(), vectMots.end(), LongueurMax(lg));
    if (it != vectMots.end())
        cout << "1er mot de lg inferieure : " << *it << endl;
}

void lireFicMots() {
    ifstream fic(NOM_FIC_MOTS);
    bool finFic  = false;

    while (!finFic) {
        string mot;
        fic >> mot;
        if (fic.eof())
            finFic = true;
        else
            vectMots.push_back(mot);
    }
}

int main()
{
    tp_personnes();
    tp_mots();

    return 0;
}
