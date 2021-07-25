/*
    count binary strings of length of N which have no consecutive ones : 

    Input:  N = 2
    Output: 3
    The 3 strings are 00, 01, 10

    Input: N = 3
    Output: 5
    The 5 strings are 000, 001, 010, 100, 101

*/

#include<iostream>
using namespace std;

int countBinarystring(int n){
    //base case:
    if(n==1 and (n+1)==1){
        return 0;
    }

    //rec case :
    int ans=0;
    ans=countBinarystring(n-1) + countBinarystring(n-2);

    return ans;
}

int main(){
    int n;
    cout<<"Enter length of binary String : ";
    cin>>n;

    cout<<"no of possible binary string which have no consecutive ones : "<<countBinarystring(n)<<endl;

}

