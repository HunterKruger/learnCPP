#include <iostream>
#include "fstream"
#include "iomanip"
#include <math.h>
using namespace std;
const float PI=3.14;

class Point{

private:

    float x;
    float y;

public:

    Point(float x, float y){
        this->x=x;
        this->y=y;
    }

    Point(){}

    float getX() const { return this->x;}

    float getY() const { return this->y;}

    void setX(float xNew){ x=xNew;}

    void setY(float yNew){ y=yNew;}

    void display(){
        cout<<"("<<getX()<<","<<getY()<<")"<<endl;
    }

    void equalTwoPoint(Point &b){
        if((getX()==b.getX())&&(getY()==b.getY())){
            cout<<"These two points are the same."<<endl;
        }else{
            cout<<"These two points are different."<<endl;
        }
    }

    float calculateDistance(const Point &b) const{
        float distance;
        distance=sqrtf(pow((getX()-b.getX()),2)+pow((getY()-b.getY()),2));
        //cout<<"The distance between these two points is "<<distance<<"."<<endl;
        return distance;
    }

};

class Segment{

private:

    Point origin;
    Point extreme;

public:

    Segment(float x1, float y1, float x2, float y2):origin(x1,y1),extreme(x2,y2){

    }

    Segment(Point& P1,Point& P2):origin(P1.getX(),P1.getY()),extreme(P2.getX(),P2.getY()){

    }

    void display(){
        cout<<"The origin point is ("<<this->origin.getX()<<","<<this->origin.getY()<<"), ";
        cout<<"and the extreme point is ("<<this->extreme.getX()<<","<<this->extreme.getY()<<").";
        cout<<endl;
    }

    void translation(const Point &newOrigin){
        float DX = newOrigin.getX()-this->origin.getX();
        float DY = newOrigin.getY()-this->origin.getY();
        this->extreme.setX(this->extreme.getX()+DX);
        this->extreme.setY(this->extreme.getY()+DY);
        cout<<"The new origin point is ("<<newOrigin.getX()<<","<<newOrigin.getY()<<"), ";
        cout<<"and the new extreme point is ("<<this->extreme.getX()+DX<<","<<this->extreme.getY()+DY<<").";
        cout<<endl;
    }

    double length() const{
        return origin.calculateDistance(extreme);
    }

};

void FileFilterPoint(const char* fileName, float distanceMax, const char* fileNameDestination){
    Point P0(0,0);
    ifstream file(fileName);
    ofstream fileDestination(fileNameDestination);
    bool finishFile = false;
    int numPoint=0;
    while(!finishFile){
        float x;
        float y;
        file >> x >> y;
        if(file.eof()){
            finishFile=true;
        }else{
            Point P(x,y);
            float distance=P.calculateDistance(P0);
            if(distance<distanceMax){
                fileDestination<<setfill('0')<<setw(3)<<numPoint         //0和numPoint共占据3个位置
                <<": "<<" ("<<x<<"," <<y<<")"
                <<"   d="<<fixed<<setprecision(2)<<distance<<endl;
                numPoint++;
            }
        }
    }
}

class Forme{
private:
    Forme* next;
public:
    Forme(){
        next=0;
    }
    void setNext(Forme* nextForme){
        next=nextForme;
    }
    Forme* getNext() const{
        return next;
    }
    virtual double perimeter() const=0;
    virtual double surface() const=0;
    virtual void display() const=0;
};

class Circle:public Forme{
private:
    Point center;
    double radius;
public:
    Circle(const Point& cen, double rad):Forme(),center(cen.getX(),cen.getY()){
        radius=rad;
    }
    double perimeter() const{
        return radius*2*PI;
    }
    double surface() const{
        return radius*radius*PI;
    }
    void display() const{
        cout<<"Circle's perimeter is "<< perimeter() << ", surface is "<<surface()<<endl;
    }
};

class Rectangle:public Forme{
private:
    Segment segmentLength;
    double height;
public:
    Rectangle(const Segment& sgL, double h):Forme(),segmentLength(sgL){
        height=h;
    }
    double surface() const{
        return segmentLength.length()*height;
    }
    double perimeter() const{
        return 2*(segmentLength.length()+height);
    }
    void display() const{
        cout<<"Rectangle's perimeter is "<< perimeter() << ", surface is "<<surface()<<endl;
    }
};

class Square:public Rectangle{
private:
public:
    Square(const Segment& side):Rectangle(side,side.length()){}
    void display() const{
        cout<<"Square's perimeter is "<< perimeter() << ", surface is "<<surface()<<endl;
    }
};

class ListForme{
private:
    Forme* head;
public:
    ListForme(){
        head=0;
    }
    void add(Forme* pForme){
        pForme->setNext(head);
        head=pForme;
    }
    void display() const{

        Forme* p=head;
        while (head!=0){
            p->display();
            p=p->getNext();
        }
    }
    void displayMax() {
        double maxPerimeter=0, maxSurface=0;
        Forme* pFormeMaxPerimeter=0;
        Forme* pFormeMaxSurface=0;
        Forme* p1=head;
        Forme* p2=head;
        while(p1!=0){

            if(p1->perimeter()>=maxPerimeter){
                pFormeMaxPerimeter=p1;
                maxPerimeter=p1->perimeter();
            }
            p1=p1->getNext();
        }

        while(p2!=0){
            if(p2->surface()>=maxSurface){
                pFormeMaxSurface=p2;
                maxSurface=p2->surface();
            }
            p2=p2->getNext();
        }

        if(pFormeMaxPerimeter!=0){
            cout<<"Max perimeter = "<< maxPerimeter <<endl;
            pFormeMaxPerimeter->display();
        }
        if(pFormeMaxSurface!=0){
            cout<<"Max surface = "<< maxSurface<<endl;
            pFormeMaxSurface->display();
        }
    }
};

int main() {

    FileFilterPoint("points.txt",40,"points2.txt");

    Point P1(12,6);
    Point P2(15,6);

    Circle C1(P1,3);
    C1.display();

    Segment Seg(P1,P2);

    Rectangle R1(Seg,8);
    R1.display();

    Square S1(Seg);
    S1.display();

    ListForme lf;
    lf.add(&C1);
    lf.add(&R1);
    lf.add(&S1);
    //lf.display();
    lf.displayMax();


    return 0;
}