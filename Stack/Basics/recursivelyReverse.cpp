#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&st,int x){
    //Base case :
    if(st.empty()){
        st.push(x);
        return;
    }
    //Hypothesis : 
    int ele=st.top();
    st.pop();
    insertAtBottom(st,x);
    
    //Induction :
    st.push(ele);
}

void recursivelyReverse(stack<int>&st){
    //Base case :
    if(st.empty()){
        return;
    }
    //Hypothesis : 
    int x=st.top();
    st.pop();
    recursivelyReverse(st);

    //Induction :
    insertAtBottom(st,x);
}   

int main(){
    stack<int>st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    recursivelyReverse(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}