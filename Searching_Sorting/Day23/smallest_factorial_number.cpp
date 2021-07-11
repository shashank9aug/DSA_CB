/*
    Input: A = 1, B = 3, C = 2
    Output: 1
    Explaination: 3 is the second term of the 
                sequence starting with 1 and having a common 
    difference 2.

    we have to check the smallest number whose factorial has n trailing zeroes.

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of trailing zeroes : ";
    cin>>n;

    int ans=0;
            while(n){
                ans+=n/5;
                n=n/5;
            }
            cout<<ans;
            return 0;
}