//Minimum no of jump to reach size 
// i.e. :end of the array

//Question:
// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element. 

#include<iostream>
using namespace std;

// int reach_end(int array[],int size){
//     int no_of_step=0;
//     int count_step=0;
//     int idx=0;
//     // for(int idx=0;no_of_step<=size;idx++){
//     while(size>no_of_step){    
//         // if(array[idx]>0 and size>no_of_step){
//         if(array[idx]>0){ 
//             no_of_step+=array[idx];
//             count_step++;
//         }
//         idx++;
//     }

//     return count_step;
// }


int reach_end(int array[],int size){
    if(size==1){
        return 0;
    }
    int count=0;
    int j=0;
    while(j<size){
        j+=array[j];
        count++;
        cout<<"value of J: "<<j<<endl;
    }
    return count;
}


int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }
    int ans = reach_end(array,size);
    cout<<"Minimum no of Jump : "<<ans<<endl;

    return 0;

}