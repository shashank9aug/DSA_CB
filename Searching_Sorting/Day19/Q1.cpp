// Find the first and last occurence index of given number in array

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  2 5
// Explanation: First occurrence of 5 is at index 2 and last
//              occurrence of 5 is at index 5.

// n=2 x=9
// arr[] = {6,9}
// output : 1 1

//Basically this question is Implementation of lower and upper bound in binary search

//T.C : O(logN)

#include<iostream>
#include<vector>
using namespace std;

int first_occurence(int arr[],int n,int x){
    int l=0,r=n-1;
    int mid,ans=-1;
    
    while(l<=r){
        mid=(l+r)/2;
        
        if(arr[mid]==x){
            ans=mid;
            r=mid-1;
        }
        else if(arr[mid]>x){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;   
}
int last_occurence(int arr[],int n,int x){
    int l=0,r=n-1;
    int mid,ans=-1;
    
    while(l<=r){
        mid=(l+r)/2;
        
        if(arr[mid]==x){
            ans=mid;
            l=mid+1;
        }
        else if(arr[mid]>x){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;   
}


vector<int> occurence(int arr[], int n , int x )
{
    vector<int> ans(2);
    ans[0]=first_occurence(arr,n,x);
    ans[1]=last_occurence(arr,n,x);
    return ans;
}


int main(){
    int n;
    cout<<"Enter the length of array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements of array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the value of x : ";
    cin>>x;
    vector<int>ans=occurence(arr,n,x);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }

    return 0;
}
