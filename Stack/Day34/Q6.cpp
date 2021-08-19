/*
    ------Valid parantheses checker-------------

$ ./a.exe
{([])}
Valid parantheses : 1
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool ParanthesesChecker(string ip){

    stack<char>st;

    if(st.size()%2!=0){
        return false;
    }
    else{
        for(auto i:ip){
            if(i=='('){
                st.push(')');
            }
            else if(i=='{'){
                st.push('}');
            }
            else if(i=='['){
                st.push(']');
            }
            //checking for closing brackets : 
            else if(st.empty() or st.top()!=i){
                return false;
            }
            //if matched : pop st.top() 
            else if(st.top()==i){
                st.pop();
            }
        }
    }
    return st.empty();
}


int main(){
    string ip;
    cin>>ip;

    cout<<"Valid parantheses : "<<ParanthesesChecker(ip)<<endl;
}