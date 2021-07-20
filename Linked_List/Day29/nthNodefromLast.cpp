#include <iostream>
using namespace std;

// Fuction based :
class node
{
public:
    int data;
    node *next;

    //constructor :
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    //check if head==null
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    //if their is any node with head
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

//print the linkedList
void PrintLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

int getNthFromLast(node *head, int n)
{
    // Your code here
    // n = nth node from end of LL
    int length=0;
    node*curr=head;
    while(curr!=NULL){
        length++;
        curr=curr->next;
    }
    
    if(n>length){
        return -1;
    }
    
    curr=head;
    for(int i=1;i<=(length-n);i++){
        curr=curr->next;
    }
    return (curr->data);
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    PrintLL(head);

    int n;
    cout<<"Enter nth node need to delete from last : ";
    cin>>n;

    cout<<"Nth node from last : "<<getNthFromLast(head,n)<<endl;

    return 0;
}