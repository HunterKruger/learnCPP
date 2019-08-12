//
// Created by 冯源 on 2018/10/28.
//

#ifndef E5FYEXAMEN_RATIONAL_H
#define E5FYEXAMEN_RATIONAL_H

#endif //E5FYEXAMEN_RATIONAL_H

#include "iostream"
#include "math.h"
using namespace std;

class Rational{
private:
    long a;
    long b;
public:
    Rational(long a, long b=1){  //denominator by default 1
        if(b==0){
            cout<<"The denominator must not be zero!"<<endl;
        }
        if(b<0){               //put the "-" before the numerator
            this->a=-a;
            this->b=-b;
        }
        if(b>0){
            this->a=a;
            this->b=b;
        }
        reduce();        //fraction reduction
    }
    void reduce(){     //fraction reduction
        long u=a;
        long v=b;
        if(u<0){
            u=-u;
        }
        long temp;
        while(v!=0){   //calculate the PGCD，save it in u
            temp=u%v;
            u=v;
            v=temp;
        }
        a/=u;
        b/=u;
    }
    friend ostream& operator<<(ostream& os, Rational& ra){
        os<<ra.a;          //output numerator first
        if(ra.b!=1){           //if denominator!=1，then output denominator
            os<<"/"<<ra.b;
        }
        return os;
    }


    //the definition of operator for calculation do not need friend，return Rational

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

    //the definition of operator for judgement needs friend, return bool
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


    float toReal(){     //change it to real number
        float result;
        result=(float)a/(float)b;
        return result;
    }



};