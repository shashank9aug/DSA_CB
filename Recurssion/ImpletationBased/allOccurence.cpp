/*

*/

#include<iostream>
using namespace std;

void AllOccurence(int arr[],int n,int i,int key){
    //Base case :
    if(i==n){
        return;
    }

    //rec case : 
    if(arr[i]==key){
        cout<<i<<",";    
    }

    AllOccurence(arr,n,i+1,key); 
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int i=0;
    AllOccurence(arr,n,i,key);

    return 0;
}