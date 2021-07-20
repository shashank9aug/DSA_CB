#include <iostream>
#include<vector>
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

node *segregateEvenOdd(node *head)
{
    vector<int> even;
    vector<int> odd;
    node *p = head;

    while (p != NULL)
    {
        if ((p->data) % 2 == 0)
        {
            even.push_back(p->data);
        }
        else
        {
            odd.push_back(p->data);
        }
        p = p->next;
    }
    node *r = head;
    for (int i = 0; i < even.size(); i++)
    {
        r->data = even[i];
        r = r->next;
    }
    for (int i = 0; i < odd.size(); i++)
    {
        r->data = odd[i];
        r = r->next;
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

    segregateEvenOdd(head);

    PrintLL(head);
}