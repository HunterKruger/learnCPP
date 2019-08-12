//
// Created by 冯源 on 2018/10/29.
//

#ifndef E9FYEXAMEN_SHAPE_H
#define E9FYEXAMEN_SHAPE_H

#endif //E9FYEXAMEN_SHAPE_H

#include "iostream"
using namespace std;
const double PI=3.14;

class Shape{
private:
    Shape* next;
public:
    Shape(){
        next=0;
    }
    void setNext(Shape* nextShape){
        next=nextShape;
    }
    Shape* getNext() const{
        return next;
    }
    virtual double perimeter() const=0;  // =0 by default; must be virtual, impossible to use in a Shape object
    virtual double surface() const=0;  // =0 by default; must be virtual, impossible to use in a Shape object
    virtual void display() const=0;   // =0 by default; must be virtual, impossible to use in a Shape object
};

class Circle:public Shape{
private:
    Point center;
    double radius;
public:
    Circle(const Point& cc,double r):Shape(),center(cc.getX(),cc.getY()){  //Attention, center==cc.X and cc.Y
        radius=r;
    }
    double perimeter() const {  //const must be used , which means do not change other variables
        return radius*PI*PI;
    }
    double surface() const {   //const must be used , which means do not change other variables
        return 2*PI*radius;
    }
    void display() const {   //const must be used , which means do not change other variables
        cout<<"Circle Perimeter="<<perimeter()<<" Surface="<<surface()<<endl;
    }
};

class Rectangle:public Shape{
private:
    Segment length;
    double height;
public:
    Rectangle(Segment ll, double hh):Shape(),length(ll){   //Attention, length==ll
        height=hh;
    }
    double perimeter() const {  //const must be used , which means do not change other variables
        return  2*(height+length.length());
    }
    double surface() const {   //const must be used , which means do not change other variables
        return height*length.length();
    }
    void display() const {   //const must be used , which means do not change other variables
        cout<<"Rectangle Perimeter="<<perimeter()<<" Surface="<<surface()<<endl;
    }
};

class Square:public Rectangle{
private:
public:
    Square(const Segment& ee):Rectangle(ee,ee.length()){
    }
    void display() const {   //const must be used , which means do not change other variables
        cout<<"Square Perimeter="<<perimeter()<<" Surface="<<surface()<<endl;
    }
};

class ShapeList{
private:
    Shape* head;  //head pointer
public:
    ShapeList(){
        head=0;     //initialize the list, head pointer is null
    }
    void addShape(Shape* pShape){
        pShape->setNext(head);  //the new node's next node is the old head
        head=pShape;      //the head pointer always refers to the first node
    }
    void display()const{
        Shape* p=head;   //travel from head
        while (head!=0){    //head=0 means go to the end of the list
            p->display();
            p=p->getNext();
        }
    }
    void displayMax()const{
        double maxPerimeter=0, maxSurface=0;
        Shape* pMaxPerimeter=0;    //it refers to the shape whose perimeter is the biggest
        Shape* pMaxSurface=0;      //it refers to the shape whose surface is the biggest
        Shape* p1=head;     //travel from head to find the shape whose perimeter is the biggest
        Shape* p2=head;     //travel from head the shape whose surface is the biggest

        while (p1!=0){
            if(p1->perimeter()>maxPerimeter){
                pMaxPerimeter=p1;
                maxPerimeter=p1->perimeter();
            }
            p1=p1->getNext();
        }

        while (p2!=0){
            if(p2->surface()>maxSurface){
                pMaxSurface=p2;
                maxSurface=p2->surface();
            }
            p2=p2->getNext();
        }

        if(pMaxPerimeter!=0){
            cout<<"Max perimeter:"<<maxPerimeter<<endl;
            pMaxPerimeter->display();
        }

        if(pMaxSurface!=0){
            cout<<"Max surface"<<maxSurface<<endl;
            pMaxSurface->display();
        }
    }

};