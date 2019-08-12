#include <iostream>
#include <math.h>
using namespace std;

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
        cout<<"("<<getX()<<","<<getY()<<")";
    }

    void equalTwoPoint(Point &b){
        if((getX()==b.getX())&&(getY()==b.getY())){
            cout<<"These two points are the same."<<endl;
        }else{
            cout<<"These two points are different."<<endl;
        }
    }

    float calculateDistance(Point &b){
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

};

class Polygone{

private:

    Point *pointTab;
    int countPoint;

public:

    Polygone(Point *pT, int cP){
        countPoint=cP;
        pointTab=new Point[countPoint];
        for(int i=0;i<countPoint;i++){
            pointTab[i]=pT[i];
        }
    }

    Polygone(Polygone& pg){
        countPoint=pg.countPoint;
        pointTab=new Point[countPoint];
        for(int i=0;i<countPoint;i++){
            pointTab[i]=pg.pointTab[i];
        }
    }

    ~Polygone(){
        delete []pointTab;
    }

    void display() const {
        for(int i=0;i<countPoint;i++){
            pointTab[i].display();
            cout<<"__";
        }
        pointTab[0].display();
        cout<<endl;
    }

    float perimeter() const {
        float peri=0;
        for(int i=0;i<countPoint-1;i++){
            peri+=pointTab[i].calculateDistance(pointTab[i+1]);
        }
        peri+=pointTab[countPoint-1].calculateDistance(pointTab[0]);
        return peri;
    }


};

int main() {

    Point pointTab[5]={Point(1.0,1.0),Point(3.0,1.0),Point(2.0,4.0),Point(4.0,4.0),Point(1.0,3.0)};
    Polygone pg(pointTab,5);
    pg.display();
    cout<<pg.perimeter();

    return 0;
}