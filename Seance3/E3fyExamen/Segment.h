//
// Created by 冯源 on 2018/10/27.
//

#ifndef E3FYEXAMEN_SEGMENT_H
#define E3FYEXAMEN_SEGMENT_H

#endif //E3FYEXAMEN_SEGMENT_H

#include "Point.h"
#include "iostream"
using namespace std;

class Segment{
private:
    Point origin;
    Point extreme;
public:
    Segment(float ox,float oy,float ex,float ey):origin(ox,oy),extreme(ex,ey){}  //the constructor recall the constructor of private member Point
    void display(){
        cout<<"origin:("<<origin.getX()<<","<<origin.getY()<<"),"
        <<"extreme:("<<extreme.getX()<<","<<extreme.getY()<<")"<<endl;
    }
    void translation(Point& newOrigin){  //input the new value of origin，extreme should be moved 
        float dx=newOrigin.getX()-origin.getX();
        float dy=newOrigin.getY()-origin.getY();
        origin.setX(newOrigin.getX());
        origin.setY(newOrigin.getY());
        extreme.setX(extreme.getX()+dx);
        extreme.setY(extreme.getY()+dy);
        cout<<"new origin:("<<origin.getX()<<","<<origin.getY()<<"),"
            <<"new extreme:("<<extreme.getX()<<","<<extreme.getY()<<")"<<endl;
    }
};