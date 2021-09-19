/*
    Give100000 Queries to find prime    number in range : 
    a b

    return count no of prime in range 
*/

#include<iostream>
#include<cstring>
using namespace std;



//generate a array containing prime numbers :
void primeSeive(int *prime){

    //mark all odd numbers as prime no : 
    for(int i=3;i<=1000000;i+=2){
        prime[i]=1;
    }

    //Seive : 
    for(long long i=3;i<=1000000;i+=2){
        //if Current element is not marked : (it is prime)
        if(prime[i]==1){
            //mark all the multiples of i as not prime :
            for(long long j=i*i;j<=1000000;j=j+i){
                prime[j]=0;
            }
        }
    }
    prime[2]=1,prime[0]=prime[1]=0;
}


int main(){
    int prime[1000005]={0};

    primeSeive(prime);

    int csum[1000005]={0};

    for(int i=1;i<=1000000;i++){
        csum[i]=csum[i-1]+prime[i];
    }

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;

        cout<<csum[b]-csum[a-1]<<endl;
    }

    return 0;
}