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

node *addOneToLLNum(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *curr = head;
    //if last element will not be two 10 after increment
    if (temp->data != 9)
    {
        temp->data++;
        return head;
    }
    else
    {
        while (head != temp)
        {
            temp->data = 0;
            curr = head;
            while (curr->next != temp)
            {
                curr = curr->next;
            }
            if (curr->data == 9)
            {
                temp = curr;
            }
            else
            {
                curr->data++;
                return head;
            }
        }
    }
    head->data++;
    return head;
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

    addOneToLLNum(head);

    printLL(head);
}