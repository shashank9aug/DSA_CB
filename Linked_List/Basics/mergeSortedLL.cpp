/*
    we have two Sorted Linked List :
        L1 and L2 
        we have to merge two sorted LL into single sorted LL

    we will take two pointer on LL as h1 and h2
    then, 
        we have to compare two nodes of data .
    combine them using another pointer    

    L1 : 7 4 3 1 -1
    L2 : 10 8 2 0 -1
    C : 0->1->2->3->4->7->8->10->
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

node* mergeSortedLL(node*h1,node*h2){
    //Base case 
    if(h1==NULL){
        return h2;
    }
    if(h2==NULL){
        return h1;
    }
    node*c;

    //take head pointer
    if(h1->data < h2->data){
        c=h1;
        c->next=mergeSortedLL(h1->next,h2);
    }
    else{
        c=h2;
        c->next=mergeSortedLL(h1,h2->next);
    }
    return c;
}

int main(){
    node*head=takeInput();
    node*head1=takeInput();
    
    node*newHead=mergeSortedLL(head,head1);

    printLL(newHead);

    return 0;
}