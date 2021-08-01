/*
    We have one integer value n;
    we have to use n no of open and n no of closing braces

    we have to print all the possible balanced paranthesis from n close and open braces

    Making recurssive tree is job
    writing code = cakework

    Enter number of closing and opening braces : 3
    ((()))
    (()())
    (())()
    ()(())
    ()()()

*/

#include<iostream>
#include<string>
using namespace std;

void balanceParanthesis(int open,int close,string op){
    //Base case :
    if(open==0 && close==0){
        cout<<op<<endl;
        return;
    }

    //if open >0  then we can add opening braces first;
    if(open!=0){
        string op1=op;
        op1.push_back('(');
        balanceParanthesis(open-1,close,op1);
    }
    //when open will be completwly 0 
    if(close>open){
        string op2=op;
        op2.push_back(')');
        balanceParanthesis(open,close-1,op2);
    }
    return;
}

int main(){
    int n;
    cout<<"Enter number of closing and opening braces : ";
    cin>>n;

    string op;
    int open=n;
    int close=n;
    balanceParanthesis(open,close,op);

    return 0;
}

