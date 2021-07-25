/*
    we will have a string which we need to convert into integer

    "1234" = 1234
    
*/

#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(char s[],int len){
    //Base case : 
    if(len==0){
        return 0;
    }

    //rec case:
    int digit=s[len-1]-'0';
    int smallAns=stringToInt(s,len-1);

    return smallAns*10+digit;
}

int main(){
    char s[]="1234";
    int len= strlen(s);

    cout<<stringToInt(s,len)<<endl;
    cout<<stringToInt(s,len)+1<<endl;
}
