/*
    -> we have to check Array is sorted or not recurssively : 

    -> two Approach : 
        i) divide the array in two sub array of size n/2 + n/2 and check them separetly
        ii) divide arr[0] and arr[n-1] part. => f(n) =[(a[0] < a[1] ) and f(n-1) is sorted]       
            else,
                return false;

*/

#include<iostream>
using namespace std;

bool isSorted(int arr[],int n){
    //Base case : 
    if(n==0 or n==1){
        return true;
    }

    //rec case :
    if(arr[0] < arr[1] and isSorted(arr+1,n-1)){
        return true;
    }

    return false;
}


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<isSorted(arr,n)<<endl;
}