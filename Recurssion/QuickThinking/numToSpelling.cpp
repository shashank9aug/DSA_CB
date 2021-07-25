/*
    We have to write a function which will use recurssion to output string in spelling format

    2048 = two zero four eight

    and if we want to print the spellings in reverse order 
    we have to only change the order of line execution.

    2048 = eight four zero two
*/

#include<iostream>
#include<cstring>
using namespace std;

//global array :
string spell[10]= {"zero","one","two","three","four","five","six","seven","eight","nine"};

void numTospell(int n){
    //Base case :
    if(n==0){
        return;
    }

    //rec case :
    int digit=(n%10);
    cout<<spell[digit]<<",";

    numTospell(n/10);

    // int digit=(n%10);
    // cout<<spell[digit]<<",";

    return;
}

int main(){
    int num;
    cin>>num;

    numTospell(num);    

}