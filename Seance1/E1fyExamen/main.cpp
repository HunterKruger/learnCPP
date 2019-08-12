#include <iostream>
using namespace std;

const int DEFAULT_YEAR = 2018;

struct Date{
    int day;
    int month;
    int year;
};

void initializeDate (Date& dd, int d,int m,int y=DEFAULT_YEAR){    //if do not input y when initialization,
                                                                   // then default y=DEFAULT_YEAR
    dd.day=d;
    dd.month=m;
    dd.year=y;
}

void displayDate (Date& dd){
    cout<<dd.year<<"-"<<dd.month<<"-"<<dd.day<<endl;
}

bool compareDate(Date& dd1, Date& dd2){
    return (dd1.day==dd2.day)&&(dd1.month=dd2.month)&&(dd1.year==dd2.year);
}

bool compareDate(Date& dd, int d,int m,int y){
    return (dd.day==d)&&(dd.month==m)&&(dd.year==y);
}

struct ListDate{
    Date* date;
    int count;
};

void initializeListDate(ListDate& ld,int c){
    ld.count=c;
    ld.date=new Date[c];   //init Date array， ld.date is a pointer array, whose capacity is c
    for(int i=0;i<c;i++){
        initializeDate(ld.date[i],1,1,DEFAULT_YEAR);  // use 1st Jan of DEFAULT_YEAR to inti DateList
    }
}

void displayListDate(ListDate& ld){
    for(int i=0;i<ld.count;i++){
        displayDate(ld.date[i]);
    }
}

void modifyDate(ListDate& ld, Date& d, int i){
    if(i>=ld.count|i<0){    //check is i out of bound of array or not
        return ;
    } else{
        ld.date[i]=d;
    }
}

void deleteListDate(ListDate& ld){
    delete[] ld.date;         //delete array to release RAM
}

int main() {

    Date date1;
    initializeDate(date1,23,6,1996);
    displayDate(date1);

    Date date2;
    initializeDate(date2,23,6,1996);
    cout<<compareDate(date1,date2)<<endl;

    Date date3;
    initializeDate(date3,10,24);
    cout<<compareDate(date1,date3)<<endl;
    cout<<compareDate(date1,23,6,96)<<endl;


    ListDate ld;
    initializeListDate(ld,4);
    displayListDate(ld);
    modifyDate(ld,date1,2);
    displayListDate(ld);

    deleteListDate(ld);

    return 0;
}