// Input:
// 5
// 4 2 -3 1 6

// Output: 
// Yes

// Explanation: 
// 2, -3, 1 is the subarray 
// with sum 0.

#include<iostream>
#include<unordered_map>
using namespace std;

//Brute force : O(n^2)
// bool subarray_with_sum0(int array[],int size){
//     bool flag;
//     for(int idx=0;idx<size;idx++){
//         int sum=0;
//         for(int jdx=idx;jdx<size;jdx++){
//             sum+=array[jdx];
//             if(sum==0){
//                 flag=true;
//                 break;
//             }
//         }
//     }
//     if(flag){
//         return true;
//     }
//     else{
//         return false;
//     }
// }



// bool subarray_with_sum0(int array[],int size){
//     int curr_sum=0;
//     bool flag;
//     for(int idx=0;idx<size;idx++){
//         curr_sum+=array[idx];
//         if(curr_sum=0){
//             flag=true;
//             break;
//         }
//         if(curr_sum<0){
//             curr_sum=0;
//         }
//     }
//     if(flag){
//         return true;
//     }
//     else{
//         return false;
//     }
// }


//optimise approach will use c++ stl container : O(n)
/*
    there are three cases :  either any element of array is zero
                             prifix sum is repeated (which can be found through map)
                             or subarray sum is zero itself    
*/
bool subarray_with_sum0(int array[],int size){
    int sum=0;
    unordered_map<int,int>m;
    bool flag;
    for(int idx=0;idx<size;idx++){
        sum+=array[idx];
        if(m[sum] or array[idx]==0 or sum==0){
            flag=1;
            break;
        }
        else{
            //update prefix sum
            m[sum]=1;
        }
    }
    if(flag==1){
        return true;
    }
    else{
        return false;
    }
}



int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<subarray_with_sum0(array,size)<<endl;

    return 0;
}