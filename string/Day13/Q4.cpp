
//Next permutation

// Input: N = 6
// arr = {1, 2, 3, 6, 5, 4}
// Output: {1, 2, 4, 3, 5, 6}
// Explaination: The next permutation of the 
// given array is {1, 2, 4, 3, 5, 6}.

//We have use the intution of dictionary order 

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

//Brute force 




class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i,j;
        //find break point
        for(i=N-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                break;
            }
        }
        //if array has no break point : increasing or decreasing
        if(i<0){
            reverse(arr.begin(),arr.end());
        }
        //we have break point
        else{
            for(j=N-1;j>=0;j--){
                if(arr[j]>arr[i]){
                    break;
                }
            }
            swap(arr[i],arr[j]);
            //reverse from break point upto end
            reverse(arr.begin()+i+1,arr.end());
        }
        return arr;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
} 