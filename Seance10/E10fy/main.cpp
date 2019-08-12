#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

class Debord{
private:
    long value;
    string message;
public:
    Debord(long v,string m){
        value=v;
        message=m;
    }
    long getValue(){
        return value;
    }
    void displayMessage(){
        cout<<message<<endl;
    }
};

class Short{
private:
    short value;
public:
    Short(long v){
        if(v>SHRT_MAX) {
            Debord debord(v, "Bigger then the limit");
            throw debord;
        } else if(v<SHRT_MIN){
            Debord debord(v,"Smaller then the limit");
            throw debord;
        } else{
            value=(short)v;
        }
    }

    friend ostream& operator<< (ostream& flood, const Short& s){
        flood<<s.value;
        return flood;
    }

    Short operator+ (const Short& s2) const{
        long v=value;
        long v2=s2.value;
        Short result(v+v2);
        return result;
    }

    Short operator- (const Short& s2) const{
        long v=value;
        long v2=s2.value;
        Short result(v-v2);
        return result;
    }

    Short operator* (const Short& s2) const{
        long v=value;
        long v2=s2.value;
        Short result(v*v2);
        return result;
    }

    Short operator/ (const Short& s2) const{
        long v=value;
        long v2=s2.value;
        Short result(v/v2);
        return result;
    }
};

int main() {

    long x,y;
    cout<<"Input 2 values:"<<endl;
    cin>>x>>y;

    try{
        cout<<"Debut of block try:"<<endl;
        Short s1(x);
        Short s2(y);
        cout<<"ADD="<<s1+s2<<endl;
        cout<<"Minus="<<s1-s2<<endl;
        cout<<"Multiply="<<s1*s2<<endl;
        cout<<"Divide="<<s1/s2<<endl;
        cout<<"follow the block try"<<endl;
    }catch (Debord excp){
        cout<<endl;
        excp.displayMessage();
        cout<<excp.getValue()<<endl;

    }
    cout<<"follow the catch"<<endl;

    return 0;
}