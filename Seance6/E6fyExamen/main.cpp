#include <iostream>
#include "Vehicle.h"

int main() {
    Vehicle vehicle("Toyota",463,4,red); //the fourth parameter is enum，no need to use ""
    vehicle.display();cout<<endl;
    Moto moto("Susuki",231,2,green,52);
    moto.display();cout<<endl;

    Vehicle* pV;
    pV=&vehicle;
    pV->display();cout<<endl;
    pV=&moto;
    pV->display();cout<<endl;
    return 0;
}