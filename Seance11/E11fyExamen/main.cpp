#include <iostream>
#include "String.h"
#include "Ensemble.h"
using namespace std;

int main() {

    Ensemble <int> e1;
    e1.add(10);
    e1.add(15);
    e1.add(10);
    e1.display();

    Ensemble <string> e2;
    string s1("Fuck");
    string s2("you");
    e2.add(s1);
    e2.add(s2);
    e2.add("Fuck");
    e2.display();

    Ensemble <String> e3;
    String S1("Ass");
    String S2("Hole");
    e3.add(S1);
    e3.add(S2);
    e3.add("Ass");
    e3.display();
    return 0;
}