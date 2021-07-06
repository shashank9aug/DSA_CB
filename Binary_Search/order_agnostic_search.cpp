//order agnostic means it's not given that given array is ascending order or descending order 
//sorted or not

//we have to identify the order of sorted array : 

#include<iostream>
using namespace std;

int a_b_s(int n,int arr[],int key){
    int start=0;
    int end=n-1;

    while(start<end){
        int mid=start+ (end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}


int d_b_s(int n,int arr[],int key){
    int start=0;
    int end=n-1;

    while(start<end){
        int mid=start+ (end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the no of array element : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key need to search : ";
    cin>>key;

    if(n==1){
        return 0;
    }

    //ascending order check
    if(arr[0]<arr[1]){
        cout<<"Ascending order binary search : "<<a_b_s(n,arr,key)<<endl;
    }
    else if(arr[0]>arr[1]){
        cout<<"Descending order binary search : "<<d_b_s(n,arr,key)<<endl;
    }
    return 0;
}