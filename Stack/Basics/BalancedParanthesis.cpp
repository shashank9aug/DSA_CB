#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isBalanced(char *s){
    stack<char>st;

    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            if(st.empty() or st.top()!=')'){
                return false;
            }
            st.pop();
        }
    }

    return st.empty()?true:false;
}

int main(){
    char s[100]="(()()";

    if(isBalanced(s)){
        cout<<"Balanced ";
    }
    else{
        cout<<"UnBalanced ";
    }

    return 0;
}