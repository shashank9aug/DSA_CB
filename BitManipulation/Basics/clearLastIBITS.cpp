/*
KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Love_450/BitManipulation (master)
$ ./a.exe
n : 5
ithBit : 1
Mask : -2
4
    5 -> 101 and i=1  => 100 fliped 1st bit only so ans=4
KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Love_450/BitManipulation (master)
$ ./a.exe
n : 4
ithBit : 2
Mask : -4
4
    5 -> 101 and i=2  => 100 fliped 2nd bit only so ans=4
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"n : ";
    cin>>n;

    int ithBit;
    cout<<"ithBit : ";
    cin>>ithBit;

    int mask=(-1<<ithBit);
    cout<<"Mask : "<<mask<<endl;

    cout<< (n&mask)<<endl;

    return 0;
}