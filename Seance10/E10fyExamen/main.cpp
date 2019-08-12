#include <iostream>
#include "Short.h"
using namespace std;
int main() {
    long x,y;
    cout<<"Input 2 values:"<<endl;
    cin>>x>>y;

    try{     // find is there any exception in the try block
        cout<<"Debut of block try:"<<endl;
        Short s1(x);      // maybe debord exception here
        Short s2(y);      // maybe debord exception here
        cout<<"Add="<<s1+s2<<endl;  // maybe debord exception here
        cout<<"Minus="<<s1-s2<<endl;  // maybe debord exception here
        cout<<"Multiply="<<s1*s2<<endl;  // maybe debord exception here
        cout<<"Divide="<<s1/s2<<endl;  // maybe debord exception here
        cout<<"End of block try."<<endl;
    }catch (Debord excp) {   //init Debord as exception
        excp.displayMessage();   //output the warning of exception
        cout<<excp.getValue()<<endl;  //show the result which out of limit
    }
    cout<<"Follow the catch!"<<endl;
    return 0;
}