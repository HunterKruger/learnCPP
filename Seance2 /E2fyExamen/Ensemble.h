//
// Created by 冯源 on 2018/10/27.
//

#ifndef E2FYEXAMEN_EMSEMBEL_H
#define E2FYEXAMEN_EMSEMBEL_H

#endif //E2FYEXAMEN_EMSEMBEL_H

#include "iostream"
using namespace std;
const int VOLUME=10;   //default array capacity

class Ensemble{

private:

    int count;
    int tab[VOLUME];

public:

    Ensemble(){
        count=0;
    }

    void add(int value){
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

    bool check(int value){      //reture true, which means value is in the array
        bool isExist=false;
        for(int i=0;i<count;i++){
            if(value==tab[i]){
                isExist=true;
                break;
            }
        }
        return isExist;
    }

    void display(){
        for(int i=0;i<count;i++){
            cout<<tab[i]<<" ";
        }
        cout<<endl;
    }

    void del(int value){
        if(check(value)){   //check is there value it the array: yes
            for(int i=0;i<count;i++){
                if(value==tab[i]){
                    for(int j=i;j<count;j++){
                        tab[j]=tab[j+1];
                    }
                }
            }
            count--;
        }else{  //check is there value it the array: no
            cout<<"This value is not in the tab!"<<endl;
        }
    }

    bool isEqual(Ensemble& ensemble2){
        bool equal=true;
        if(count!=ensemble2.count){    //if the capacity of two arrays is different, then they are not equal;
            equal=false;
        } else{
            for(int i=0;i<count;i++){
                if(tab[i]!=ensemble2.tab[i]){
                    equal= false;
                    break;
                }
            }
        }
        return equal;
    }

    void intersaction(Ensemble& ensemble2){
        for(int i=0;i<ensemble2.count;i++){
            if(!check(ensemble2.tab[i])){
                add(ensemble2.tab[i]);
            }
        }
    }

    void prime(){
        for(int i=0;i<count;i++){
            bool isPrime=true;
            for(int j=2;j<tab[i];j++){
                if(tab[i]%(j)==0){
                    isPrime=false;
                    break;
                }
            }
            if(isPrime){
                cout<<tab[i]<<" ";
            }
        }
    }

};