// Input:
// n = 6
// arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are 
// [0], [0], [0], [0], [0,0], and [0,0].

//we have to calculate all the subarray with sum=0


#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        
        // int count=0;
        //count all the single element with 0 value as subarray with sum 0;
        // for(int i=0;i<n;i++){
        //     if(arr[i]==0){
        //         count+=1;
        //     }
        // }
        
        ll sum=0;
        int temp=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int temp=0;
        for(int i=0;i<n;i++){
            temp+=arr[i];
            if(mp.find(temp) !=mp.end()){
                sum+=mp[temp];
                mp[temp]++;
            }
            else{
                mp[temp]++;
            }
        }
        return sum;
    }
};


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
} 