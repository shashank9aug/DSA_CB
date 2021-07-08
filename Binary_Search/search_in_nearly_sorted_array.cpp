/*
 ith index => element can be at i+1 or i-1;

    eg: i/p      :     5,10,30,20,40
        i/p (sorted) : 5,10,20,30,40
        key : 20 if we search in nearly sorted array it can be at (i+1)or (i) or (i-1)
        o/p : 3      
        
*/

#include<iostream>
#include<algorithm>
using namespace std;


int search_nearly_sorted_array(int n,int arr[],int key){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;

        if(key==arr[mid]){
            return mid;
        }

        if(mid<=start and arr[mid-1]==key){
            return mid-1;
        }

        if(mid+1<=end and arr[mid+1]==key){
            return mid+1;
        }
    }

    return -1;
}


int main(){
    int n;
    cout<<"Eneter the number of elements in array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements  : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Eneter the key need to search : ";
    cin>>key;
    
    cout<<search_nearly_sorted_array(n,arr,key)<<endl;

    return 0;
}