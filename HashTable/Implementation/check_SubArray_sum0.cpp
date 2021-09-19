/*
    ps : We have array in which we have to find their is any subarray whose sum==0 then return YES else NO

    arr[]={6,-1,2,-1,2,-1}
    -> YES (-1,2,-1)

We have 3 Approach : 
    - O(N^3) Generate all the subarray and check their sum simultaneously 
    - O(N^2) Calaulate prefix sum array and check if two value of prefix sum equal then prefix sum exist
    - O(N)  calculate prefix sum and store in unordered map or set and (find() -> O(1) time) 


PS D:\GitHub\Algo++\HashTable\Implementation> ./a.exe
Enter size of array : 5
1 2 3 4 5
NO
PS D:\GitHub\Algo++\HashTable\Implementation> ./a.exe
Enter size of array : 6
6 -1 2 -1 2 -1
YES

Leetcode : 560

*/


#include<iostream>
#include<unordered_set>
using namespace std;


bool chekSubarray(int arr[],int n){
    unordered_set<int>s;

    int pre=0;
    for(int i=0;i<n;i++){
        pre+=arr[i];

        //Check if prefix sum exist previously then return true
        if(pre==0 or s.find(pre)!=s.end()){
            return true;
        }
        s.insert(pre);
    }

    return false;
}

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bool ans= chekSubarray(arr,n);
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}