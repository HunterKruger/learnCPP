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

    String(char* chain){   //common constructor
        ch=new char[strlen(chain)+1];
        strcpy(ch,chain);
    }

    String(String& s){   //copy constructor
        ch=new char[strlen(s.ch)+1];
        strcpy(ch,s.ch);
    }

    void display(){
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

    bool isEqual(String& s2){
        return !strcmp(ch,s2.ch);  //if same, strcmp return 0
    }

};

