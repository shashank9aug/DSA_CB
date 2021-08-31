/*
    We are given an array containing n numbers. and each number present thrice except the 
    only unique number only.
    -> 3N+1 => pattern => every no occur three times and 1 no will occur 1 time
    follow a algo : 


$ ./a.exe
Enter no of element : 7
1 1 1 2 2 2 3
3

$ ./a.exe
Enter no of element : 10
1 2 1 2 1 2 3 3 3 5
5

*/

#include<iostream>
using namespace std;

void uniqueNo(int arr[],int n){
    //count array of 64 size => array of fixed size takes O(1) space.
    int count[64]={0};

    for(int i=0;i<n;i++){
        //update count array by extracting bits : 
        int j=0;
        while(arr[i]>0){
            int last_bit=(arr[i]&1);
            count[j]+=last_bit;
            j++;
            arr[i]=arr[i]>>1;
        }
    }

    //iterate over the array and form the ans by converting 0s and 1s into a number.
    int pow=1;
    int ans=0;
    for(int i=0;i<64;i++){
        //%3 because we have every arr[i] 3 times
        count[i]%=3;
        ans+=(count[i]*pow);
        pow=pow<<1;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int n;
    cout<<"Enter no of element : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    uniqueNo(arr,n);

    return 0;
}