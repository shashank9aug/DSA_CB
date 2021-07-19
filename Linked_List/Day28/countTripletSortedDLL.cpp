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
//Naive Approach :  O(n^3)
int countTripletM1(node *head, int k)
{
    node *ptr1, *ptr2, *ptr3;
    int count = 0;
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)
            {
                if ((ptr1->data + ptr2->data + ptr3->data) == k)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

// M-2 : Using Hashing

// M-3 : Two pointer Approach : O(n) and O(1)

int countPairs(node *first, node *last, int key)
{
    int count = 0;

    while (first != NULL and last != NULL and first != last and last->next != first)
    {

        if ((first->data + last->data) == key)
        {
            count++;

            first = first->next;

            last = last->prev;
        }

        // if sum is greater than 'value'
        // move second in backward direction
        else if ((first->data + last->data) > key)
        {
            last = last->prev;
        }

        //move first in forward direction
        else
        {
            first = first->next;
        }
    }
    return count;
}

int countTripletM3(node *head, int key)
{
    if (head == NULL)
    {
        return 0;
    }

    node *current;
    node *first;
    node *last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    int count = 0;
    //traverse from left
    for(current=head;current!=NULL;current=current->next){

        first=current->next;

        // we are passing (key-current->data) because current data is one of the 3 item
        count+=countPairs(first,last,(key - current->data));
    }
    return count;
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

    int key;
    cout << "Enter triplet sum : ";
    cin >> key;

    // cout << "Total triplets in sorted DLL : " << countTripletM1(head, key) << endl;
    cout << "Total triplets in sorted DLL : " << countTripletM3(head, key) << endl;

    return 0;
}