//
// Created by 冯源 on 2018/10/30.
//

#ifndef E10FYEXAMEN_SHORT_H
#define E10FYEXAMEN_SHORT_H

#endif //E10FYEXAMEN_SHORT_H

#include "iostream"
#include "cstring"
#include "climits"  // it includes the limits of variables
using namespace std;

class Debord{       // this class is for exception
private:
    short value;
    string message;    // message shows the warning of exception
public:
    Debord(long v,string m){
        message=m;
        value=v;
    }
    long getValue(){
        return value;
    }
    void displayMessage(){
        cout<<message<<endl;
    }
};

class Short{  // class for encapsulation of a "short" variable
private:
    short value;
public:
    Short(long v){
        if(v>SHRT_MAX){
             Debord debord(v,"Value bigger than limit!");   //create exception
             throw debord;      //  throw exception
        }else if(v<SHRT_MIN){
            Debord debord(v,"Value smaller than limit!");   //create exception
            throw debord;      //  throw exception
        }else{
            value=(short)v;   // no exception, variable type change brutally
        }
    }

    friend ostream& operator<< (ostream& flood, const Short& S){
        flood<<S.value;  // overload "<<",  allow output the "value" of a Short object directly
        return flood;
    }

    Short operator+(const Short S2)const {  // allow direct calculation of two Short object
        long v1=value;
        long v2=S2.value;
        Short result(v1+v2);
        return result;
    }
    Short operator-(const Short S2)const {
        long v1=value;
        long v2=S2.value;
        Short result(v1-v2);
        return result;
    }
    Short operator*(const Short S2)const {
        long v1=value;
        long v2=S2.value;
        Short result(v1*v2);
        return result;
    }
    Short operator/(const Short S2)const {
        long v1=value;
        long v2=S2.value;
        Short result(v1/v2);
        return result;
    }

};
























