/*
    check the given SinglyLL is pallindrome or not

    1->2->1
    -> true

    1->2->3->4->5
    ->false 
*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

node *takeInput()
{
    int d;
    cin >> d;

    node *head = NULL;
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    return head;
}

//print LL
void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

node *reverseLL(node *head2)
{
    node*curr=head2;
    node*prev=NULL;
    node*next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    head2=prev;
    return head2;
}

bool isPallindrome(node*head)
{
    if (head->next == NULL)
    {
        return true;
    }
    //mid point
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //reverse after mid poin all the nodes
    node *head1 = head;
    node *head2 = slow;

    head2 = reverseLL(head2);

    //check the each LL data
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main()
{
    node *head = takeInput();

    printLL(head);

    bool ans=isPallindrome(head);
    if(ans){
        cout<<"Given LL is pallindrome"<<endl;
    }
    else{
        cout<<"Not a pallindrome"<<endl;
    }
    return 0;
}