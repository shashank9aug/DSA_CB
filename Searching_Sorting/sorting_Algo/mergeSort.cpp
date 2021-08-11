/*
$ ./a.exe
5
3 4 2 5 1
1 2 3 4 5 
*/

/*
    Space and Time Analysis : 

    Time : K = finding mid point 
        2T(n/2) = for sorting each parts about mid point
        kn = Merging the array 

        T(n)  = k + 2T(n/2) + kn

        T(n) = k'n + 2T(n/2)

        2T(n/2) = 2k'(n/2) + 4T(n/4);
        4T(n/4) = 4K'(n/4) + 4*2T(n/8);
        ......
        nT(1) = nk' + 0;
     ---------------------------------------------   
        T(n) = sum(k'n)i=0 to i=logn  = k'nlogn

        T(n) = n(logn) 

*/


#include<iostream>
using namespace std;

void mergeArr(int arr[],int start,int end){
    int mid=start+(end-start)/2;

    int i=start,j=mid+1,k=start;

    int temp[100];

    while(i<=mid and j<=end){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    //if any no of elements left in array after comparision
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }

    //copy all elements to orignal array : 
    for(int i=start;i<=end;i++){
        arr[i]=temp[i];
    }
}


void mergeSort(int arr[],int start,int end){
    //Base case : 
    if(start>=end){
        return;
    }

    //mid :
    int mid=start+(end-start)/2;

    //recurssively divide the array : about mid point 
    mergeSort(arr,start,mid);  
    mergeSort(arr,mid+1,end);

    //Merge the two parts : 
    mergeArr(arr,start,end);  

}


int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}