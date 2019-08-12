//
// Created by 冯源 on 2018/10/28.
//

#ifndef E4FYEXAMEN_STRING_H
#define E4FYEXAMEN_STRING_H

#endif //E4FYEXAMEN_STRING_H

#include "iostream"
#include "cstring"
#include "ctype.h"
using namespace std;

class String{
private:
    char* ch;
public:

    String(){  // new constructor added in this seance, in case of no parameter when initialize
        ch=new char[1];
        ch[0]='\0';
    }

    String(const char* chain){   //common constructor
        ch=new char[strlen(chain)+1];
        strcpy(ch,chain);
    }

    String(const String& s){   //copy constructor
        ch=new char[strlen(s.ch)+1];
        strcpy(ch,s.ch);
    }

    void display() const{
        cout<<ch;
    }

    void toUpper(){
        for(int i=0;i<strlen(ch);i++){
            ch[i]=(char)toupper(ch[i]);
        }
    }

    ~String(){
        delete[]ch;
    }

    bool isEqual(const String& s2) const{
        return !strcmp(ch,s2.ch);  //if same, strcmp return 0
    }

    //String objects will be stored in Ensemble, so I must override operator "<<" "=" "!=" "=="

    friend ostream& operator<<(ostream& flux, const String& str2){
        flux<<str2.ch;
        return flux;
    }

    bool operator!=(const String& str2) const {
        return !this->isEqual(str2);
    }
    bool operator==(const String& str2) const {
        return this->isEqual(str2);
    }

    String& operator = (const String& str2){
        if(this!=&str2){       //do not forget "&" before str2, because "this" is a pointer
            delete []ch;
            ch=new char[strlen(str2.ch)+1];
            strcpy(ch,str2.ch);
        }
        return *this;
    }

};

