/*
    Given List of numbers :  5,1,2,1,3,2,5,7

    we have to extract output as unique numbers. : 3,7

$ ./a.exe
Enter no of element : 6
1 2 3 5 1 2
3, 5

*/


#include<iostream>
using namespace std;

void uniqueNo(int arr[],int n){
    //Xor of each each element of array
    int Xor=0;
    for(int i=0;i<n;i++){
        Xor = Xor^arr[i];
    }

    int temp=Xor;
    int pos=0;
    while((temp&1)!=1){
        pos++;
        temp=temp>>1;
    }

    //find bit in xor is at position pos
    int mask=(1<<pos);
    int a=0;
    int b=0;
    for(int i=0;i<n;i++){
        if((arr[i]&mask)>0){
            a=a^arr[i];
        }
    }
    b=Xor^a;

    cout<<min(b,a)<<", "<<max(a,b)<<endl;
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