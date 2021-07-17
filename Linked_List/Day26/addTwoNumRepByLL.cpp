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

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

node *addTwoRepLL(node *head)
{

}

int main()
{
    node *head = NULL;

    // insertAtHead(head, 1);
    // insertAtHead(head, 2);
    // insertAtHead(head, 3);
    // insertAtHead(head, 4);

    insertAtHead(head,9);
    insertAtHead(head,9);
    insertAtHead(head,9);

    printLL(head);

    addTwoRepLL(head);

    printLL(head);
}