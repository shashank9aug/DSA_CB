//  Minimise the maximum difference between heights [V.IMP]

//Question: GeeksforGeeks
// Given an array arr[] denoting heights of N towers and a positive integer K, you have 
// to modify the height of each tower either by increasing or decreasing them by K only  once.After modifying, height should be a non-negative integer. 
// Find out what could be the possible minimum difference of the height 
// of shortest and longest towers after you have modified each tower.


#include<iostream>
#include<climits>
using namespace std;

int modify_height(int array[],int size,int k){
    for(int idx=0;idx<size;idx++){
        if(array[idx]>k and (array[idx]-k)>0 ){
            array[idx]-=k;
        }
        else if(array[idx]<k and (array[idx]+k)>0){
            array[idx]+=k;
        }
    }
    int highest = INT_MIN;
    int lowest = INT_MAX;
    for(int idx=0;idx<size;idx++){
        lowest=min(array[idx],lowest);
        highest=max(array[idx],highest);
    } 

    return (highest-lowest);
}

int main(){
    int size;
    cin>>size;

    int array[size];
    
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }
    cout<<"Enter the value by which height modify : ";
    int k;
    cin>>k;

    int ans=modify_height(array,size,k);
    cout<<"Difference Between Tallest and smallest height : "<<ans<<endl;

    return 0;
}