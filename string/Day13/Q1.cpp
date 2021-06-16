// Input: str = “0100110101” 
// Output: 4 
// The required substrings are “01”, “0011”, “01” and “01”.
// Input: str = “0111100010” 
// Output: 3 

#include<iostream>
#include<cstring>
using namespace std;

int binary_substr(string str){
    
    int count=0;
    int count_0=0;
    int count_1=0;

    for(int idx=0;idx<str.size();idx++){
        if(str[idx]=='0'){
            count_0++;
        }
        else{
            count_1++;
        }
        //check equal no of 0's and 1's in binary substring
        if(count_0==count_1){
            count++;
        }
    }

    //check whether the given string is monotonic or not
    if(count==0){
        return -1;
    }
    return count;
}

int main(){
    
    string str;
    cout<<"Enter a binary string : ";
    cin>>str;

    cout<<"max substring with equal no of 0 and 1's : "<<binary_substr(str)<<endl;

    return 0;   
}