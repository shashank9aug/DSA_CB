// $ ./a.exe
// Enter no : 5
// Enter ith bit : 2
// 2 th bit of 5 : 1

#include<iostream>
using namespace std;

int main(){
    int no;
    cout<<"Enter no : ";
    cin>>no;

    int ithBit;
    cout<<"Enter ith bit : ";
    cin>>ithBit;

    // (1<<2) = 100 and if(n&(1<<i))>0 => 1 otherwise 0 bit 
    int mask=(1<<ithBit);

    int bit=(no&mask)>0 ? 1:0;

    cout<<ithBit<<" th bit of "<<no<<" : "<<bit<<endl;

    return 0;
}