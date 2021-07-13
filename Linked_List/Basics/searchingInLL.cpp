
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

//Linear search :
bool searchInLL(node *head, int key)
{
    node *temp = head;
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

//recursively :
bool searchRecurssively(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }

    //rec case check at head,remaining linked List.
    if (head->data == key)
    {
        return true;
    }
    else
    {
        return searchRecurssively(head->next, key);
    }
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
    
    if (searchInLL(head, 13))
    {
        cout << "Key present" << endl;
    }
    else
    {
        cout << "Key not present" << endl;
    }
     
    if (searchRecurssively(head, 1))
    {
        cout << "Key present" << endl;
    }
    else
    {
        cout << "Key not present" << endl;
    }

    return 0;
}