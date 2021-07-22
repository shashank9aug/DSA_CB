/*
    space : O(N) : due to implicit recurssive stack used during function call execution
    
    during recurssive function call stack memory used so that it will deleted after program execution.
    
*/
#include<iostream>
using namespace std;

int fact(int n){
    //Base case : 
    if(n==0){
        return 1;
    }

    //Recurssive case : 
    int small_ans=fact(n-1);
    return n*small_ans;
}

int main(){
    int n;
    cout<<"Enter number whoose factorial need to find : ";
    cin>>n;

    cout<<"factorial of number : "<<fact(n)<<endl;
}