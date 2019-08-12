//
// Created by 冯源 on 2018/10/26.
//

#ifndef E12FY_PERSON_H
#define E12FY_PERSON_H

#endif //E12FY_PERSON_H

#pragma once
#include "cstring"
#include "iostream"
using namespace std;

class Person{
private:
    string name;
    int age;
public:
    Person(string n, int a){
        name=n;
        age=a;
    }
    void display(){
        cout<<"Name:"<<name<<" Age:"<<age<<endl;
    }
    string getName(){
        return name;
    }
    int getAge() {
        return age;
    }
};