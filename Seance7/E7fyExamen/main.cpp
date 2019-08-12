#include <iostream>
#include "Animal.h"
#include "ListAnimal.h"
using namespace std;
int main() {

    Animal animal("Animal","wank");
    animal.display();
    animal.parle();   // there is no parle

    Chien chien("Chien");
    chien.display();
    chien.parle();

    Oiseau oiseau("Oiseau");
    oiseau.display();
    oiseau.parle();   // there is no parle

    Pigeon pigeon("Pigeon");
    pigeon.display();
    pigeon.parle();

    Animal* pAnimal;
    pAnimal=&chien;
    pAnimal->display();
    pAnimal->parle();

    pAnimal=&oiseau;
    pAnimal->display();
    pAnimal->parle();  // there is no parle

    pAnimal=&pigeon;
    pAnimal->display();
    pAnimal->parle();

    ListAnimal ls;
    ls.add(animal);
    ls.add(chien);
    ls.add(oiseau);
    ls.add(pigeon);
    ls.display();


    return 0;
}