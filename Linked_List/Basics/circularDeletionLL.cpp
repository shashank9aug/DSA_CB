/*
    we have to create circular LL and then insert in LL
    then,
    we can delete the 

    50->40->30->20->10
    50->40->20->10
    50->40->20

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

//deletion in circular Linked List : 
// firstly we have to search the node then we can delete that node
node* getNode(node*head,int data){
    node*temp=head;
    //for all the nodes except last node : 
    while(temp->next!=NULL){
        if(temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    //for last element
    if(temp->data==data){
        return temp;
    }
    return NULL;
}

//delete node : 
void deleteNode(node*&head,int data){

    node*del=getNode(head,data);
    if(del==NULL){
        return;
    }
    //if node present then
    node*temp=head;
    //stop one step behind the node which will need to delete
    while(temp->next!=del){
        temp=temp->next;
    }

    temp->next=del->next;
    delete(del);
}
int main(){
    node*head=NULL;

    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);

    printCLL(head);

    deleteNode(head,30);
    printCLL(head);
    deleteNode(head,10);
    printCLL(head);

}