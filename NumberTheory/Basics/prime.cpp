/*
    we have to find given number is prime or not
    - for small number
    - for large number
*/

#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

#define ll long long

//Naive Approach : O(N) =>  for 1 number 
// for n number O(N^2)
bool isPrime(int n){
    //1 -> coprime
    if(n==1){
        return false;
    } 

    //2 -> prime 
    if(n==2){
        return true;
    }

    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

//for 1 number : O(sqrt(N))
bool isPrimeM2(int n){
    //1 -> coprime
    if(n==1){
        return false;
    } 

    //2 -> prime 
    if(n==2){
        return true;
    }
    clock_t time_req;

    time_req = clock();
    
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    
    time_req=clock()-time_req;

    cout<<"second : "<<(float)time_req/CLOCKS_PER_SEC<<endl;
    return true;
}

int main(){
    cout<<isPrime(17)<<endl;
    cout<<isPrimeM2(17)<<endl;
}