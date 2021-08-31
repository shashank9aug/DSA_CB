/*
$ ./a.exe
abc

a
b
ab
c
ac
bc
abc

*/


#include<iostream>
#include<cstring>
using namespace std;


void filterChars(char a[],int n){
    int j=0;

    while(n>0){
        int last_bit=(n&1);
        if(last_bit==1){
            cout<<a[j];
        }
        j++;
        n=n>>1;
    }
    cout<<endl;
}


void printSubsets(char a[]){
    int n=strlen(a);
    cout<<(1<<n)<<endl;
    for(int i=0;i<(1<<n);i++){
        cout<<i<<", ";
        filterChars(a,i);
    }

    return; 
}


int main(){
    char a[100];

    cin>>a;

    printSubsets(a);
    return 0;
}