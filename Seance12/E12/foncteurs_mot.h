// foncteurs_mots.h

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Affichage
{
public :
    Affichage(bool retourLigne)     { this->retourLigne = retourLigne; }

    void operator()(const string& s)
    {
        cout << s;
        if (retourLigne)
            cout << endl;
        else
            cout << " ";
    }

private :
    bool retourLigne;
};

class CompareLongueur
{
public :
    bool operator()(const string& s1, const string& s2)
    {
        return s1.length() < s2.length();
    }
};

class LongueurMax
{
public :
    LongueurMax(int lgMax)      { this->lgMax = lgMax; }

    bool operator()(const string& s)
    {
        return s.length() < lgMax;
    }

private :
    int lgMax;
};
