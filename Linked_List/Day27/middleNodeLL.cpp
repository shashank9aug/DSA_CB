/*
    we can use two mehtod to solve this :
        - calculate lenght and traverse L/2 for even and (L/2)-1 for odd
        - Runner technique => It states that f=> will move 2x speed S=> will move x speed   
                when F will reach end  S will be at mid
    for L=odd 
    eg: L=5 
        1->2->3->4->5->NULL
        mid=3
        F and S will be at head
    for L=even
        1->2->3->4->NULL
        mid=2
        F will be at head->next and slow will be at head 
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

node* midPoint(node*head){
    // no node or only one node
    if(head==NULL or head->next==NULL){
        return head;
    }

    node*slow=head;
    node*fast=head;

    
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

int main(){
    node*head=takeInput();

    printLL(head);

    node*mid=midPoint(head);
    cout<<"Mid point of LL : "<<mid->data<<endl;

    return 0;
}