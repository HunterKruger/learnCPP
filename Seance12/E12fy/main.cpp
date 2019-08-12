#include <iostream>
#include <fstream>   //used to read and write files
#include <string>
#include <vector>    //use vector
#include <map>        //use map
#include "algorithm"   //some algorithm like sort()
#include "Person.h"
#include "FunctionPerson.h"
#include "FunctionWord.h"
using namespace std;
#define List_of_person "person.txt"
#define List_of_word "word.txt"

vector<Person> vectorPerson;  //define vector
map<string,Person> mapPerson;  //define map
vector<string> vectorWord;

void readPersonFile(){
    ifstream file(List_of_person);
    bool finishReadFile = false;
    while (!finishReadFile){
        string name;
        int age;
        file>>name>>age;
        if(file.eof()){
            finishReadFile=true;
        }else{
            Person person(name,age);
            vectorPerson.push_back(person);  //insert person into VectorPerson at end of vector
            pair<string,Person> pairNamePerson(name,person);  //define a pair of string(name), Person
            pair<map<string,Person>::iterator,bool> pairMapBool;  //init the iterator of map,
                                                         //define a pair of iterator and bool
            pairMapBool= mapPerson.insert(pairNamePerson);   //insert pair into map
            if(pairMapBool.second==false){
                cout<<pairNamePerson.first<<"already displayed"<<endl;
            }
        }
    }
}

void readWordFile(){
    ifstream file(List_of_word);
    bool finishReadFile = false;
    while (!finishReadFile){
        string word;
        file>>word;
        if(file.eof()){
            finishReadFile=true;
        }else{
            vectorWord.push_back(word);
        }
    }
}

void displayVectorPerson(){
    int nbPerson=vectorPerson.size();
    for(int i=0;i<nbPerson;i++){
        vectorPerson[i].display();
    }
}

void displayVectorPersonByIterator(){
    vector<Person>::iterator it;
    for(it=vectorPerson.begin();it!=vectorPerson.end();it++){
        it->display();
    }
}

void displayMapPerson(){
    map<string,Person>::iterator it;
    for(it=mapPerson.begin();it!=mapPerson.end();it++){
        it->second.display(); //display "Person" part in map
    }
}

void displayAllPerson(){
    readPersonFile();
    cout<<"Display vector by index : "<<endl;
    displayVectorPerson();
    cout<<"Display vector by iterator : "<<endl;
    displayVectorPersonByIterator();
    cout<<"Display map: "<<endl;
    displayMapPerson();
    cout<<"Sort name : "<<endl;
    sort(vectorPerson.begin(),vectorPerson.end(),ComparePersonByName());
    displayVectorPerson();
    cout<<"Sort age: "<<endl;
    sort(vectorPerson.begin(),vectorPerson.end(),ComparePersonByAge());
    displayVectorPerson();
}

void displayAllWord(){
    readWordFile();
    cout<<"Display vector word: "<<endl;
    int nbWord=vectorWord.size();
    for(int i=0;i<nbWord;i++){
        cout<<vectorWord[i]<<endl;
    }

    cout<<"Display by FOR_EACH: "<<endl;
    for_each(vectorWord.begin(),vectorWord.end(),Display(true));
    for_each(vectorWord.begin(),vectorWord.end(),Display(false));
    cout<<endl;

    cout<<"Simple sort (alphabetic) :"<<endl;
    sort(vectorWord.begin(),vectorWord.end());
    for_each(vectorWord.begin(),vectorWord.end(),Display(true));
    cout<<endl;

    cout<<"Sort by length :"<<endl;
    sort(vectorWord.begin(),vectorWord.end());
    for_each(vectorWord.begin(),vectorWord.end(),Display(true));
    cout<<endl;

    string word;
    cout<<"word to be counted: ";
    cin>>word;
    cout<<"nb="<<count(vectorWord.begin(),vectorWord.end(),word)<<endl;

    int lengthMax;
    cout<<"Input length:";
    cin>>lengthMax;
    cout<<"word that shorter than lengthMax:"<<count_if(vectorWord.begin(),vectorWord.end(),LengthMax(lengthMax))<<endl;

    vector<string>::iterator it;
    it=find_if(vectorWord.begin(),vectorWord.end(),LengthMax(lengthMax));
    if(it!=vectorWord.end()){
        cout<<"The first word shorter than lengthMax is: "<<*it<<endl;
    }


}

int main() {

    displayAllPerson();
    displayAllWord();

    return 0;
}