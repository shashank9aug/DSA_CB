/*
    There are two types of Construction of LL can be happen
        - object oriented based.
        - Procedural programming Based.

    - Preffered one procedural programming based : 
        Because we can make our separate function According to requirements.

*/


#include<iostream>
using namespace std;

// Fuction based :
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


// object oriented based : 
/*
class LinkedList{
    public:
        node *head;
        node *tail;

    public:
        LinkedList(){

        }

        void insert(int d){

        }
};

*/

/*
    we are just passing head as pass by reference because,
        we want to modify LL after complition of function call 
    But if we were using pass by value then we will loose the momory after function call over    
        => static memory will distroy after function call will over
        => dynamic memory will remain after function call over.
*/
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


int main(){
    node*head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    PrintLL(head);

}