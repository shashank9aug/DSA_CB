/*
    //Replace Bits in n by m :
    -> you are given two 32-bit integer , n and m, and two bit position i and j.
    write a method to set all the bits between i and j in n equal to m  
    i.e : m becomes a substring of n located at i and j

e.g : 
M = 10000000000
N = 10101
i = 2 and j = 6 
output : 10001010100


$ ./a.exe
Enter no : 15
ithBit : 1
jthBit : 3
Enter m : 2
5


*/

#include<iostream>
using namespace std;

int clear_bit_range(int no,int ithBit,int jthBit){
    int ones=(~0);
    int a=ones<<(jthBit+1);
    int b=((1<<ithBit)-1);
    int mask=(a | b);
    
    int ans=(no&mask);

    return ans;
}

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

    int ans=clear_bit_range(no,ithBit,jthBit);

    int m;
    cout<<"Enter m : ";
    cin>>m;
    

    int mask=(m<<ithBit);

    cout<<(ans | mask)<<endl;

    return 0;
}