#include <iostream>
#include "Vehicle.h"
using namespace std;
int main() {

    Marine marine("055",45,12000);
    marine.display();

    Terrestrial terrestrial("99A",55,12);
    terrestrial.display();

    Amphibious amphibious("Yamato",428,8,54000);
    amphibious.display();

    Vehicle* pV;
    pV=&terrestrial;
    pV->display();

    pV=&marine;
    pV->display();

    Marine* pM;
    pM=&amphibious;
    pM->display();

    return 0;
}