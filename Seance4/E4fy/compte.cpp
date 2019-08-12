#include "compte.h"
#include "string.h"
// Created by 冯源 on 2018/9/12.
//

#include "iostream"
using namespace std;
float Compte::tax=3.5;
Compte* Compte::head=0;

Compte::Compte(const char* cc, float amo):nom(cc){
    amount=amo;
    next=head;
    head=this;
}

void Compte::add(float m){
    amount+=m;
}

void Compte::modifyTax(float newTax){
    tax=newTax;
}

void Compte::display(){
    nom.display();
    cout<<" "<<amount<<endl;
}

void Compte::verse(float montantVerse){
    amount+=montantVerse;
}

void Compte::update(){
    amount=amount*(1+tax/100);
}

void Compte::updateAll(){
    Compte *compte=head;
    while (compte!=0){
        compte->update();
        compte=compte->next;
    }
}

void Compte::displayAll(){
    Compte *compte=head;
    while (compte!=0){
        compte->display();
        compte=compte->next;
    }
}

Compte::~Compte(){
    Compte *previous=0;
    Compte *current=head;
    while (current!=this){
        previous=current;
        current=current->next;
    }
    if(previous!=0){
        previous->next=current->next;
    }else{
        head=current->next;
    }
}