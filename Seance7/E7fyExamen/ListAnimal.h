//
// Created by 冯源 on 2018/10/29.
//

#ifndef E7FYEXAMEN_LISTANIMAL_H
#define E7FYEXAMEN_LISTANIMAL_H

#endif //E7FYEXAMEN_LISTANIMAL_H


#include "iostream"
using namespace std;
const int SIZE=10;
class ListAnimal{
private:
    Animal* pA[SIZE];     //pointer array
    int count;
public:
    ListAnimal(){
        count=0;
    }
    void add(Animal& animal){
        if(count<SIZE){
            pA[count]=&animal;
            count++;
        }else{
            cout<<"The list is full!"<<endl;
        };
    }

    void display(){
        for(int i=0;i<count;i++){
            pA[i]->display();
            pA[i]->parle();
        }
    }

};