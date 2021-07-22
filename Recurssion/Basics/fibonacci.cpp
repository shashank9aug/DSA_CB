/*
    Just try to visualize the recurssion tree formed during function call execution
    it's basically  recurssion tree : 
        which will expand accordingly.

*/

#include<iostream>
using namespace std;

int fibo(int n){
    //Base case : 
    if(n==0 or n==1){
        return n;
    }

    //reccurssive case : 
    int f1=fibo(n-1);
    int f2=fibo(n-2);

    return f1+f2;
}


int main(){
    int n;
    cout<<"Enter nth value : ";
    cin>>n;

    cout<<"nth fibonacci is : "<<fibo(n)<<endl;
    return 0;
}