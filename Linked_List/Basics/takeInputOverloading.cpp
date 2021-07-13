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
    cout<<endl;
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


// void operator<<(ostream &os,node*head){
//     PrintLL(head);
//     return;
// }

ostream &operator<<(ostream&os,node*head){
    PrintLL(head);
    return os;
}

istream &operator>>(istream&is,node*&head){
    head=take_input();
    return is;
}

int main(){
    /*
    node*head=take_input();
    node*head1=take_input();
    node*head2=take_input();
    */
    //operator overloading   
    // cout<<head;
    // cout<<head1;
    // cout<<head2;

    /*
        if we want to use 
            cout<<head<<head1;
            it will return an error because :
            cout<<head;=> it will return void after execution
                if we return cout itself then we can do it.
        so,

        ostream &operator<<(ostream &os,node*head){

            return os;
        }    
    => this is called Cascading of operator.    
    */

//    cout<<head<<head1<<head2;



   /*
    overloading cin operator :
        cin>>head>>head1;    
   */ 

    node*head;
    node*head1;
    node*head2;
    cin>>head>>head1>>head2;

    cout<<head<<head1<<head2;
    /*
    1 2 3 4 -1
    5 6 7 8 -1
    5 6 1 3 -1
    4->3->2->1->
    8->7->6->5->
    3->1->6->5->
    */

   
}