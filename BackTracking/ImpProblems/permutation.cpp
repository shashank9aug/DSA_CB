/*
    we have given char set :
    we have to return all the possible permutation.

    permutation : all the possible rearrangement .

ip : abc 

op : 
    abc
    acb
    bac
    bca
    cba
    cab
*/


#include<iostream>
#include<cstring>
using namespace std;

//taking i -> for traversal of given char set

void permute(char ip[],int i){
    //Base case : 
    if(ip[i]=='\0'){
        cout<<ip<<"\n";
        return;
    }

    //Rec case : 
    for(int j=i;ip[j]!='\0';j++){
        swap(ip[i],ip[j]);
        permute(ip,i+1);
        //Back track : to avoid repeating of chars : 
        swap(ip[i],ip[j]);
    }
}


int main(){
    char ip[100];
    cin>>ip;

    permute(ip,0);

    return 0;
}