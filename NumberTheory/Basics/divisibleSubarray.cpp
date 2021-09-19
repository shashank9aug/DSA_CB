/*

2
5
1 1 1 1 1
5
5 5 5 5 5

In first test case, there is only one sub-array [1, 1, 1, 1, 1], 
such that 1+1+1+1+1=5, which is divisible by N=5

*/


#include<iostream>
#include<cstring>
using namespace std;

#define ll long 

ll arr[1000005] , freq[1000005];
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        memset(freq,0,sizeof(freq));
        freq[0]=1;

        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            //for cummulative sum 
            sum+=arr[i];

            sum=sum%n;
            sum=(sum+n)%n;

            //store frequency with same sum
            freq[sum]++;
        }

        ll ans=0;
        //ans+=freq^C^2
        for(int i=0;i<n;i++){
            ll m=freq[i];
            ans+=m*(m-1)/2;
        }

        cout<<ans<<endl;
    }

    return 0;
}