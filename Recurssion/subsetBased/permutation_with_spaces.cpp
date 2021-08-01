/*
    we will have input string 
    ip="ABC"

    we will have to print all the possible strings that can be made after adding spaces
    between two letters : 
    A_B_C
    AB_C
    A_BC
    ABC
*/

#include<iostream>
#include<string>
using namespace std;

void generateString(string ip,string op){
    //Base case : at leaf node we will get all the op string and ip will be empty
    if(ip.length()==0){
        cout<<op<<endl;
        return;
    }

    string op1=op;
    string op2=op;

    op1.push_back('_');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);

    ip.erase(ip.begin()+0);

    generateString(ip,op1);
    generateString(ip,op2);

    return;
}

int main(){
    string ip;
    cout<<"Enter input string : ";
    cin>>ip;

    string op="";

    //first we can not add spaces before letter and after letter spaces must be in between letters
    op.push_back(ip[0]);
    //erase that letter for next step in recurssive tree
    ip.erase(ip.begin()+0);
    
    generateString(ip,op);

    return 0;
}