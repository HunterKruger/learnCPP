//
// Created by 冯源 on 2018/10/26.
//

#ifndef E12FY_WORD_H
#define E12FY_WORD_H

#endif //E12FY_WORD_H

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Display{
public:
    Display(bool rL){
        returnLine=rL;
    }
    void operator()(string& s){
        cout<<s;
        if(returnLine)
            cout<<endl;
        else
            cout<<" ";
    }
private:
    bool returnLine;
};

class CompareLength{
public:
    bool operator()(string& string1, string& string2){
        return string1.length()<string2.length();
    }
};

class LengthMax{
public:
    LengthMax(int mL){
        maxLength=mL;
    }
    bool operator()(string& s){
        return s.length()<maxLength;
    }
private:
    int maxLength;
};