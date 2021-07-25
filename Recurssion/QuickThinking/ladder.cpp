/*
    we have given ladder and maximum number of jumps that we can perform to reach the top

    we have to count max possible way we can reach the top of ladder

*/

#include<iostream>
using namespace std;

int reachTop(int n,int k){
    //Base case :
    if(n==0){
        return 1;
    }

    if(n<0){
        return 0;
    }

    //rec case :
    int ans=0;
    for(int i=1;i<=k;i++){
        // n-i because we have reached these many steps
        ans+=reachTop(n-i,k);
    }

    return ans;
}

int main(){
    int n,k;
    cout<<"Enter value of n and k : ";
    cin>>n>>k;

    cout<<"Maximum number of steps : "<<reachTop(n,k)<<endl;

    return 0;
}