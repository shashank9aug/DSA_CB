// count squares : 

/*
    num=9
    output : 2

    num=3
    output : 1
*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int count_squareroot(int num){
    int ans=sqrt(num);

    if(ans*ans==num){
        return (ans-1);
    }
    else{
        return num;
    }
}


int main(){
    int number;
    cout<<"Enter number having some value : ";
    cin>>number;

    int ans=count_squareroot(number);
    cout<<ans;

    return 0;
}