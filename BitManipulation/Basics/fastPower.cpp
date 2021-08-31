
#include<iostream>
using namespace std;

void powerExp(int num,int exp){
    int ans=1;

    while(exp>0){
        int last_bit=(exp&1);
        if(last_bit){
            ans*=num;
        }
        //square value of num
        num=num*num;
        //discard last bit of exponent
        exp=exp>>1;
    }
    cout<<ans<<endl;

    return;
}


int main(){
    int num;
    cout<<"Enter number : ";
    cin>>num;

    int exp;
    cout<<"Enter exponenet : ";
    cin>>exp;

    powerExp(num,exp);

    return 0;
}