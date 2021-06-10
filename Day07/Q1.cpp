
// A[] = {1, 4, 45, 6, 0, 19}
// x  =  51
// Output: 3
// Explanation:
// Minimum length subarray is 
// {4, 45, 6}


#include<iostream>
using namespace std;

//Brute force approach : O(N^2) : two nested loop traversal.
/*
int min_length_subarray(int array[],int size,int sum){
    int curr_sum=0;
    int length_count=size+1;
    for(int idx=0;idx<size;idx++){
        //starting point of subarray 
        curr_sum=array[idx];
        //MAy be first element will be greater than sum
        if(idx==0 && curr_sum>sum){
            return 1;
        }

        for(int jdx=idx+1;jdx<size;jdx++){
            curr_sum+=array[jdx];
            //(jdx-idx+1) is current length of subarray
            if(curr_sum>sum && (jdx-idx+1)<length_count){
                length_count=(jdx-idx+1);
            }
        }      
    }
  return length_count;
}
*/

//Optimised code : O(N)

int min_length_subarray(int array[],int size,int sum){
    int curr_Sum=0,length_count=size+1;
    int idx=0,jdx=0;
    
    while(jdx<size){
        //adding subarray element while subarray sum less than given sum
        while(curr_Sum<=sum && jdx<size){
            curr_Sum+=array[jdx];
            jdx++;
        }

        while(curr_Sum>sum && idx<size){
            if((jdx-idx)<length_count){
                length_count=(jdx-idx);
            }

            curr_Sum-=array[idx];
            idx++;
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