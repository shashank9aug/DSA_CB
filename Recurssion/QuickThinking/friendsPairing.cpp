/*
    we have N friends
    each can go sigle or couple

    find no of ways n friends can go to party.

    N=3
    ways=4

*/

#include<iostream>
using namespace std;

int fact(int n){
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
    }
    return ans;
}

int nCr(int n,int r){
    return fact(n)/(fact(r)*fact(n-r));
}

int friendPairing(int n){
    //Base case :
    if(n==0 or n==1){
        return 1;
    }

    //rec case :
    int ans=0;

    //each can go either sigle or couple
    ans=1*friendPairing(n-1) + nCr(n-1,1)*friendPairing(n-2);

    return ans;
}


int main(){
    int n;
    cout<<"Enter number of friends : ";
    cin>>n;

    cout<<"Number of ways friends can go to party : "<<friendPairing(n)<<endl;

    return 0;
}