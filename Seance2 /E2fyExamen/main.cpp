#include <iostream>
#include "Ensemble.h"
using namespace std;

int main() {
    Ensemble ensemble;
    ensemble.add(3);
    ensemble.add(5);
    ensemble.add(7);
    ensemble.display();
    ensemble.add(7);
    ensemble.del(1);
    ensemble.del(3);
    ensemble.display();
    ensemble.add(32);
    ensemble.add(24);
    ensemble.add(93);
    ensemble.add(25);
    ensemble.display();

    Ensemble ensemble2=ensemble;
    cout<<ensemble.isEqual(ensemble2)<<endl;
    ensemble2.del(24);
    cout<<ensemble.isEqual(ensemble2)<<endl;
    ensemble2.add(55);
    cout<<ensemble.isEqual(ensemble2)<<endl;


    ensemble.display();
    ensemble2.display();

    ensemble.intersaction(ensemble2);
    ensemble.display();

    ensemble.prime();

    return 0;
}