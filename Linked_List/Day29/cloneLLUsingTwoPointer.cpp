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
    if(head==NULL){
        head=new node(data);
        return;
    }

    node*temp=new node(data);
    temp->next=head;
    head=temp;
}

void printLL(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;            
    }
    cout<<endl;
}

node* copyLL(node*head){
    
}

int main(){
    node*head=NULL;

    insertAtHead(head,10);    
    insertAtHead(head,20);    
    insertAtHead(head,30);    
    insertAtHead(head,40);

    printLL(head);    
}