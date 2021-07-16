#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
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

node* takeInput(){
    int d;
    cin>>d;

    node*head=NULL;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

void printLL(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}

node* startingPointLoop(node* head){
    node*fast=head;
    node*slow=head;

    //co
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast){
            break;
        }
    }


}

int main(){
    node*head=NULL;

    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);

    printLL(head);

    startingPointLoop(head);
}