#include <iostream>

// e1.cpp

#include <iostream>
using namespace std;

struct Date
{
    int jour, mois, annee;
};

struct ListeDates
{
    int nbjours;
    Date* dat;
};

const int ANNEE_BASE = 2000;

void init (Date& dat, int j, int m, int a = ANNEE_BASE);
void afficher (const Date& dat);
bool comparer (const Date& dat1, const Date& dat2);
bool comparer (const Date& dat, int j, int m, int a);

void init(ListeDates& liste, int nbjours);
void afficher(const ListeDates& liste);
void modifier(ListeDates& liste, const Date& dat, int n);
void liberer(ListeDates& liste);

void init (Date& dat, int j, int m, int a)
{
    dat.jour = j;
    dat.mois = m;
    dat.annee = a;
}

void afficher (const Date& dat)
{
    cout << dat.jour << "/" << dat.mois << "/" << dat.annee << endl;
}

bool comparer (const Date& dat1, const Date& dat2)
{
    if (dat1.annee == dat2.annee && dat1.mois == dat2.mois && dat1.jour == dat2.jour)
        return true;
    return false;
}

bool comparer (const Date& dat, int j, int m, int a)
{
    if (dat.annee == a && dat.mois == m && dat.jour == j)
        return true;
    return false;
}

void init(ListeDates& liste, int n)
{
    liste.nbjours = n;
    liste.dat = new Date[n];

    for (int i = 0; i < n; i++)
        init(liste.dat[i], 1, 1, ANNEE_BASE + i);
}

void afficher(const ListeDates& liste)
{
    for (int i = 0; i < liste.nbjours; i++)
        afficher(liste.dat[i]);
}

void modifier(ListeDates& liste, const Date& dat, int n)
{
    if (n<1 || n>liste.nbjours) return;
    liste.dat[n-1] = dat;
}

void liberer(ListeDates& liste)
{
    delete[] liste.dat;
}

int main ()
{
    int j1, m1, j2, m2, a2;

    cout << "saisir jour/mois de annee ref: ";
    cin >> j1 >> m1;
    cout << "saisir une date : ";
    cin >> j2 >> m2 >> a2;

    Date date1, date2;
    init (date1, j1, m1);
    init (date2, j2, m2, a2);

    afficher (date1);
    afficher (date2);

    cout << "comparer date1/date2 : " << comparer (date1,date2) << endl;
    cout << "comparer date1/entiers : " << comparer (date1,j2,m2,a2) << endl;

    ListeDates liste;
    init(liste, 4);
    afficher(liste);
    modifier(liste, date1, 1);
    modifier(liste, date2, 2);
    afficher(liste);

    liberer(liste);

    return 0;
}
