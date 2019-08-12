//
// Created by 冯源 on 2018/10/29.
//

#ifndef E7FYEXAMEN_ANIMAL_H
#define E7FYEXAMEN_ANIMAL_H

#endif //E7FYEXAMEN_ANIMAL_H

#include "iostream"
using namespace std;

class Animal{
private:
    string name;
    string characteristic;
public:
    Animal(string nn,string cc){
        name=nn;
        characteristic=cc;
    }
    void display(){
        cout<<"Name:"<<name<<" Characteristic:"<<characteristic<<endl;
    }
    virtual void parle(){   //virtual function for Polymorphism
    }
};

class Chien:public Animal{
public:
    Chien(string nn):Animal(nn,"fidele"){    //caution! The format of constructor
    }
    void parle(){
        cout<<"Parle:aboie"<<endl;
    }
};

class Cheval:public Animal{
public:
    Cheval(string nn):Animal(nn,"galope"){
    }
    void parle(){
        cout<<"Parle:hennit"<<endl;
    }
};

class Oiseau:public Animal{
public:
    Oiseau(string nn):Animal(nn,"vole"){
    }                                         //There is no parle for oiseau
};

class Pigeon:public Oiseau{
public:
    Pigeon(string nn):Oiseau(nn){
    }
    void parle(){
        cout<<"Parle:roucoule"<<endl;
    }
};

class Corbeau:public Oiseau{
public:
    Corbeau(string nn):Oiseau(nn){
    }
    void parle(){
        cout<<"Parle:croasse"<<endl;
    }
};

class Possignol:public Oiseau{
public:
    Possignol(string nn):Oiseau(nn){
    }
    void parle(){
        cout<<"Parle:chante"<<endl;
    }
};
