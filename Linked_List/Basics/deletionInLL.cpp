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

void insertAtHead(node* &head,int data){
    //check if head==null
    if(head==NULL){
        head=new node(data);
        return;
    }
    //if their is any node with head
    node *temp=new node(data);
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

//delete at head : 
void deleteAtHead(node*&head){
    //if their is only single node
    if(head==NULL){
        return;
    }
    node*temp=head->next;
    delete head;
    head=temp;
}

//delete in middle
void deleteInMiddle(node*&head,int position){
    int jump=0;
    node*temp=head;
    //traverse temp node upto position
    while(jump<=position-1){
        temp=temp->next;
        jump++;
    }
    node*prev=head;
    jump=0;
    while(jump<=position-2){
        prev=prev->next;
        jump++;
    }
    prev->next=temp->next;
    delete temp;
    temp=head;
}

int main(){
    node*head=NULL;

    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    printLL(head);

    deleteAtHead(head);
    printLL(head);

    deleteInMiddle(head,2);
    printLL(head);
}