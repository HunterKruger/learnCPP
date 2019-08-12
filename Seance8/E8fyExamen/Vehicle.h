//
// Created by 冯源 on 2018/10/29.
//

#ifndef E8FYEXAMEN_VEHICLE_H
#define E8FYEXAMEN_VEHICLE_H

#endif //E8FYEXAMEN_VEHICLE_H

#include "iostream"
using namespace std;

class Vehicle{
private:
    string name;
    int maxSpeed;
public:
    Vehicle(string nn,int ms){
        name=nn;
        maxSpeed=ms;
    }
    virtual void display(){
        cout<<"Name:"<<name<<" Max speed:"<<maxSpeed<<endl;
    }
};

class Terrestrial:public Vehicle{
private:
    int wheels;
public:
    Terrestrial(string nn,int ms,int ww):Vehicle(nn,ms){   //Attention, old and new parameters together in the constructor
        wheels=ww;
    }
    void display(){
        Vehicle::display();
        cout<<"Wheels:"<<wheels<<endl;
    }
};

class Marine:public Vehicle{
private:
    int displacement;
public:
    Marine(string nn,int ms,int dd):Vehicle(nn,ms){
        displacement=dd;
    }
    void display(){
        Vehicle::display();
        cout<<"Displacement:"<<displacement<<endl;
    }
};

class Amphibious:public Marine,Terrestrial{   //rhombus inherit
private:
public:
    Amphibious(string nn,int ms,int nw,int dd):Marine(nn,ms,dd),Terrestrial(nn,ms,nw){   //Attention, old and new parameters together in the constructor
    }
    void display(){
        Marine::display();
        Terrestrial::display();
    }
};