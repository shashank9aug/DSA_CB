/*

$ ./a.exe
Enter no : 31
ithBit : 1
jthBit : 3
Ans : 17

*/

#include<iostream>
using namespace std;

int main(){
    int no;
    cout<<"Enter no : ";
    cin>>no;

    int ithBit;
    cout<<"ithBit : ";
    cin>>ithBit;

    int jthBit;
    cout<<"jthBit : ";
    cin>>jthBit;

    int ones=(~0);
    int a=ones<<(jthBit+1);
    int b=((1<<ithBit)-1);
    int mask=(a | b);
    
    int ans=(no&mask);

    cout<<"Ans : "<<ans<<endl;

    return 0;
}