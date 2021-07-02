// Input:
// n = 6
// a[] = {5,5,10,100,10,5}
// Output: 110
// Explanation: 5+100+5=110

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//


class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int loot1=0;
        int loot2=0;
        
        if(n%2==0){
            //first loot1 0 to <n-1
            for(int i=0;i<(n-1);i+=2){
                loot1+=arr[i];
            }
            
            //second loot2 1 to <n
            for(int i=1;i<n;i+=2){
                loot2+=arr[i];
            }
            
            return max(loot1,loot2);
        }
        //for odd no of elements
        else{
            for(int i=0;i<n;i+=2){
                loot1+=arr[i];
            }
            
            for(int i=1;i<(n-1);i+=2){
                loot2+=arr[i];
            }
            
            return max(loot1,loot2);
        }
    }
};


int main(){
    int n;
    cout<<"Enter the number of elements in array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements in array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution ob;

    cout<<ob.FindMaxSum(arr,n)<<endl;

    return 0;
}