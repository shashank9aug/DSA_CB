//Max sum subarray

#include<iostream>
#include<climits>
using namespace std;

//Brute force approach  :  O(n^2)

// int max_sum_subarray(int array[],int size){
//     int max_sum=INT_MIN;
//     for(int idx=0;idx<size;idx++){
//         int sum=0;
//         for(int jdx=idx+1;jdx<size;jdx++){
//             sum+=array[jdx];
//             if(max_sum<sum){
//                 max_sum=sum;
//             }
//         }
//     }
//     return max_sum;
// }

//Kadane's algo : O(n)

int max_sum_subarray(int array[],int size){
    int max_sum=0;
    int curr_sum=0;
    for(int idx=0;idx<size;idx++){
        curr_sum+=array[idx];
        if(max_sum<curr_sum){
            max_sum=curr_sum;
        }
        if(curr_sum<0){
            curr_sum=0;
        }
    }
    return max_sum;
}

//What will be the max sum subarray when all the elements of array is negative


int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<"Maximum sum of subarray : "<<max_sum_subarray(array,size)<<endl;

    return 0;

}