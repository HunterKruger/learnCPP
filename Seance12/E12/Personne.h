// Personne.h

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Personne
{
public :
    Personne(const string& nomPers, int agePers) : nom(nomPers) {
        age = agePers;
    }

    void afficher() const { cout << nom << " " << age << endl; }
    string getNom() const { return nom; }
    int getAge() const    { return age; }

private :
    string nom;
    int age;
};
