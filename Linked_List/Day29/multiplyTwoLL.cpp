/*
    we have given two LL we have to return ans(as long long int ans)

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

long long multiplyLL(node*l1,node*l2){
    long long ans=1;
    long long num1=0,num2=0,mod=1000000007;
    
    while(l1 or l2){
        if(l1){
            num1=(num1*10+l1->data)%mod;
        
            l1=l1->next;
        }
        
        if(l2){
            num2=(num2*10+l2->data)%mod;
            
            l2=l2->next;
        }
    }
  return (num1*num2)%mod;           
}

int main(){
    node*head=NULL;
    // insertAtHead(head,5);
    // insertAtHead(head,4);
    // insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    PrintLL(head);

    node*head1=NULL;
    insertAtHead(head1,1);
    insertAtHead(head1,2);
    // insertAtHead(head1,3);
    // insertAtHead(head1,4);
    // insertAtHead(head1,5);

    PrintLL(head1);

    cout<<"Product of two LL elements : "<<multiplyLL(head,head1)<<endl;
}