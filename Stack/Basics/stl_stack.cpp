#include <iostream>
//Header file will implement all the operation of stack
#include<stack>
using namespace std;


// Push() , Pop() , Peek() , top() , empty(). 
int main() {
    stack<int>s;

    for(int i=1;i<=5;i++){
        s.push(i);
    }
    //Try to print the content of the stack by popping each element
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
return 0;
}