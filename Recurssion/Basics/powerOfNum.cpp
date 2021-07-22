/*
    we have to find power of given number recurssively :

    power(a,n);

    a^n = a^n * a^(n-1) * a^(n-2)....*a^0

*/

#include<iostream>
using namespace std;

int powerNum(int num,int n){
    //Base case : 
    if(num==1){
        return 1;
    }
    else if(n==0){
        return 1;
    }

    //Rec case : 
    return num*powerNum(num,n-1);
}


int main(){
    int n;
    cout<<"Enter the power : ";
    cin>>n;

    int num;
    cout<<"Enter number : ";
    cin>>num;

    cout<<powerNum(num,n)<<endl;

    return 0;
}