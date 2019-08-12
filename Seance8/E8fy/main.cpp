#include <iostream>
#include "string.h"
using namespace std;

class Vehicle{
private:
    int maxSpeed;
    string name;
public:
    Vehicle(string n, int ms){
        maxSpeed=ms;
        name=n;
    }
    virtual void display(){
        cout<<"I am "<<name<<", and my max speed is "<<maxSpeed<<"."<<endl;
    }
};

class Terrestrial:public Vehicle{
private:
    int numberOfWheels;
public:
    Terrestrial(string n,int ms,int nw):Vehicle(n,ms){
        numberOfWheels=nw;
    }
    void display(){
        Vehicle::display();
        cout<<"I have "<<numberOfWheels<<" wheels."<<endl;
    }
};

class Marine:public Vehicle{
private:
    int displacement;
public:
    Marine(string n,int ms,int d):Vehicle(n,ms){
        displacement=d;
    }
    void display(){
        Vehicle::display();
        cout<<"My displacement is "<<displacement<<"."<<endl;
    }
};

class Amphibious:public Marine,public Terrestrial{
public:
    Amphibious(string n, int ms, int d, int nw):Marine(n,ms,d),Terrestrial(n,ms,nw){

    }
    void display(){
        Marine::display();
        Terrestrial::display();
    }
};

int main() {

    Vehicle v("Vehicle",25);
    v.display();

    Terrestrial t("Terrestrial",52,4);
    t.display();

    Marine m("Marine",12,5000);
    m.display();

    Amphibious a("Amphibious",42,2000,8);
    a.display();

    Vehicle* pV=&t;
    pV->display();

    Vehicle* pV2=&m;
    pV2->display();

    Terrestrial* pT=&a;
    pT->display();

    return 0;
}