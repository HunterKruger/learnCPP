//
// Created by 冯源 on 2018/10/27.
//

#ifndef E3FYEXAMEN_POINT_H
#define E3FYEXAMEN_POINT_H

#endif //E3FYEXAMEN_POINT_H

#include <iostream>
#include "math.h"
using namespace std;

class Point{
private:
    float x;
    float y;
public:
    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    void setX(float x) {
        this->x = x;
    }

    void setY(float y) {
        this->y = y;
    }

    Point(float x, float y){
        this->x=x;
        this->y=y;
    }

    Point(){}

    void display(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }

    bool isEqual(Point& point2){
        return (x==point2.x)&&(y==point2.y);
    }

    double distance(const Point& point2)const{
        return sqrt((x-point2.x)*(x-point2.x)+(y-point2.y)*(y-point2.y));
    }


};