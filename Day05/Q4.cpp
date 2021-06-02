
//Longest consecutive subsequence

#include<iostream>
#include<algorithm>
using namespace std;

// Subsequence : 
//Brute force : O(NlogN)
int longest_subsequence(int array[],int size){

    sort(array,array+size);
    for(int idx=0;idx<size;idx++){ cout<<array[idx]<<",";}
    int max_length=0;
    int curr_length=1;
    for(int idx=0;idx<size;idx++){
        if(array[idx]==(array[idx+1]-1)){
            curr_length+=1;
            max_length=max(curr_length,max_length);
        }
        else{
            curr_length=1;
        }
    }
    return max_length;

}

//Optimise code will require c++ stl container with O(N) extra space : hash map


int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int arrray[size];

    for(int idx=0;idx<size;idx++){
        cin>>arrray[idx];
    }

    cout<<"Longest consecutive Subsequence : "<<longest_subsequence(arrray,size)<<endl;

    return 0;

}