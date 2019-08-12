//
// Created by 冯源 on 2018/10/27.
//

#ifndef E3FYEXAMEN_POLYGONE_H
#define E3FYEXAMEN_POLYGONE_H

#endif //E3FYEXAMEN_POLYGONE_H

using namespace std;

class Polygone{
private:
    Point* pointTab;
    int countPoint;
public:
    Polygone(Point *pT, int cP) {  //common constructor，pT is Point type array pointer
        countPoint=cP;
        pointTab=new Point[countPoint];
        for(int i=0;i<countPoint;i++){
            pointTab[i]=pT[i];
        }
    }

    Polygone(Polygone& pg){   //copy constructor
        countPoint=pg.countPoint;
        pointTab=new Point[countPoint];
        for(int i=0;i<countPoint;i++){
            pointTab[i]=pg.pointTab[i];
        }
    }

    ~Polygone(){  //delete pointTab array
        delete [] pointTab;
    }
    void display(){
        for(int i=0;i<countPoint;i++){
            pointTab[i].display();
        }
    }
    float perimeter(){    //get the perimeter of poluygone
        float peri=0;
        for(int i=0;i<countPoint-1;i++){
            peri+=pointTab[i].distance(pointTab[i+1]);
        }
        peri+=pointTab[0].distance(pointTab[countPoint-1]); //the distance between the last and first element of array
        return peri;
    }
};