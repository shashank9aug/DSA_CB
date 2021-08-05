// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 
// has three inversions (2, 1), (4, 1), (4, 3).


#include<iostream>
#include<algorithm>
using namespace std;

//Brute force
int count_inversion(int array[],int size){
    int count=0;
    for(int idx=0;idx<(size-1);idx++){
        for(int jdx=idx+1;jdx<size;jdx++){
            if (array[idx] > array[jdx]) 
                count++; 
        }
    }
    return count;
}

//Best case solution : Using merge sort



int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<count_inversion(array,size)<<endl;

    return 0;
    
}