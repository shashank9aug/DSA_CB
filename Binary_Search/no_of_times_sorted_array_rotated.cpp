/*
    n = 8
    arr is unrotated and sorted
    arr[8]={2,5,6,8,11,12,15,18}
    min_ele=arr[0]=2
    no of times rotated=0

    arr is rotated as well as unsorted 
    arr[8]={11,12,15,18,2,5,6,8}
    min_ele=arr[4]=2
    no_of_times_rotated=4

    idx of min_element = no of times array is rotated

*/

#include<iostream>
#include<algorithm>
using namespace std;

int no_of_times_rotated(int n,int arr[]){
    int start=0;
    int end=n-1;
    int pivot=-1;

    //Base condition :if array is not rotated
    if(arr[0]<arr[n-1]){
        return 0;
    }

    while(start<=end){
        int mid=start+(end-start)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;

        
        if(arr[start]<=arr[end]){
            return start;
        }

        //check arr[mid] is between both smaller element 
        if((arr[mid]<=arr[next])and (arr[mid]<=arr[prev])){
            pivot=mid;
            break;
        }
        //go for unsorted part
        if(arr[start]<=arr[mid]){
            start=mid+1;        
        }
        else if(arr[mid]<=arr[end]){
            end=mid-1;
        }
    }
    return pivot;
}

int main(){
    int n;
    cout<<"Eneter the number of elements in array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements  : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int key;
    // cout<<"Eneter the key need to search : ";
    // cin>>key;
    
    cout<<no_of_times_rotated(n,arr)<<endl;

    return 0;
}
