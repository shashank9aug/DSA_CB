/*
Queue implementation using Linked List stl.

    Methods available inside List class : 
    - push_front() , pop_front()
    - push_back() , pop_back()
*/

#include<iostream>
#include<list>
//forward List header file consists implamentation of singly LL
// #include<forward_list>
using namespace std;

class Queue {
    int cs=0;
    list<int>l;
public : 
    Queue(){
        cs=0;
    }
    
    bool isEmpty(){
        return cs==0;
    }

    void push(int data){
        l.push_back(data);
        cs+=1;
    }

    void pop(){
        if(!isEmpty()){
            cs--;
            l.pop_front();
        }    
    }

    int front(){
        return l.front();
    }
};

int main(){
    Queue q;

    for(int i=0;i<=10;i++){
        q.push(i);
    }

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}