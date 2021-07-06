//extension of no_of_times_array_rotated problem : 

#include<iostream>
#include<algorithm>
using namespace std;

int no_times_array_rotated(int arr[],int n){
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

        
        // if(arr[start]<arr[end]){
        //     return start;
        // }

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

int binarySearch(int arr[],int n,int start,int end,int key){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[start]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
    }
    return -1;
}

int search_in_rotated_array(int n,int arr[],int key){
    int index=no_times_array_rotated(arr,n);

    int ans1=binarySearch(arr,n,0,index-1,key);
    int ans2=binarySearch(arr,index,index,(n-1),key);
    
    if(ans1>=0){
        return ans1;
    }
    if(ans2>=0){
        return ans2;
    }
    else{
        return -1;
    }
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
    int key;
    cout<<"Enter the element need to search : ";
    cin>>key;

    cout<<search_in_rotated_array(n,arr,key)<<endl;
    
    return 0;
}
