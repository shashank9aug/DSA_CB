#include<iostream>
#include<climits>
using namespace std;

int maxSubarray(int arr[],int n,int k){
    //Initially window size : 
    int start=0;
    int end=0;

    int sum=0;
    int mx=INT_MIN;
    while(end<n){
        sum+=arr[end];
        if((end-start+1) < k){
            end++;
        }
        else if((end-start+1)==k){
            mx=max(mx,sum);
            sum=sum-arr[start];
            start++;
            end++;
        }
    }
    return mx;
}

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   

    int k;
    cout<<"Enter window size : ";
    cin>>k;

    cout<<"Max subarray : "<<maxSubarray(arr,n,k)<<endl;

    return 0;
}