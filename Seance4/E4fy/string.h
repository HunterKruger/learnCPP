//
// Created by 冯源 on 2018/9/12.
//

#ifndef E4FY_STRING_H
#define E4FY_STRING_H

#endif //E4FY_STRING_H

#pragma once;

using namespace std;

class String{

private:

    char* ch;
    void Init(const char* chain);

public:

    String(const char* chain);
    String(const String& s);
    ~String();
    void toUpper();
    void display() const;
    bool isEqual(const String& s) const;

};
