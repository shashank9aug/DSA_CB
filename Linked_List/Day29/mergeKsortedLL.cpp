/*
    Approach : We have to take two linked List at time and merge them 
               using merge sorted LL function :
                 
Enter number of LL : 4
Enter lenght of kth LL : 3
Enter kth LL : 1 2 3
Enter lenght of kth LL : 2
Enter kth LL : 4 5
Enter lenght of kth LL : 2
Enter kth LL : 5 6
Enter lenght of kth LL : 2
Enter kth LL : 7 8
1->2->3->4->5->5->6->7->8->

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

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

node *mergeSortedLL(node *h1, node *h2)
{
    //Base case
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }
    node *c;

    //take head pointer
    if (h1->data < h2->data)
    {
        c = h1;
        c->next = mergeSortedLL(h1->next, h2);
    }
    else
    {
        c = h2;
        c->next = mergeSortedLL(h1, h2->next);
    }
    return c;
}

node *mergeKLists(node *arr[], int N)
{
    node*ans=NULL;

    for(int i=0;i<N;i++){
        ans=mergeSortedLL(ans,arr[i]);
    }
    return ans;
}

int main()
{
    int N;
    cout << "Enter number of LL : ";
    cin >> N;
    node *arr[N];
    for (int j = 0; j < N; j++)
    {
        int n;
        cout << "Enter lenght of kth LL : ";
        cin >> n;

        cout << "Enter kth LL : ";
        int x;
        cin >> x;
        arr[j] = new node(x);
        node *curr = arr[j];
        n--;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            node *temp = new node(x);
            curr->next = temp;
            curr = temp;
        }
    }
    node *res = mergeKLists(arr, N);
    printLL(res);
}