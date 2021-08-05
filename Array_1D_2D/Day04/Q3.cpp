
// Input  :  arr[] = {1, 5, 7, -1}, 
//           sum = 6
// Output :  2
// Pairs with sum 6 are (1, 5) and (7, -1)




#include<iostream>
using namespace std;

//Brute force approach : O(n^2)
int sum_equal_given_num(int array[],int size,int k){
    int count=0;
    for(int idx=0;idx<size;idx++){
        int f_item=array[idx];
        for(int jdx=idx+1;jdx<size;jdx++){
            if(f_item+array[jdx]==k){
                count++;                    
            }
        }    
    }
    return count;
}

//Best case aproach : O(n)  : through c++ Stl
// int sum_equal_given_num(int array[],int size,int k){
//     int count=0;
//     for(int idx=0;idx<size;idx++){

//     }
// }


int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }
    int k;
    cin>>k;
   

    cout<<sum_equal_given_num(array,size,k)<<endl;

    return 0;
    
}