// Given an array of n positive integers and a number k.
// Find the minimum number of swaps required to bring all the numbers less than or equal to k together


// Input : arr[ ] = {2, 7, 9, 5, 8, 7, 4} 
// K = 6 
// Output :  2 

#include<iostream>
#include<climits>
using namespace std;

//Brute force :
/*int min_swap(int array[],int size,int key){
    int count=0;
    // int start=0;
    int idx=0;
    while(idx<size){
        // int start=0;
        while(array[idx]<=key && idx<size){
            idx++;
        }
        int end=size-1;
        while(array[end]>=key && end>0){
            end--;
        }

        if(array[idx]>key && array[end]<key){
           swap(array[idx],array[end]); 
            count++;
        }

    }
    //test
    // for(int idx=0;idx<size;idx++){
    //     cout<<array[idx]<<","<<" ";
    // }
    return count;
}*/

//Sliding window method : O(N)

int min_swap(int array[],int size,int k){
    int good=0;
    for(int i=0;i<size;i++){
        if(array[i]<=k){
            good++;
        }
    }

    int ans=INT_MAX;
    int bad=0;

    for(int i=0;i<good;i++){
        if(array[i]>k) bad++;
    }

    int i=0;
    int j=good-1;

    while(j<size){
        ans=min(ans,bad);
        j++;
        if(array[i]>k) bad--;
        if(j<size && array[j]>k) bad++;
        i++;        
    }

    return ans;  
}


int main(){

    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int array[size];
    cout<<"Enter the array elements : ";
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    int key;
    cout<<"Key value : ";
    cin>>key;
    cout<<"Minimum no of swaps required : "<<min_swap(array,size,key)<<endl;

    return 0;
}