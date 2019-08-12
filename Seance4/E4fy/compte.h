//
// Created by 冯源 on 2018/9/12.
//

#ifndef E4FY_COMPTE_H
#define E4FY_COMPTE_H

#endif //E4FY_COMPTE_H

#pragma once
#include "string.h"
using namespace std;

class Compte{

private:

    String nom;
    float amount;
    static Compte* head;
    Compte* next;
    static float tax;

public:

    Compte(const char* cc, float mm=0);

    void add(float m);

    static void modifyTax(float newTax);

    void display();

    void verse(float montantVerse);

    void update();

    static void updateAll();

    static void displayAll();

    ~Compte();

};