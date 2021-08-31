#include<iostream>
using namespace std;

//Method : 1  (T.C : O())
int countSetBits(int no){
    int ans=0;
    while(no>0){
        ans+=(no&1);
        no=no>>1;
    }

    return ans;
}

 
//Method : 2  faster than M1 : How ?? => dry run
int countSetBitsFast(int no){
    int ans=0;
    while(no>0){
        no=(no&(no-1));
        ans++;
    }

    return ans;
}

int main(){
    int no;
    cout<<"Enter no : ";
    cin>>no;

    int ans = countSetBits(no);

    cout<<ans<<endl;

    int ans1=countSetBitsFast(no);

    cout<<ans1<<endl;    

    //Method : 3 
    cout<<__builtin_popcount(no)<<endl;

    return 0;
}