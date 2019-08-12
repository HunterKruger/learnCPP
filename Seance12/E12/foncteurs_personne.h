// foncteurs_personnes.h

#pragma once
#include <iostream>
#include "Personne.h"
using namespace std;

class ComparePersParAge
{
public :
    bool operator()(const Personne& pers1, const Personne& pers2)
    {
        return pers1.getAge() < pers2.getAge();
    }
};

class ComparePersParNom
{
public :
    bool operator()(const Personne& pers1, const Personne& pers2)
    {
        return pers1.getNom() < pers2.getNom();
    }
};
