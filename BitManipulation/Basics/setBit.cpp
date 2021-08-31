#include<iostream>
using namespace std;

int main(){
    int no;
    cout<<"Enter no : ";
    cin>>no;

    int ithBit;
    cout<<"ith bit : ";
    cin>>ithBit;

    int mask=(1<<ithBit);
    no=no | mask;

    cout<<no;

    return 0;
}