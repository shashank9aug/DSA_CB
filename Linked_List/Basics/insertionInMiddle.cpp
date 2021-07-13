/*
    Insert at middle : 
        traverse head upto the position then change the pointers
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

//calculate lenght of LL
int length(node*head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}

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



// Assuming that position should be >0 but <sizeOfLL
void insertInMiddle(node*&head,int data,int position){
    //create Node
    /*
        --- for position==0 ---
    */
    if(position==0){
        insertAtHead(head,data);
    }

   /*
        ---- for position==size-1 ----
    */
    else if(position>length(head)){
        cout<<"Insertion will be done at the end of LL"<<endl;
        return ;
    }

    //postion is in between of ll lenght
    else{
        //it will take position-1 jump
        int jump=1;
        //create temprory pointer for  
        node*temp=head;
        while(jump<=position-1){
            temp=temp->next;
            jump++;
        }
        //create node to insert
        node *n=new node(data);
        n->next=temp->next;
        temp->next=n; 
    }
}

//print the LL
void printLL(node*head){
    while(head!=NULL){
        cout<<head->data<<",";
        head=head->next;
    }
}

int main(){
    // int position;
    // cout<<"Enter position to insert : ";
    // cin>>position;

    node*head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);

    printLL(head);
    cout<<endl;
    insertInMiddle(head,2,2);

    printLL(head);

    return 0;
}
