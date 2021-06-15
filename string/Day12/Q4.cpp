//Print all the subsequences of string

// Input : abc
// Output : a, b, c, ab, bc, ac, abc

// Input : aaa
// Output : a, aa, aaa


#include<iostream>
#include<vector>
using namespace std;

vector<string> subsequence_string(string str){
    
}


int main(){
    string str;
    cout<<"Enter input string : ";
    cin>>str;

    vector<string>ans=subsequence_string(str);

    cout<<"All the subsequence of string : ";
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}