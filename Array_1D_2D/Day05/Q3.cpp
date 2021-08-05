
//max product sub array

// Input:
// N = 5
// Arr[] = {6, -3, -10, 0, 2}
// Output: 180
// Explanation: Subarray with maximum product
// is 6, -3, -10 which gives product as 180.



#include<iostream>
using namespace std;

//This code is not handeling the case when two numbers are negative and their product will be +ve

// int max_product_subarray(int array[],int size){

//     int max_product=INT32_MIN;
//     int curr_product=1;

//     for(int idx=0;idx<size;idx++){
//         curr_product*=array[idx];

//         if(curr_product<0){
//             curr_product=1;
//         }

//         if(curr_product>max_product){
//             max_product=curr_product;
//         }
//     }
//     return max_product;
// }


int max_product_subarray(int array[],int size){

    int max_produce=1,min_product=1,ans=1;

    for(int idx=0;idx<size;idx++){
        int curr=array[idx];

        //elements are negative
        if(curr<0){
            swap(max_produce,min_product);
        }   

        max_produce=max(curr,curr*max_produce);
        min_product=min(curr,curr*min_product);

        ans = max(ans,max_produce);

    }    

    return ans;
}





int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<"Maximum product of subarray : "<<max_product_subarray(array,size)<<endl;

    return 0;
}