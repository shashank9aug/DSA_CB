/*
Important : 

    Sort the array in wave form : 

Enter length of array : 5 
1 2 3 4 5
2 1 4 3 5

*/


#include<iostream>
#include<vector>
using namespace std;


void waveSort(int arr[],int n){
    //iterate over array : 
    for(int i=0;i<n;i+=2){
        //prev element : 
        if(i!=0 and arr[i]<arr[i-1]){
            swap(arr[i],arr[i-1]);
        }

        //next element 
        if(i!=(n-1) and arr[i]<arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
}

int main(){
    int n;
    cout<<"Enter length of array : ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    waveSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    

    return 0;
}