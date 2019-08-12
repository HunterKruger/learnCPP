#include <iostream>
#include "string.h"
using namespace std;

// C++多态(polymorphism)是通过虚函数来实现的，虚函数允许子类重新定义成员函数，
// 而子类重新定义父类的做法称为覆盖(override)，或者称为重写。
// 最常见的用法就是声明基类的指针，利用该指针指向任意一个子类对象，调用相应的虚函数，动态绑定。
// 由于编写代码的时候并不能确定被调用的是基类的函数还是哪个派生类的函数，所以被成为“虚”函数。
// 如果没有使用虚函数的话，即没有利用C++多态性，则利用基类指针调用相应的函数的时候，
// 将总被限制在基类函数本身，而无法调用到子类中被重写过的函数。

class Animal{
private:
    string name;
    string characteristic;
public:
    Animal(string n,string c){
        name=n;
        characteristic=c;
    }
    void display(){
        cout<<"Name:"<<name<<" Characteristic:"<<characteristic<<endl;
    }
    virtual void speak(){
    };
};

class Chien:public Animal{
public:
    Chien(string n):Animal(n,"fidele"){
    }
    void speak(){
        cout<<"I can aboie"<<endl;
    }
};

class Cheval:public Animal{
public:
    Cheval(string n):Animal(n,"galope"){
    }
    void speak(){
        cout<<"I can hennit"<<endl;
    }
};

class Oiseau:public Animal{
public:
    Oiseau(string n):Animal(n,"vole"){
    }
};

class Pigeon:public Oiseau{
public:
    Pigeon(string n):Oiseau(n){
    }
    void speak(){
        cout<<"I can roucoule"<<endl;
    }
};

class Corbeau:public Oiseau{
public:
    Corbeau(string n):Oiseau(n){
    }
    void speak(){
        cout<<"I can croasse"<<endl;
    }
};

class Rossignol:public Oiseau{
public:
    Rossignol(string n):Oiseau(n){
    }
    void speak(){
        cout<<"I can chante"<<endl;
    }
};

const int SIZE=100;

class ListAnimal{
private:
    Animal* ptAnimal[SIZE];
    int count;
public:
    ListAnimal(){
        count=0;
    }
    void add(Animal &animal){
        if(count<SIZE){
            ptAnimal[count]=&animal;
            count++;
        }
    }
    void display(){
        for(int i=0;i<count;i++){
            cout<<"*******************************"<<endl;
            ptAnimal[i]->display();
            ptAnimal[i]->speak();
        }
    }

};


int main() {

    Animal animal("Human","Stupid");
    animal.display();

    Chien chien("Chien");
    chien.display();
    chien.speak();

    Animal* pa=&chien;
    pa->display();
    pa->speak();

    Cheval cheval("Cheval");

    Oiseau oiseau("Oiseau");
    oiseau.display();
    oiseau.speak();

    Pigeon pigeon("Pigeon");
    pigeon.display();
    pigeon.speak();

    Corbeau corbeau("Corbeau");

    Rossignol rossignol("Rossignol");


    ListAnimal listAnimal;
    listAnimal.add(chien);
    listAnimal.add(cheval);
    listAnimal.add(oiseau);
    listAnimal.add(pigeon);
    listAnimal.add(corbeau);
    listAnimal.add(rossignol);

    listAnimal.display();
    //Animal* pa=&chien;
    //pa->display();
    return 0;
}