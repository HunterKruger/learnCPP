#include <iostream>
#include "String.h"
#include "Account.h"
float Account::tax=3.5;
Account* Account::head=0;
int main() {
    String s1("Fuck you");
    String s2(s1);
    s1.display();cout<<endl;
    s2.display();cout<<endl;
    cout<<s1.isEqual(s2)<<endl;
    s2.toUpper();
    cout<<s1.isEqual(s2)<<endl;
    s1.toUpper();
    cout<<s1.isEqual(s2)<<endl;

    Account a1("FY",1000);
    a1.display();
    a1.payment(900);
    a1.display();
    a1.modifyTax(10);
    a1.update();
    a1.display();

    Account a2("OK",1000);
    Account a3("XY",1000);
    Account a4("YF",1000);
    Account::displayAll();
    Account::updateAll();
    Account::displayAll();


    return 0;
}