//
// Created by 冯源 on 2018/10/28.
//

#ifndef E6FYEXAMEN_VEHICLE_H
#define E6FYEXAMEN_VEHICLE_H

#endif //E6FYEXAMEN_VEHICLE_H

#include "iostream"
using namespace std;
enum color{red=1,green=2,yellow=3,blue=4};   //enum

class Vehicle{
private:
    string name;
    float power;
    int wheels;
    color colorVehicle;
public:
    Vehicle(string n, float p,int w,color c){
        name=n;
        power=p;
        wheels=w;
        colorVehicle=c;
    }
    virtual void display() {   //virtual function，Polymorphism，according to the object the pointer refers to
                               // automatically recall the display() of the object
        string cc;
        switch (colorVehicle) {     //set the output of enum. if use colorVehicle directly，the output is 1、2、3、4
            case red: cc="red";break;
            case green: cc="green";break;
            case yellow: cc="yellow";break;
            case blue: cc="blue";break;
        }
        cout << "Name:" << name << " Power:" << power
        << " Wheels:" << wheels << " Color:" << cc; //attention，only using cc can display the colors
    }
};

class Moto:public Vehicle{
private:
    int cylinder;
public:
    Moto(string n, float p,int w,color c,int cl):Vehicle(n,p,w,c){  //attention the format，recall the constructor of father class
        cylinder=cl;
    }
    void display(){
        Vehicle::display();
        cout<<" Cylinder:"<<cylinder;
    }
};