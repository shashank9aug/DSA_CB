#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    node(int d){
        data=d;
        next==NULL;
    }
};

class queue{
public:
    node* front,*rear;
    queue(){
        front=rear=NULL;
    }

    void push(int d){
        node*temp=new node(d);

        //if queue is empty front and rear both will be on new node
        if(rear==NULL){
            front=rear=temp;
            return;
        }

        rear->next=temp;
        rear=temp;
    }

    void pop(){
        //if queue is empty
        if(front==NULL){
            return;
        }

        node*temp=front;
        front=front->next;

        //if front will be null then make rear also as null
        if(front==NULL){
            rear=NULL;
        }

        delete temp;
    }
};

int main(){
    queue q;
    q.push(1);    
    q.push(2);    
    q.push(3);    
    q.push(4);
    q.push(5);

    q.pop();
    q.pop();

    cout<<"Front : "<<(q.front)->data<<endl;    
    cout<<"Rear  : "<<(q.rear)->data<<endl;    

    return 0;
}