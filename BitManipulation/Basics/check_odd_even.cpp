#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int ans=n&1;

    if(ans){
        cout<<"odd";
    }
    else{
        cout<<"even";
    }

    return 0;
}