/*
    in given sorted array we have to find min difference element.
    i.e :  1, 3, 8, 10, 15, 18
        key=12
        find??

        we will apply normal binary search as usual 
        then we will notice : 
        -> if key present in array => min(key) == 0
            in left of key increasing difference and in right also increasing difference

          so : 
            we have to find both the min element from right and left 
            then compare their differnce to get min_difference element

        -> if key is not present => then  
            while(start<=end) => when condition become false then       
                start will point to right hand side of key
                and end will point to left hand side of key
              then we can find the min among them                 

*/


// #include<iostream>
// #include<cmath>
// #include<cstdlib>
// #include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int min_diff_element(int n,int arr[],int key){
    int start=0;
    int end=n-1;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==key){
            return arr[mid];
        }
        else if(arr[mid]<key){
            start=mid+1;
        }    
        else{
            end=mid-1;
        }
    }

    int min1= abs(arr[start]-key);
    int min2= abs(arr[end]-key);

    if(min1<min2){
        return arr[start];
    }
    else{
        return arr[end];
    }
}


int main(){
    int n;
    cout<<"Enter number of element in array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter array element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter value of key : ";
    cin>>key;

    cout<<"Min difference element in array : "<<min_diff_element(n,arr,key)<<endl;
    
    return 0;
}