/*
    6 5 4 3 2 1
    -1
    1->2->3->4->5->6->
*/


#include<iostream>
using namespace std;

class node{ 
    public:
        int data;
        node *next;

    //constructor : 
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

//print the linkedList
void PrintLL(node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}

// void take_input(node*&head){

// }

node* take_input(){
    int d;
    cin>>d;

    node* head=NULL;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}


int main(){
    node*head=take_input();
    PrintLL(head);
}