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

void deleteAtHead(node*&head){
    node*todelete=head;
    head=head->next;
    head->prev=NULL;

    delete(todelete);
}


void deletionInDLL(node* &head,int position){
    
    if(position==1){
        deleteAtHead(head);
        return;
    }
    
    node*temp=head;
    int count=1;

    while(temp!=NULL and count!=position){
        temp=temp->next;
        count++;
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }

    delete(temp);

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

    deletionInDLL(head,3);
    deletionInDLL(head,1);

    printDLL(head);
}