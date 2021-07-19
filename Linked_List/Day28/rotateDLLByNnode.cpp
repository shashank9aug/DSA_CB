/*
    9->8->6->5->4->2->1->
    6->5->4->2->1->9->8->
*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    node *n = new node(data);
    n->next = head;

    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }

    node *n = new node(data);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

void printDLL(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void rotateDLLByN(node*&head,int position){
    if(position==0){
        return;
    }

    node* current=head;
    int count=1;
    while(count<position and current!=NULL){
        current=current->next;
        count++;
    }

    node*nthNode=current;
    while(current->next!=NULL){
        current=current->next;
    }

    current->next=head;

    head->prev=current;

    head=nthNode->next;

    head->prev=NULL;

    nthNode->next=NULL;
}

int main()
{
    node *head = NULL;

    // insertAtTail(head, 10);
    // insertAtTail(head, 10);
    // insertAtTail(head, 10);
    // insertAtTail(head, 20);
    // insertAtTail(head, 30);
    // insertAtTail(head, 40);

    insertAtTail(head,9);
    insertAtTail(head,8);
    insertAtTail(head,6);
    insertAtTail(head,5);
    insertAtTail(head,4);
    insertAtTail(head,2);
    insertAtTail(head,1);

    printDLL(head);


    rotateDLLByN(head,2);

    printDLL(head);

    return 0;
}