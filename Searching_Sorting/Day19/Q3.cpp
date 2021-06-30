// we have to rotate array by given pivot index then search element in array

//we have to rotate sorted(ascending order) array
//then apply binary search to search target position 
//return index of target item

#include<iostream>
#include<vector>
using namespace std;

void rotate_array(int arr[],int pivot){
    
}

int search_element(int arr[],int target){
    
}


int main(){
    int n;
    cout<<"Enter the no of elements in array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter values inside array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int pivot;
    cout<<"Enter pivot position : ";
    cin>>pivot;

    rotate_array(arr,pivot);

    int target;
    cout<<"Enter element need to search : ";
    cin>>target;

    int ans=search_element(arr,target);

    cout<<ans;

    return 0;
}