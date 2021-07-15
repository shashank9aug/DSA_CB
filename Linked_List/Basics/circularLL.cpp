/*
    we have to create circular LL and then insert in LL

*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node*next;

    node(int d){
        data=d;
        next=NULL;
    }    
};

void insertAtHead(node*&head,int data){
    node* n = new node(data);
    node* temp = head;

    n->next=head;
    if(temp!=NULL){
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;            
    }
    //for self loop 
    else{
        n->next=n;
    }
    head=n;
}


void printCLL(node*head){
    node*temp=head;
    while(temp->next!=head){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    //for last node
    cout<<temp->data<<endl;
    return;
}


int main(){
    node*head=NULL;

    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);

    printCLL(head);
}