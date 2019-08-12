//
// Created by 冯源 on 2018/10/27.
//

#ifndef E2FYEXAMEN_EMSEMBEL_H
#define E2FYEXAMEN_EMSEMBEL_H

#endif //E2FYEXAMEN_EMSEMBEL_H

#include "iostream"
using namespace std;
const int VOLUME=10;   //default array capacity


template <class T>  //inti of templete
class Ensemble{

private:

    int count;
    T tab[VOLUME];      //array member can be any type, so change it into "T"

public:

    Ensemble();
    void add(T value);   //array member can be any type, so change it into "T"
    bool check(T value);   //array member can be any type, so change it into "T"
    void display();
};

template <class T>  //inti of templete
Ensemble<T>::Ensemble(){
    count=0;
}

template <class T>  //inti of templete
void Ensemble<T>::add(T value){
    if(count<VOLUME){
        if(!check(value)){   //check is there value it the array: no
            tab[count]=value;
            count++;
        }else {             //check is there value it the array: yes
            cout<<"This value is already in the tab!"<<endl;
        }
    } else{
        cout<<"This tab is full!"<<endl;
    }
}

template <class T>  //inti of templete
bool Ensemble<T>::check(T value){      //reture true, which means value is in the array
    bool isExist=false;
    for(int i=0;i<count;i++){
        if(value==tab[i]){
            isExist=true;
            break;
        }
    }
    return isExist;
}

template <class T>  //inti of templete
void Ensemble<T>::display(){
    for(int i=0;i<count;i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}