/*
    we have to use recussive function for Binary search : 

*/


#include<iostream>
using namespace std;


bool recBinarySearch(int arr[],int n,int key,int start,int end){
    
    int mid=start+(end-start)/2;
    //Base case : 
    if(arr[mid]==key){
        return true;
    }

    //rec case : 
    if(arr[mid]<key){
        recBinarySearch(arr,n,key,mid+1,end);
    }
    else if(arr[mid]>key){
        recBinarySearch(arr,n,key,start,mid-1);
    }
    
    return false;
}


int main(){
    int n;
    cout<<"Enter length of array : ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter key element : ";
    cin>>key;

    int start=arr[0];
    int end=arr[n-1];
    cout<<recBinarySearch(arr,n,key,start,end)<<endl;

    return 0;
}