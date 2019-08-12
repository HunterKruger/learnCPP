//
// Created by 冯源 on 2018/9/12.
//

#include <iostream>
#include "cstring"
#include "cctype"
#include "string.h"
using namespace std;

void String::Init(const char* chain){
    cout<<strlen(chain);
    ch=new char[strlen(chain)+1];
    strcpy(ch,chain);
}

String::String(const char* chain){
    ch=new char[strlen(chain)+1];
    strcpy(ch,chain);
}

String::String(const String& s){
    Init(s.ch);
}

String::~String(){
    delete[] ch;
}

void String::toUpper(){
    for(int i=0;i<strlen(ch);i++) {
        ch[i] =(char)toupper(ch[i]);
    }
}

void String::display() const {
    cout<<ch;
}

bool String::isEqual(const String& s) const{
    return !strcmp(ch,s.ch);
}
