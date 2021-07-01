//searching in an array where adjacent element differ by "at most" k 
 
//find the index of x. if it's freqency > 1 then return 1st position of idx x  

/*
    input : N=5
        {4,5,6,7,6}
        x=6
    Output : 2

*/


// #include<iostream>
// #include<cstdlib>
// #include<algorithm>
#include<bits/stdc++.h>
using namespace std;

//array is not sorted so we will apply linear search

//Approach : Linear search O(n) and O(1)
int search_diff_m1(int n,int arr[],int k,int x){
    int occurrence=0;
    int idx=0;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            idx=i;
            break;
        }
    }
    return idx;
}   

//Optimised approach : no of steps will less

int search_diff_m2(int n,int arr[],int k,int x){
    int i=0;
    while(i<n){
        if(arr[i]==x){
            return i;
        }

        i=i+max(1,abs(arr[i]-x)/k);
    }
    return -1;
}


int main(){
    int n;
    cout<<"Enter the length of array : ";
    cin>>n;

    int k;
    cout<<"Enter the diff value (K ) : ";
    cin>>k;

    int x;
    cout<<"Enter the value need to search : ";
    cin>>x;

    int arr[n];
    cout<<"Enter the array element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // cout<<"Index of x : "<<search_diff_m1(n,arr,k,x)<<endl;
    cout<<"Index of x : "<<search_diff_m2(n,arr,k,x)<<endl;

    return 0;
}