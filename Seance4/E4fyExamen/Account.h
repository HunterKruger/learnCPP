//
// Created by 冯源 on 2018/10/28.
//

#ifndef E4FYEXAMEN_COMPTE_H
#define E4FYEXAMEN_COMPTE_H

#endif //E4FYEXAMEN_COMPTE_H

#include "iostream"
using namespace std;

class Account{
private:
    String name;
    float balance;
    static float tax;  //static，can be initialized directly out of this class
    static Account* head;  //static，can be initialized directly out of this class
    Account* next;
public:
    Account(char* cc, float b=0):name(cc){
        balance=b;
        next=head;
        head=this;
    }
    static void modifyTax(float newTax){  //static，can be called out of this class，without initializing this class
        tax=newTax;
    }
    void payment(float price){
        balance-=price;
    }
    void update(){
        balance+=balance*tax/100;
    }
    void display(){
        cout<<"Name:";
        name.display();
        cout<<",balance:"<<balance<<endl;
    }
    static void updateAll(){  //static，can be called out of this class，without initializing this class
        Account* account=head;
        while (account!=0){
            account->update();
            account=account->next;
        }
    }
    static void displayAll(){  //static，can be called out of this class，without initializing this class
        Account* account=head;
        while (account!=0){
            account->display();
            account=account->next;
        }
    }
     ~Account(){
        Account *previous=0;
        Account *current=head;
        while (current!=this){
            previous=current;
            current=current->next;
        }
        if(previous!=0){
            previous->next=current->next;
        }else{
            head=current->next;
        }
    }

};