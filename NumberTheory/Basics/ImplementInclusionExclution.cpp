/*
    PS : given n as integer number find number of numbers between 1 to n 
        which are divisible by any of the prime no less than 20.

ip-op : 5 -> 4
        10 -> 9
        12 -> 11
        15 -> 14
        18 -> 17 

PS D:\GitHub\Algo++\NumberTheory\Basics> ./a.exe
5
5 10 12 15 18
4 9 11 14 17         

*/


#include<iostream>
using namespace std;

#define ll long long

int main(){
    ll t;
    cin>>t;

    //prime no in range 1 to 20 
    int prime[]={2,3,5,7,11,13,17,19};

    while(t--){
        ll n;
        cin>>n;

        //subsets will be in range 2^N -1 
        ll subsets = (1<<8)-1;
        ll ans=0;

        for(int i=1;i<=subsets;i++){
            //denominator will be different  as N/product or prime no in current subset
            ll denom=1ll;
            //count all the set bits in given number :
            ll setBits = __builtin_popcount(i);

            //iterate over bits of number :
            for(ll j=0;j<=7;j++){
                //check bit at jth position as setbit or not .
                //0100010 => (1<<1)  => 0000010 => no&mask => mask=(1<<j)
                if(i&(1<<j)){
                    denom*=prime[j];        
                }
            }
            //if setBits will be odd
            if(setBits&1){
                ans+=n/denom;
            }            
            else{
                ans-=n/denom;
            }
        }
        cout<<ans<<" ";
    }

    return 0;
}