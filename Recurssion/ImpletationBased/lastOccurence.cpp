/*
    if arr will be sorted then we will apply Binary search otherwise,
    Linear search : we will traverse from back and the first occurence we will return 

    But ,
    we will traverse from front as we are learning recurssion now
    we are going into depth of recurssion untill n==0 
    then,
    we will check accordingly.
    and return.
*/

#include<iostream>
using namespace std;

int lastOccurence(int arr[],int n,int key){
    //Base case : 
    if(n==0){
        return -1;
    }

    //rec case : 
    int i=lastOccurence(arr+1,n-1,key);

    if(i==-1){
        if(arr[0]==key){
            return 0;
        }
        else{
            return -1;
        }
    }

    //otherwise 
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

    cout<<lastOccurence(arr,n,key)<<endl;

    return 0;
}