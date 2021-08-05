// largest sum contiguous subarray

#include<iostream>
#include<climits>
using namespace std;

int largest_contiguous_subarray(int array[],int size){
    int largest_sum=INT_MIN;
    int sum=0;
    for(int idx=0;idx<size;idx++){
        sum += array[idx];
        if(sum<0)
        {
            sum=0;
        }
        largest_sum=max(largest_sum,sum);
    }
    return largest_sum;
}

int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<"Sum of the largest contiguous subarray: ";
    
    cout<<largest_contiguous_subarray(array,size)<<endl;

    return 0;
}

// 5
// 1 2 3 4 5
// 15

// 8
// -2 -3 4 -1 -2 1 5 -3
// Sum of the largest contiguous subarray: 7