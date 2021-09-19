/*
PS D:\GitHub\Algo++\HashTable> ./a.exe
Name : Jalaj->9083,9084,9085,
Name : Shashank->8083,8084,8085,8086,

*/


#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    unordered_map<string,vector<string>>phonebook;

    phonebook["Shashank"].push_back("8083");
    phonebook["Shashank"].push_back("8084");
    phonebook["Shashank"].push_back("8085");
    phonebook["Jalaj"].push_back("9083");
    phonebook["Jalaj"].push_back("9084");
    phonebook["Jalaj"].push_back("9085");
    phonebook["Shashank"].push_back("8086");

    for(auto p:phonebook){
        cout<<"Name : "<<p.first<<"->";

        for(auto s:p.second){
            cout<<s<<",";
        }
        cout<<endl;
    }

    string name;
    cin>>name;

    /*
    PS D:\GitHub\Algo++\HashTable> ./a.exe
    Name : Jalaj->9083,9084,9085,
    Name : Shashank->8083,8084,8085,8086,
    Jalaj
    9083
    9084
    9085
    */
    //search : 
    if(phonebook.count(name)==0){
        cout<<"Absent";
    }
    else{
        for(auto s:phonebook[name]){
            cout<<s<<endl;
        }
    }

    return 0;
}