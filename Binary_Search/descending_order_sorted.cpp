// Array is given in Descending order 

//find the index of given element position otherwise if not present return -1;


#include<iostream>
#include<algorithm>
using namespace std;

//for ascending order array 

int binary_search(int n,int arr[],int key){
    int start=0;
    int end=n-1;
    
    while(start<end){
      int mid=start + (end-start)/2;
      if(arr[mid]==key){
          return mid;
      }
      else if(arr[mid]>key){
          start=mid+1;
      }
      else{
          end=mid-1;
      }
    }

   return -1; 
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
    cout<<"Eneter the key need to search : ";
    cin>>key;
    cout<<binary_search(n,arr,key)<<endl;

    return 0;
}