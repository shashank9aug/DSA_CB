/*
    Stack  : st1,st2  --> LIFO 
    Queue  : q --> FIFO
*/

#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class queue {
public:
    stack<T>s1,s2;
       
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int curr = s1.top();
        s1.pop();
        return curr;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};


int main(){
    queue<int>q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    cout<<q.pop()<<endl;
    

    return 0;
}