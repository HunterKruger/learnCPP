#include <iostream>
#include "math.h"
using namespace std;

class Rational{

private:

    long a;
    long b;

public:

    Rational(long a,long b=1){
        if(b==0){
            cout<<"The denominator cannot be 0"<<endl;
            exit(0);
        }
        if(b<0){
            this->a=-a;
            this->b=-b;
        }else{
            this->a=a;
            this->b=b;
        }
        reduce();
    }
    void reduce(){
        long u = a;
        long v = b;
        long temp;
        if(u < 0){
            u = -u;
        }
        while(v != 0) {
            temp = u % v;
            u = v;
            v = temp;
        }
        a /= u;
        b /= u;
    }
    float toFloat(){
        float result;
        result=(float)a/(float)b;
        return result;
    }
    friend ostream& operator<<(ostream& os, const Rational& ra){
        os<<ra.a;
        if(ra.b!=1){
            os<<"/"<<ra.b;
        }
        return os;
    }

    Rational &operator+(const Rational& ra2)const {
        long up=b*ra2.a+a*ra2.b;
        long down=b*ra2.b;
        Rational result(up,down);
        return result;
    }
    Rational &operator-(const Rational& ra2)const {
        long up=a*ra2.b-b*ra2.a;
        long down=b*ra2.b;
        Rational result(up,down);
        return result;
    }
    Rational &operator*(const Rational& ra2)const {
        long up=a*ra2.a;
        long down=b*ra2.b;
        Rational result(up,down);
        return result;
    }
    Rational &operator/(const Rational& ra2)const {
        long up=a*ra2.b;
        long down=b*ra2.a;
        Rational result(up,down);
        return result;
    }

    Rational &operator+=(const Rational& ra2){
        *this=*this+ra2;
        return *this;
    }
    Rational &operator-=(const Rational& ra2){
        *this=*this-ra2;
        return *this;
    }
    Rational &operator*=(const Rational& ra2){
        *this=*this*ra2;
        return *this;
    }
    Rational &operator/=(const Rational& ra2){
        *this=*this/ra2;
        return *this;
    }

    friend bool operator==( const Rational& ra1, const Rational& ra2){
        return ra1.a*ra2.b == ra1.b*ra2.a;
    }
    friend bool operator!=( const Rational& ra1, const Rational& ra2){
        return !(ra1==ra2);
    }
    friend bool operator>( const Rational& ra1, const Rational& ra2){
        return ra1.a*ra2.b > ra1.b*ra2.a;
    }
    friend bool operator>=( const Rational& ra1, const Rational& ra2){
        return (ra1==ra2)||(ra1>ra2);
    }
    friend bool operator<( const Rational& ra1, const Rational& ra2){
        return ra1.a*ra2.b < ra1.b*ra2.a;
    }
    friend bool operator<=( const Rational& ra1, const Rational& ra2){
        return (ra1==ra2)||(ra1<ra2);
    }

};

void series(int q,int N){
    int n=1;
    Rational u(1);
    Rational qInv(1);
    while (n<=N){
        cout<<"n="<<n<<", u="<<u.toFloat()<<endl;
        n++;
        qInv /= q;
        u += qInv;
    }
    cout<<endl;
}
void series2(int N){
    int n=0;
    Rational u(2,1);
    Rational two(2,1);
    Rational one(1,1);
    while (n<N){
        Rational v=two/u;
        cout<<"n="<<n<<", u="<<u<<"="<<u.toFloat()<<", v="<<v<<"="<<v.toFloat()<<endl;
        cout<<"u-v="<<(u-v).toFloat()<<endl;
        cout<< ((u-v)<one) <<endl;
        u=(u+v)/2;
        n++;
        one/=4;
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
    cout<<rational4.toFloat()<<endl;

    Rational rational3=rational1+rational2;
    cout<<rational3<<endl;

    Rational rational5=rational1/rational2;
    cout<<rational5<<endl;

    series(5,14);
    series2(10);

    return 0;
}
