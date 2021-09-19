/*
132
2^2
3^1
11^1
*/

#include<iostream>
#include<vector>
// #include<pair>
using namespace std;


void printFactor(int n){
    vector<pair<int,int>>vp;
    int count=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            count=0;
            //keep on divide by i till it is divisible.
            while(n%i==0){
                count++;
                n=n/i;
            }
            vp.push_back(make_pair(i,count));
        }
    }

    if(n!=1){
        //whatever left is prime in itself :
        vp.push_back(make_pair(n,1));
    }

    //print the factors :
    for(auto p:vp){
        cout<<p.first<<"^"<<p.second<<endl;
    }

    return;
}

int main(){
    int n;
    cin>>n;

    printFactor(n);


    return 0;
}