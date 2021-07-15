/*
    we can reverse a LinkedList By 2 methods :
     - Swapping the data of LL
     - Reversing the Links of LinkedList

    $ ./a.exe
    1 2 3 4 5 -1
    5->4->3->2->1->
    1->2->3->4->5->    
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

//print LL
void printLL(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}


//Iterative Method
void reverseLL(node*&head){
    node*prev=NULL;
    node*c=head;
    node*n;

    while(c!=NULL){
        n=c->next;
        c->next=prev;
        prev=c;
        c=n;
    }
    head=prev;    
}


//Recurssive Method : 
void reverseLLRecursive(node*&head){
    
}

int main(){
    node*head=takeInput();

    printLL(head);

    reverseLL(head);

    printLL(head);
}