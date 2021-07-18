#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node*next;
        node*prev;
    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }    
};

void insertAtHead(node*&head,int data){
    node*n=new node(data);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

void insertAtTail(node*&head,int data){
    if(head==NULL){
        insertAtHead(head,data);
        return;
    }
    node*n=new node(data);
    node*temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;
}


void printDLL(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;   
}


int main(){
    node*head=NULL;

    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);

    printDLL(head);

    insertAtHead(head,50);

    printDLL(head);
}