/*
    Split circular LL into two halfs : 
        if no of nodes will be odd then 1st will have one node more than the other half
    both the resultant LL must be circular also

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

void splitList(node *head, node **head1_ref, node **head2_ref)
{
    // your code goes here
    //find the midPoint of CLL
    node*slow=head;
    node*fast=head->next;
    while(fast!=head and fast->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    //first CLL will start from head
    *head1_ref=head;
    
    //for second CLL => start from mid->next;
    *head2_ref=slow->next;
    
    //make first LL as circular
    slow->next=*head1_ref;
    
    node*curr=*head2_ref;
    
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=*head2_ref;
}


int main(){
    node*head=NULL;

    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);

    printCLL(head);

    node**head1=NULL;
    node**head2=NULL;

    splitList(head,*&head1,*&head2);

    printCLL(*head1);
    printCLL(*head2);

}