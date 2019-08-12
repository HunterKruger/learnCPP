#include <iostream>

using namespace std;
const int VOLUME = 10;

class Ensemble{

private:

    int tab[VOLUME];
    int elementCount;

public:

    Ensemble(){
        elementCount=0;
    }

    bool check(int value)  {
        bool isExisted= false;
        for(int i=0;i<elementCount;i++){
            if(value==tab[i]){
                isExisted= true;
                break;
            }
        }
        return isExisted;
    }

    void del(int value){
        if(check(value)){
            for(int i=0;i<elementCount;i++){
                if(tab[i]==value){
                    for(int j=i;j<elementCount;j++){
                        tab[j]=tab[j+1];
                    }
                    elementCount--;
                }
            }
        }else{
            cout<<"cannot find this value in the Tab."<<endl;
        }
    }

    void add(int value){
        if(elementCount<VOLUME){
            if(!check(value)){
                tab[elementCount]=value;
                elementCount++;
            }else {
                cout<<"This value is already in the tab!"<<endl;
            }
        }else{
            cout<<"The tab is full."<<endl;
        }
    }

    void displayTab(){
        for(int i=0;i<elementCount;i++){
            cout<<tab[i]<<" ";
        }
        cout<<endl;
    }

    bool isEqual(Ensemble &ensemble2){
        bool bb=true;
        if(this->elementCount!=ensemble2.elementCount){
            bb=false;
        }else{
            for(int i=0;i<this->elementCount;i++){
                if(this->check(ensemble2.tab[i])==false){
                    bb=false;
                    break;
                }
            }
        }
        return bb;
    }

    void intersaction(Ensemble &ensemble2){
        Ensemble inter;
        for(int i=0;i<elementCount;i++){
            if(ensemble2.check(this->tab[i])){
                inter.add(this->tab[i]);
            }
        }
        inter.displayTab();
    }

    void findPrime(){
        Ensemble prime;
        for(int i=0;i<elementCount;i++){
            bool isPrime= true;
            for(int j=2;j<=tab[i]/2;j++){
                if(tab[i]%j==0){
                    isPrime= false;
                    break;
                }
            }
            if(isPrime){
                //cout<<i<<" ";
                prime.add(tab[i]);
            }
        }
        prime.displayTab();
    }


};

int main() {

    Ensemble ensemble;
    ensemble.add(5);
    ensemble.add(3);
    ensemble.add(32);
    ensemble.add(52);
    ensemble.add(31);

    ensemble.displayTab();

    cout<<ensemble.check(43)<<endl;
    cout<<ensemble.check(3)<<endl;

    ensemble.add(52);
    ensemble.displayTab();

    ensemble.del(32);
    ensemble.displayTab();

    Ensemble ensemble2;
    ensemble2.add(5);
    ensemble2.add(3);
    ensemble2.add(52);
    ensemble2.add(31);
    ensemble2.displayTab();

    cout<<ensemble.isEqual(ensemble2)<<endl;

    Ensemble ensemble3;
    ensemble3.add(5);
    ensemble3.add(3);
    ensemble3.add(57);
    ensemble3.add(31);
    ensemble3.displayTab();

    ensemble3.intersaction(ensemble2);

    Ensemble ensemble4;
    ensemble4.add(17);
    ensemble4.add(18);
    ensemble4.add(19);
    ensemble4.add(25);
    ensemble4.displayTab();

    ensemble4.findPrime();


    return 0;
}