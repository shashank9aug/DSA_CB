/*
    Approach of this problem is that : 
        ->we are just storing single linkedList elements in set
             as set stores elements in sorted order
        
        ->we are just comparing the sets data with other LL data if it matches 
            we just erase the data of set at that position. 


$ ./a.exe
40->30->20->10->
50->20->40->
20->40->

*/

#include<iostream>
#include<set>
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

void printLL(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

node* findIntersection(node* head1, node* head2)
{
    // Your Code Here
    set<int>s;
    while(head1!=NULL){
        s.insert(head1->data);
        head1=head1->next;
    }
    
    node*start=NULL,*end=NULL;
    
    while(head2!=NULL){
        if(s.find(head2->data)!=s.end()){
            if(start==NULL){
                start=end=head2;
            }
            else{
                end->next=head2;
                end=head2;
            }
            s.erase(head2->data);
        }
        head2=head2->next;
    }
    if(start!=NULL){
        end->next=NULL;
    }
    return start;
}


int main(){
    node*head1=NULL;
    node*head2=NULL;

    insertAtHead(head1,10);
    insertAtHead(head1,20);
    insertAtHead(head1,30);
    insertAtHead(head1,40);

    printLL(head1);

    insertAtHead(head2,40);
    insertAtHead(head2,20);
    insertAtHead(head2,50);
    
    printLL(head2);

    node*start=findIntersection(head1,head2);

    printLL(start);
}