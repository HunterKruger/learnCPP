#include <iostream>
#include "Rational.h"
using namespace std;

void series(int q,int N){  //N is the max of n，q is the common ratio
    Rational u(1);
    Rational qInv(1);  //qInv is the inverse of q
    int n=1;
    while (n<=N){
        cout<<"n="<<n<<", u="<<u.toReal()<<endl;
        n++;
        qInv /= q;   //qInv can be seen as 1/q^n
        u += qInv;   //u(n+1)=u(n)+1/q^n
    }
}

void series2(int N){
    int n=0;
    Rational u(2,1);
    Rational two(2,1);  //need a real 2
    Rational one(1,1);  //need a real 1
    while (n<N){
        Rational v=two/u;
        cout<<"n="<<n<<", u="<<u.toReal()<<", v="<<v.toReal()<<endl;
        cout<<"u-v="<<u.toReal()-v.toReal()<<endl;
        cout<<"1/4^n="<<one.toReal()<<endl;
        cout<< (u.toReal()-v.toReal()<one.toReal()) <<endl;
        u=(u+v)/2;   //u(n+1)=(u(n)+v(n))/2
        n++;
        one/=4;  //one can be seen as 1/4^n
    }

}


int main() {
    Rational rational0(7);
    cout<<rational0<<endl;

    Rational rational1(5,3);
    cout<<rational1<<endl;

    Rational rational2(4,3);
    bool result1=(rational1>=rational2);
    cout<<result1<<endl;

    Rational rational4(8,6);
    cout<<rational4<<endl;
    cout<<rational4.toReal()<<endl;

    Rational rational3=rational1+rational2;
    cout<<rational3<<endl;

    Rational rational5=rational1/rational2;
    cout<<rational5<<endl;

    series(5,14);
    series2(8);

    return 0;
}