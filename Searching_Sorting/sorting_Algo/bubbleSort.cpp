/*


*/

#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    //N-1 larger elements to the end : 
    for(int itr=0;itr<n;itr++){
        //pairwise swapping in the unsorted part of array  :
        for(int j=0;j<(n-itr-1);j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

}

int main(){
    int n;
    cout<<"Enter no of array element : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubbleSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}