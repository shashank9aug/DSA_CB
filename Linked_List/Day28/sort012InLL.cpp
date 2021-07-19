/*
    We have to sort the LL having 0 ,1 ,2 as data
    return the sorted LL in O(N) time and O(1) space

0->0->1->1->2->2->1->0->2->2->
0->0->0->1->1->1->2->2->2->2->    
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
}

node *sort012LL(node *head)
{
    // Add code here
    node *temp = head;
    int arr[3] = {0};

    //counting no of 0,1,2 in LL
    while (temp != NULL)
    {
        arr[temp->data]++;
        temp = temp->next;
    }
    temp = head;

    //storing 0,1,2 in LL in sorted order
    for (int i = 0; i < 3; i++)
    {
        while (arr[i]--)
        {
            temp->data = i;
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    insertAtHead(head, 0);


    PrintLL(head);

    cout<<endl;
    node*temp=sort012LL(head);

    PrintLL(temp);
}