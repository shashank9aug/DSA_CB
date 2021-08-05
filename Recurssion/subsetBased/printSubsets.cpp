/*
    we have to take string as input and print all the possible subsets of string.

    "ab" = ["","a","b","ab"] 

    for this we will use method called  :  IP-OP method.

*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

void printSubsets(string str,string op,vector<string>&ans){
    //Base case : 
    if(str.length()==0){
        // cout<<op<<",";
        ans.push_back(op);
        return; 
    }

    //IP-OP step for recurssive tree : 
    string op1=op;
    string op2=op;

    op2.push_back(str[0]);

    //erase function takes input as an iterator : 
    str.erase(str.begin()+0);
    
    printSubsets(str,op1,ans);
    printSubsets(str,op2,ans);

    return;
}


int main(){
    string str;
    cout<<"Enter input strings : ";
    cin>>str;

    string op="";
    vector<string>ans;
    printSubsets(str,op,ans);
    // sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
    return 0;
}