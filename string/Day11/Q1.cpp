// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]


#include<iostream>
#include<cstring>
using namespace std;

// void reverse_string(string s){
//     for(int idx=s.length()-1;idx>=0;idx--){
//         cout<<s[idx];    
//     }
// }

void reverse_string(char str[]){
    int start=0;
    int end=strlen(str)-1;

    while(start<end){
        // if(str[start] != str[end])
        // {
        //     str[start] = str[start] + str[end];
        //     str[end] = str[start] - str[end];
        //     str[start] = str[start] - str[end];
        // }
        // char temp=str[start];
        // str[start]=str[end];
        // str[end]=temp;
        // start++;
        // end--;


        swap(str[start++],str[end--]);

    }

    
    for(int idx=0;idx<strlen(str);idx++){
        cout<<str[idx];
    }
}

int main(){
    // string s1;
    // cout<<"Enter the input string : ";
    // cin>>s1;

    // reverse_string(s1);    

    // cout<<s1;

    cout<<"Enter the length of array : ";
    int length;
    cin>>length;
    cin.get();
    char str[length];
    cin.getline(str,length);

    // for(int idx=0;idx<length;idx++){
    //     cin>>str[idx];
    // }

    reverse_string(str);

    // for(int idx=0;idx<length;idx++){
    //     cout<<str[idx];
    // }

    return 0;
}