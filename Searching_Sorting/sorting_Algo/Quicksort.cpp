/*
    -Inplace Algorithm
    -D&C
    -O(nlogn) in average case
    -N^2 wrost case.

    # Apparoch : 
    Choose pivot element
    divide arr  <=pivot  and >=pivot 
    Recurssively sort the both the part before pivot and after pivot
*/

#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
    //Inplace : (can't take extra space)
    int i=start-1;
    int j=start;
    int pivot=arr[end];

    for(;j<=end-1;){
        if(arr[j]<=pivot){
            //merge the smaller element in the region-1
            i=i+1;
            swap(arr[i],arr[j]);
        }
        //expand the larger region : 
        j=j+1;
    }
    //place the pivot element in the correct index : 
    swap(arr[i+1],arr[end]);
    return i+1;
}

void QuickSort(int arr[],int start,int end){
    //Base case :
    if(start>=end){
        return;
    }

    //Hypothesis : 
    int pivot= partition(arr,start,end);

    //Left part : 
    QuickSort(arr,start,pivot-1);

    //right part : 
    QuickSort(arr,pivot+1,end);

}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    QuickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}