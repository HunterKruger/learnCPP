#include <iostream>
#include "string.h"
using namespace std;
enum color{red,green,blue,yellow};

class Vehicle{
protected:
    string name;
    float fiscalPower;
    int numberOfWheels;
    color colorVehicle;
public:
    Vehicle (string n,float fp,int nw,color cV){
        name=n;
        fiscalPower=fp;
        numberOfWheels=nw;
        colorVehicle=cV;
    }

    virtual void display(){
        cout<<"Name:"<<name<<", Fiscal power: "<<fiscalPower<<", Wheel(s): "
            <<numberOfWheels<<", Color:"<<colorVehicle<<endl;
    }
};

class Moto: public Vehicle{
private:
    int cylinder;
public:
    Moto(string n, float fp,int nw ,color cV, int cyl):Vehicle(n,fp,nw,cV){
        cylinder=cyl;
    }
    void display(){
        Vehicle::display();
        cout<<"Cylinder: "<<cylinder<<endl;
    }
};

int main() {
    Vehicle v("Toyota",7.5,4,red);
    v.display();
    Moto m("Suzuki",8,2,green,15);
    m.display();
    Vehicle* pv=&m;
    pv->display();
    return 0;
}