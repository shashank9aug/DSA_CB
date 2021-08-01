/*
    we have to take string as input and print all the possible subsets of string.

    "ab" = ["","a","b","ab"] 

    for this we will use method called  :  IP-OP method.

*/


#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void printSubsets(string str,string op){
    //Base case : 
    if(str.length()==0){
        cout<<op<<endl;
        return; 
    }

    //IP-OP step for recurssive tree : 
    string op1=op;
    string op2=op;

    op2.push_back(str[0]);

    //erase function takes input as an iterator : 
    str.erase(str.begin()+0);
    
    printSubsets(str,op1);
    printSubsets(str,op2);

    return;
}


int main(){
    string str;
    cout<<"Enter input strings : ";
    cin>>str;

    string op="";

    printSubsets(str,op);

    return 0;
}