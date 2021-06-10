// Write a function that reverses a string. The input string is given as an array
// of characters s.

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverse_string(vector<char>&str){
    int start=0;
    int end=str.size()-1;

    while(start<end){
        // swap(str[start],str[end]);
        char temp = str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        temp--;    
    }
}

int main(){
   vector<char>str;
    for(int idx=0;idx<5;idx++){
        int input;
        str.push_back(input);
        cin>>input;
    }
    reverse_string(str);

    cout<<"Reversed String : ";
    
    for(int idx=0;idx<str.size();idx++){
        cout<<str[idx]<<",";
    }

    return 0;
}