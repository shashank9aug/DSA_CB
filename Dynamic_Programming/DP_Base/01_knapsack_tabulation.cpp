#include<iostream>
using namespace std;





int main(){
    memset(t,-1,sizeof(t));

    int n;
    cout<<"No of items : ";
    cin>>n;

    int wt[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int val[n];
    cout<<"Enter value of items : ";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int w;
    cout<<"Enter Max weight : ";
    cin>>w;

    cout<<"Maximum profit : "<<knapsack(wt,val,w,n)<<endl;

    return 0;
}