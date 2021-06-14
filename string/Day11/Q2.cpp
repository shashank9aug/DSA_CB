// Input: S = "abba"
// Output: 1
// Explanation: S is a palindrome


#include<iostream>
#include<cstring>
using namespace std;


bool pallindromic_string(string str){
    int start=0;
    int end=str.size()-1;
    bool flag=0;
    while(start<end){
        if(str[start]==str[end]){
            start++;
            end--;
            flag=1;
        }
        else{
            flag=0;
            return flag;
        }
    }
    return flag;
}


int main(){
    string str;
    cout<<"Enter the input string : ";
    cin>>str;

    bool ans=pallindromic_string(str);

    if(ans){
        cout<<"Pallindromic string";
    }
    else{
        cout<<"Not a pallindromic string";
    }   
}