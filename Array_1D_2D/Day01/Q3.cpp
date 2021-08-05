#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//I will another method to solve this problem soon

int main(){
    int idx;
    int size;
    cin>>size;

    int array[size];

    for(idx=0;idx<size;idx++){
        cin>>array[idx];
    }
    
    int position;
    cout<<"Enter the kth position: ";
    cin>>position;

    sort(array,array+size);

    cout<<"Kth max element "<<array[size-position]<<endl;
    cout<<"Kth min element "<<array[position-1]<<endl;

    return 0;
}