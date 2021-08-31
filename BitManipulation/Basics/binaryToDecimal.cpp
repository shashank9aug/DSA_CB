#include<iostream>
using namespace std;

//M : 1 
// $ ./a.exe
// Enter no : 10
// 0101
void decimalToBinary(int no){
    while(no>0){
        int last_bit=(no&1);
        cout<<last_bit;
        no=no>>1;
    }        
}

int decimalToBinaryM2(int no){
    int ans=0;
    int pow=1;

    while(no>0){
        int last_bit=(no&1);
        ans+=last_bit*pow;

        pow=pow*10;
        no=no>>1;
    }
    return ans;
}

int main(){

    int no;
    cout<<"Enter no : ";
    cin>>no;

    decimalToBinary(no);
    cout<<endl;

    cout<<"M2 : "<<decimalToBinaryM2(no)<<endl;

    return 0;
}    