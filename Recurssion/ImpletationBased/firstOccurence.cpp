/*
    if arr will be sorted then we will apply Binary search otherwise,
    Linear search

*/

#include<iostream>
using namespace std;

int firstOccurence(int arr[],int n,int key){
    if(n==0){
        return -1;
    }
    //Base case
    if(arr[0]==key){
        return 0;
    }

    //rec case :
    int i=firstOccurence(arr+1,n-1,key);
    
    if(i==-1){
        return -1;
    }

    return i+1;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;

    cout<<firstOccurence(arr,n,key)<<endl;

    return 0;
}