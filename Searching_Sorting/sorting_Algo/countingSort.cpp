/*
    sorting array technique : when we have data from certain range.
    i.e : when the numbers range will be small we will apply counting Sort.

    T.C : O(n + range)
    if(range~small) => then O(n) time.

$ ./a.exe
Enter number of elements in array :  5
1 34 8 3 2
1 2 3 8 34 

*/

#include<iostream>
using namespace std;

void countingSort(int arr[],int n){
    int largest=-1;

    for(int i=0;i<n;i++){
        largest=max(largest,arr[i]);
    }

    int *temp=new int[largest+1]{0};

    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    int j=0;
    for(int i=1;i<=largest;i++){
        while(temp[i]>0){
            arr[j]=i;
            temp[i]--;
            j++;
        }
    }

}



int main(){
    int n;
    cout<<"Enter number of elements in array :  ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    countingSort(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}