/*
    we have again two approach :
        - calculat lenght of ll then traverse N-k lenght => two loop
        - Runner technique.( using two pointer )
                -traverse first fast pointer by kth position 
                    then,
                    traverse Fast and slow both by single step.
                    at the end : slow will be at (N-k) postion
                                 Fast will be at NULL    
    eg: 
    3 4 5 6 7 8 -1
    Enter the kth position : 3
    8->7->6->5->4->3->
    Kth position of LL : 5                             
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

node* kthNodeFromEnd(node*head,int k){
    if(head==NULL or head->next==NULL){
        return head;
    }

    node*fast=head;
    node*slow=head;
    while(k!=0){
        fast=fast->next;
        k--;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

int main(){
    node*head=takeInput();

    cout<<"Enter the kth position : ";
    int k;
    cin>>k;

    printLL(head);

    node*kth=kthNodeFromEnd(head,k);
    cout<<"Kth position of LL : "<<kth->data<<endl;

    return 0;
}