/*
                ---important---
    There are two ways for function call : 
        ->Increasing order : We are calling function after output statement 
            will be in top to bottom (Base) 

        ->decreasing order  : we are calling function before output statement 
            will be in bottom (Base) to top

*/


#include<iostream>
using namespace std;

//decreasing order
void dec(int n){
    //Base case : 
    if(n==0){
        return;
    }

    //rec case : 
    cout<<n<<",";
    dec(n-1);
}

//Increasing order : 
void inc(int n){
    
    //Base case : 
    if(n==0){
        return;
    }
    
    //rec case : 
    inc(n-1);
    cout<<n<<",";
}

int main(){
    int n;
    cout<<"Enter value of n : ";
    cin>>n;

    dec(n);
    cout<<endl;
    inc(n);
    return 0;
}