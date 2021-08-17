/*
    Implement stack using two queue.

    q1,q2 -> FIFO 
    S -> LIFO
*/

#include<iostream>
#include<queue>
using namespace std;

template<typename T>
//Implement stack using two queue : 
class stack{
    queue<T>q1,q2;
public : 
    void push(T x){
        q1.push(x);
    }

    void pop(){
        //remove last added element from q1 : 
        //remove first n-1 element in q2 : 
        //interchange the names of q1 and q2 :
        if(q1.empty()){
            return;
        }

        while(q1.size()>1){
            T element=q1.front();
            q2.push(element);
            q1.pop();
        }

        //remove the last element : 
        q1.pop();

        //swap the names of q1 and q2 : 
        swap(q1,q2);
    }


    T top(){
        while(q1.size()>1){
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }

        //1 element will remain in q1
        T element=q1.front();
        q1.pop();
        q2.push(element);

        swap(q1,q2);
        return element;
    }

    int size(){
        return q1.size()+q2.size();
    }

    bool empty(){
        return size()==0;
    }
};



int main(){
    stack<int>st;

    st.push(10);
    st.push(100);
    st.push(1000);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}