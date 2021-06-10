
// Input: 
// n = 5
// A[] = {1, 2, 3, 3, 4}
// [a, b] = [1, 2]
// Output: 1
// Explanation: One possible arrangement is:
// {1, 2, 3, 3, 4}. If you return a valid
// arrangement, output will be 1.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(NlogN)
// int array_partition(int array[],int size,int a,int b){
//     if(array[0]==a && array[size-1]==b){
//         return 1;
//     }    



// }

//O(N)

void array_partition(int array[],int size,int a,int b){
    int left=0, right=size-1;

    for(int idx=0;idx<=right;idx++){
        if(array[idx]<a){
            swap(array[idx],array[left]);
            left++;
        }
        else if(array[idx]>b){
            swap(array[idx],array[right]);
            right--;
            idx--;
        }
    }

}


int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int array[size];
    cout<<"Enter the array elements : ";
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    int a,b;
    cout<<"Ranges : ";
    cin>>a>>b;

    // sort(array,array+size);
    cout<<"Partitioning array with given range";
    array_partition(array,size,a,b);

    for(int idx=0;idx<size;idx++){
        cout<<array[idx]<<",";
    }

    return 0;
}
