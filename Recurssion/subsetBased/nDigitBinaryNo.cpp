/*
    We have n as integer value 
    
    we have to print all the possible binary strings in which no of 1's will be greater than 
    the no of 0's

    n=3
    101
    110
    111
*/

#include<iostream>
#include<string>
using namespace std;

void nDigitBinary(int n,int one,int zero,string op){
    //Base case : 
    if(n==0){
        cout<<op<<endl;
        return;
    }

    //reccursive tree : codeflow 
    //option to add 1 is always available in recurssive tree 
    string op1=op;
    op1.push_back('1');
    nDigitBinary(n-1,one+1,zero,op1);

    if(one>zero){
        string op2=op;
        op2.push_back('0');
        nDigitBinary(n-1,zero+1,one,op2);
    }

    return;
}

int main(){
    int n;
    cout<<"no of digit in binary string : ";
    cin>>n;

    string op;
    int one=0;
    int zero=0;
    nDigitBinary(n,one,zero,op);

    return 0;
}