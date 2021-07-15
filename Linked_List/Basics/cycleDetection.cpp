/*
    [!important]

    Floyd's Cycle detection technique : 
        -> Based on Runner technique.
        -> Detect cycle and remove it

        
                 
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

bool cycleDetection(node*h){
    node*slow=h;
    node*fast=h;

    while(slow!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}


int main(){
    node*head=take_input();
    PrintLL(head);

    bool ans=cycleDetection(head);

    if(ans){
        cout<<"Cycle present"<<endl;
    }
    else{
        cout<<"Cycle absent"<<endl;
    }

}