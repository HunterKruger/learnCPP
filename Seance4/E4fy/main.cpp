#include <iostream>
#include "string.h"
#include "compte.h"
using namespace std;

int main() {

    String str1("Bonjour");
    str1.display();cout<<endl;
    String str2(str1);
    str2.display();cout<<endl;
    str1.toUpper();
    cout<<str1.isEqual(str2)<<endl;
    str2.toUpper();
    cout<<str1.isEqual(str2)<<endl;

    Compte *compte1=new Compte("aa",1200);
    compte1->display();
    compte1->verse(800);
    compte1->display();
    compte1->update();
    compte1->display();

    Compte compte2("bb",1000);
    compte2.display();
    Compte::modifyTax(5.0);
    compte2.update();
    compte2.display();

    Compte *compte3=new Compte("cc",600);
    compte3->display();
    Compte compte4("dd",26);
    compte4.display();
    Compte *compte5=new Compte("ee");
    compte5->display();

    Compte::modifyTax(10.0);
    Compte::updateAll();
    Compte::displayAll();

    delete compte1;
    delete compte5;
    delete compte3;
    Compte::displayAll();

    return 0;
}