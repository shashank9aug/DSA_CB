// 1-D 

// Input:
// N = 8
// arr[] = {7 2 8 9 1 3 6 5}
// Output: 16
// Explanation: Maximum size of the histogram 
// will be 8  and there will be 2 consecutive 
// histogram. And hence the area of the 
// histogram will be 8x2 = 16.

#include<iostream>
using namespace std;

int max_area_histogram(int array[],int size){
    
}

int main(){
    int size;
    cout<<"Size of array : ";
    
    int array[size];
    cout<<"Enter the array items : ";
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<"Maximum area of histogram : "<<max_area_histogram(array,size)<<endl;

    return 0;
}