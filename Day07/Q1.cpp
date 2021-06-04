
// A[] = {1, 4, 45, 6, 0, 19}
// x  =  51
// Output: 3
// Explanation:
// Minimum length subarray is 
// {4, 45, 6}


#include<iostream>
using namespace std;

int min_length_subarray(int array[],int size,int sum){
    int curr_sum=0;
    int length_count=0;
    for(int idx=0;idx<size;idx++){
        curr_sum+=array[idx];
        //MAy be first element will be greater than sum
        if(idx==0 && curr_sum>sum){
            return 1;
        }
        if(curr_sum>sum){
            length_count=idx+1;
        }
    }
  return length_count;
}

int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    int sum;
    cout<<"Enter the sum : ";
    cin>>sum;

    cout<<"Minimum length subarray : "<<min_length_subarray(array,size,sum)<<endl;

    return 0;
}