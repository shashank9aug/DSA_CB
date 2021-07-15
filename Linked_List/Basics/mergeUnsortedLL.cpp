/*
    we will have one single unsorted LL
    L : unsorted LL

    we have to sort that LL
    so,
        1 : Break the LL into two parts.
        2 : Sort them separetly.
        3 : merge the sorted parts

    $ ./a.exe
    1 0 4 3 2 5 -1
    0->1->2->3->4->5->    
*/

// #include<iostream>
// #include<algorithm>
#include<bits/stdc++.h>
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
    node*fast=head->next;

    
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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

node* mergeUnsortedLL(node*h){
    //Base case 
    if(h==NULL or h->next==NULL){
        return h;
    }

    //rec case :
    //Break
    node*mid=midPoint(h);
    node*h1=h;
    node*h2=mid->next;

    mid->next=NULL;

    //2 : reccursively sort the two parts 
    h1 = mergeUnsortedLL(h1);
    h2 = mergeUnsortedLL(h2);

    //3 : merge them
    node*c=mergeSortedLL(h1,h2);

    return c;
}

int main(){
    node*head=takeInput();
    
    node*Head=mergeUnsortedLL(head);

    printLL(Head);

    return 0;
}