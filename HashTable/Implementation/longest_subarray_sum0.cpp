/*
    ps : We have array in which we have to find longest subarray whose sum==0 and return its length

     
PS D:\GitHub\Algo++\HashTable\Implementation> ./a.exe
Enter size of array : 5
1 -1 0 0 5
4
PS D:\GitHub\Algo++\HashTable\Implementation> ./a.exe
Enter size of array : 7
0 -1 1 2 1 5 -5
3

*/

#include<iostream>
#include<unordered_map>
using namespace std;


int longestSubarraySum0(int arr[],int n){
    unordered_map<int,int>mp;

    int len=0;
    int pre=0;
    for(int i=0;i<n;i++){
        pre+=arr[i];

        if(pre==0){
            len=max(len,i+1);
        }

        //if prefix sum is repeated :
        if(mp.find(pre)!=mp.end()){
            len=max(len,i-mp[pre]);
        }
        else{
            //store the first occurrence :
            mp[pre]=i;
        }
    }

    return len;
}

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<longestSubarraySum0(arr,n)<<endl;

    return 0;
}