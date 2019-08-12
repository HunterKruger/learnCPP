//
// Created by 冯源 on 2018/10/24.
//

#ifndef E11FY_ENSEMBEL_H
#define E11FY_ENSEMBEL_H

#endif //E11FY_ENSEMBEL_H

#pragma once
#include <iostream>
const int VOLUME=100;
using namespace std;

template <class T>
class Ensemble{
private:
    T tab[VOLUME];
    int elementCount;
public:
    Ensemble();
    bool check(T value) const;
    void add(T value);
    void displayTab();
};

template <class T>
Ensemble<T>::Ensemble(){
    elementCount=0;
}

template <class T>
bool Ensemble<T>::check(T value) const{
    int i = 0;

    while (value != tab[i] && i < elementCount)
        i++;

    if (i < elementCount)
        return true;
    else
        return false;
}

template <class T>
void Ensemble<T>::add(T value){
    if(elementCount<VOLUME){
        if(!check(value)){
            tab[elementCount]=value;
            elementCount++;
        }
    }else{
        cout<<"The tab is full."<<endl;
    }
}

template <class T>
void Ensemble<T>::displayTab(){
    for(int i=0;i<elementCount;i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}