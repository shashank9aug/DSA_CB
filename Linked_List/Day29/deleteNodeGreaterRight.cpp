/*
1->2->3->4->5->
5->
*/

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

node *deleteNodeGreaterRight(node *head)
{
    node *curr = head;
    node *prev = NULL;
    while (curr != NULL and curr->next != NULL)
    {
        if (curr->data < curr->next->data)
        {
            prev = curr->next;
            curr->data = prev->data;
            curr->next = prev->next;
            curr = head;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
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

    deleteNodeGreaterRight(head);

    PrintLL(head);
}