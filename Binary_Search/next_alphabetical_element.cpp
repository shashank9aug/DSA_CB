/*
    problem is similar to ceil of integer number 

    given set of alphabets which is sorted as well 
    
    ch[5]={a,b,c,f,h}
    key = f
    we have to find next alphabetical char otherwise return '#'
    o/p : h

*/

#include<iostream>
#include<algorithm>
using namespace std;


char next_alphabet(int n,char inp[],char key){
    int start=0;
    int end=n-1;

    char ans='#';

    while(start<=end){
        int mid=start+(end-start)/2;
        //if we got key we will move start mid+1
        if(inp[mid]==key){
            start=mid+1;
        }
        else if(inp[mid]>key){
            ans=inp[mid];
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}


int main(){
    int n;
    cout<<"Enter number of char in inp arr : ";
    cin>>n;
    
    char inp[n];
    cout<<"Enter input char elements : ";
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }

    char key;
    cout<<"char for which next char need to search : ";
    cin>>key;

    cout<<"Next char is : "<<next_alphabet(n,inp,key);

    return 0;
}
