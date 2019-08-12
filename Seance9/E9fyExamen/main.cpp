#include <iostream>
#include "Point.h"
#include "Segment.h"
#include "Shape.h"
#include "fstream"  // Attention, include this for read and write files
#include "iomanip"  // Attention, include this for controlling output and input formats
using namespace std;

void FileFilterPoint(char* fileName, float maxDistance, char* newFileName){
    Point p0(0,0);
    ifstream file(fileName);   // create a file object to read whose name is fileName
    ofstream newFile(newFileName);  // create a file object to write whose name is newFileName
    bool finishFile=false;
    int countPoint=0;
    while (!finishFile){
        float x,y;
        file>>x>>y;   //read file and save coordinates in x and y
        if(file.eof()){
            finishFile=true;
        } else{
            Point p(x,y);
            double distance=p.distance(p0);
            if(distance<=maxDistance){
                newFile<<setfill('0')<<setw(3)<<countPoint   //display 001 002 003 : 0 and countPoint capture 3 positions
                <<": "<<" ("<<x<<"," <<y<<")"
                <<"   d="<<fixed<<setprecision(2)<<distance<<endl;  //fixed and setprecision(2): output 2 nums after "."
                countPoint++;
            }
        }
    }
}

int main() {
    FileFilterPoint("points.txt",40,"points2.txt");  //you can also input exact address instead of "points.txt"

    Point P1(12,6);
    Point P2(15,6);

    Circle C1(P1,3);
    C1.display();

    Segment Seg(P1,P2);

    Rectangle R1(Seg,8);
    R1.display();

    Square S1(Seg);
    S1.display();


    ShapeList sl;
    sl.addShape(&C1);
    sl.addShape(&R1);
    sl.addShape(&S1);
    //sl.display();
    sl.displayMax();
    return 0;


}