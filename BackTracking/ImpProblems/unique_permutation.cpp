/*
    we have given char set :
    we have to return all the possible permutation.

    permutation : all the possible rearrangement .

    if  Given in question : unique and lexicographical 

    we can use set for that => stl container 

ip : aba

op : aab,aba,baa,
    
*/


#include<iostream>
#include<set>
#include<string>
#include<cstring>
using namespace std;

//taking i -> for traversal of given char set

void permute(char ip[],int i,set<string>&s){
    //Base case : 
    if(ip[i]=='\0'){

        string t(ip);

        s.insert(t);

        return;
    }

    //Rec case : 
    for(int j=i;ip[j]!='\0';j++){
        swap(ip[i],ip[j]);
        permute(ip,i+1,s);
        swap(ip[i],ip[j]);
    }
}


int main(){
    char ip[100];
    cin>>ip;
    
    set<string>s;
    permute(ip,0,s);

    //print unique and lixicographical order strings : 
    for(auto str : s){
        cout<<str<<",";
    }

    return 0;
}