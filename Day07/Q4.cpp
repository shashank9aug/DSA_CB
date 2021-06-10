
// Minimum no. of operations required to make an array palindrome




#include<iostream>
using namespace std;

bool check_pallindrome(int array[],int size){
    bool flag=1;
    
    for(int idx=0;idx<size;idx++){
        int temp = array[idx];
        int rem, sum=0;

        while(temp>0){
            rem=temp%10;
            sum=sum*10+rem;
            temp=temp/10;
        }
        if(array[idx]!=sum){
            flag=false;
            return flag;
        }
        else{
            sum=0;
        }
    }
    flag=1;
    return flag;
}


int main(){

    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int array[size];
    cout<<"Enter the array elements : ";
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<"Pallindrome or not : "<<check_pallindrome(array,size);

    return 0;
}