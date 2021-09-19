/*
PS D:\GitHub\Algo++\NumberTheory\Basics> ./a.exe
25
2, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25,
*/

#include<iostream>
#include<cstring>
using namespace std;

#define MAX 1000000
#define ll long long

//generate a array containing prime numbers :
void primeSeive(int n){

    bool prime[n+1];
    memset(prime,false,sizeof(prime));

    //mark all odd numbers as prime no : 
    for(int i=3;i<=n;i+=2){
        prime[i]=true;
    }

    //Seive : 
    for(int i=3;i<=n;i+=2){
        //if Current element is not marked : (it is prime)
        if(prime[i]==true){
            //mark all the multiples of i as not prime :
            for(ll j=i*i;j<=n;j=j+i){
                prime[j]=false;
            }
        }
    }
    prime[2]=true,prime[0]=prime[1]=false;

    for(ll i=2;i<n;i++){
        if(prime[i]==true){
            cout<<i<<", ";
        }
    }
}


int main(){
    int n;
    cin>>n;

    primeSeive(n);

    return 0;
}