#include <iostream>

using namespace std;
const int ANNEE_DE_BASE=1996;
struct Date{
    int jour;
    int mois;
    int annee;
};


void initialiseDate(Date &dd, int jj, int mm,int aa=ANNEE_DE_BASE){
    dd.jour=jj;
    dd.mois=mm;
    dd.annee=aa;
}

void displayDate(Date &dd){
    cout<<dd.jour<<"-"<<dd.mois<<"-"<<dd.annee<<endl;
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
    return 0;
}

