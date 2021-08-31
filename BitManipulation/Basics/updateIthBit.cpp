#include<iostream>
using namespace std;


void updateBit(int &n,int ithBit,int value){
    int mask=~(1<<ithBit);
    int clear_bit=n&mask;
    n=clear_bit or (value<<ithBit);
}

int main(){
    int n;
    cin>>n;

    int ithBit;
    cout<<"Enter ithBit : ";
    cin>>ithBit;

    int value;
    cout<<"Enter value : ";
    cin>>value;

    updateBit(n,ithBit,value);

    cout<<n;

    return 0;
}