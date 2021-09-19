#include<iostream>
using namespace std;


int calGCD(int a,int b){
    //Base case: 
    if(b==0){
        return a;
    }
    calGCD(b,a%b);

    //1 line =>  return b==0 ? a : GCD(b,a%b); 
}


int main(){
    int a,b;
    cin>>a>>b;

    cout<<calGCD(a,b)<<endl;
    
    return 0;
}