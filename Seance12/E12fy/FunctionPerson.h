//
// Created by 冯源 on 2018/10/26.
//

#ifndef E12FY_FUNCTIONPERSON_H
#define E12FY_FUNCTIONPERSON_H

#endif //E12FY_FUNCTIONPERSON_H

#pragma once
#include "Person.h"
#include "iostream"
using namespace std;

class ComparePersonByAge{
public:
    bool operator()(Person& person1, Person& person2){
        return person1.getAge()<person2.getAge();
    }
};

class ComparePersonByName{
public:
    bool operator()(Person& person1, Person& person2){
        return person1.getName()<person2.getName();
    }
};