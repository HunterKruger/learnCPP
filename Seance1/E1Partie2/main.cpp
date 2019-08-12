#include <iostream>

using namespace std;
const int ANNEE_DE_BASE=2018;
struct Date{
    int jour;
    int mois;
    int annee;
};

struct ListDate{
    Date* date;
    int count;
};

void initialiseDate(Date &dd, int jj, int mm,int aa=ANNEE_DE_BASE){
    dd.jour=jj;
    dd.mois=mm;
    dd.annee=aa;
}

void initialiseListDate(ListDate &listDate,int c){
    listDate.count=c;
    listDate.date=new Date[c];
    for(int i=0;i<c;i++){
        initialiseDate(listDate.date[i],1,1,ANNEE_DE_BASE);
    }
}

void displayDate(Date &dd){
    cout<<dd.jour<<"-"<<dd.mois<<"-"<<dd.annee<<endl;
}

void displayListDate(ListDate &ld){
    for(int i=0;i<ld.count;i++){
        displayDate(ld.date[i]);
    }
}

void modifyDate(ListDate &ld, Date &dd,int n){
    if(n<1||n>ld.count){
        return;
    }
    ld.date[n-1]=dd;
}

void deleteListDate(ListDate &ld){
    delete[] ld.date;
}


bool compareDate(const Date &dd,int jj,int mm,int aa){
    return dd.annee==aa && dd.mois==mm && dd.jour==jj;
}

bool compareDate2(const Date &dd1,const Date &dd2){
    return compareDate(dd1,dd2.jour,dd2.mois,dd2.annee);
}

int main() {
    Date date1;
    initialiseDate(date1,23,6);
    displayDate(date1);
    Date date2={2,5,2018};
    displayDate(date2);
    cout<<compareDate(date1,23,6,1996)<<endl;
    cout<<compareDate2(date1,date2)<<endl;

    ListDate ld;
    initialiseListDate(ld,4);
    displayListDate(ld);
    modifyDate(ld,date1,2);
    displayListDate(ld);

    deleteListDate(ld);

    return 0;
}

