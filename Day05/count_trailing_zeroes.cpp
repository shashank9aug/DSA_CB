
// count the trailing zeroes inside n! of n is very large number

#include<iostream>
using namespace std;

/*
    logic : we have to divide number [100/5]+[100/5*5]+...untill [number/p] become zeroes
    like calculating n! and counting zeroes from that is quite time consuming
*/

int trailing_zeroes(int number){
    int ans=0;
    int p=5;

    while((number/p)>0){
        ans+=(number/p);
        p=p*5;
    }
    return ans;
}

int main(){
    int number;
    cout<<"Enter the number : ";
    cin>>number;

    cout<<"No of trailing zeroes : "<<trailing_zeroes(number)<<endl;

    return 0;
}

