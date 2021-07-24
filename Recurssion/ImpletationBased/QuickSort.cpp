/*
    Quick sort : Inplace algorithm.
    -find pivot element.
    - Partition the array about pivot element  > and < 
    - Recurssively sort the each part of the array.

*/

#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    //Inplace algo : doesnot take extra space 
    int i=s-1;
    // int j=s;
    //pivot element:
    int pivot=arr[e];
    for(int j=s;j<=(e-1);j++){
        if(arr[j]<=pivot){
            i=i+1;
            swap(arr[i],arr[j]);
        }
        //expand the large region
        // j=j+1;
    }

    //place the pivot at its correct position :
    swap(arr[i+1],arr[e]);
    
    //return position of pivot element :
    return i+1;
}

void quickSort(int arr[],int start,int end){
    //Base case :
    if(start>=end){
        return;
    }

    //Rec case:
    int p=partition(arr,start,end);

    //left part :
    quickSort(arr,start,p-1);

    //right part : 
    quickSort(arr,p+1,end);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }

    return 0;
}