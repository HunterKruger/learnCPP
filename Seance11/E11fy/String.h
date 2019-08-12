//
// Created by 冯源 on 2018/9/12.
//

#ifndef E4FY_STRING_H
#define E4FY_STRING_H

#endif //E4FY_STRING_H

#pragma once
#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

class String{
private:
    char* ch;
public:
    String(){
        ch=new char[1];
        ch[0]='\0';
    }
    String(const char* ch2){
        ch=new char[strlen(ch2)+1];
        strcpy(ch,ch2);
    }
    String(const String& str2){
        ch=new char[strlen(str2.ch)+1];
        strcpy(ch,str2.ch);
    }
    ~String(){
        delete[ ] ch;
    }
    void toUpper(){
        int i=0;
        while (ch[i]!=0){
            ch[i]=toupper(ch[i]);
        }
    }
    void display() const{
        cout<<ch<<endl;
    }
    bool isEqual(const String& str2) const{
        if(strcmp(ch,str2.ch)==0){
            return true;
        }else{
            return false;
        }
    }
    String& operator = (const String& str2){
        if(this!=&str2){
            delete[] ch;
            ch=new char[strlen(str2.ch)+1];
            strcpy(ch,str2.ch);
        }
        return *this;
    }
    friend ostream& operator<<(ostream& flux,const String& str){
        flux<<str.ch;
        return flux;
    }
    bool operator!=(const String& str2 ) const{
        return !isEqual(str2);
    }
};
