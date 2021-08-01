/*
    we have given string as lower case letters

    we have to output the permutations of that string with changing letters

    ip : ab
    op : ab , aB , Ab , AB

*/

#include<iostream>
#include<string>
using namespace std;

void changeCase(string ip,string op){
    //Base case : 
    if(ip.length()==0){
        cout<<op<<endl;
        return;
    }

    //IP-OP recurssive tree step:
    string op1=op;
    string op2=op;

    op1.push_back(ip[0]);
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin()+0);

    changeCase(ip,op1);
    changeCase(ip,op2);
    return;
}


int main(){
    string ip;
    cout<<"Enter input string : ";
    cin>>ip;

    string op;

    changeCase(ip,op);

    return 0;
}