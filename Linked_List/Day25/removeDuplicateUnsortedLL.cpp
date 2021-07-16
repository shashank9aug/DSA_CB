/*
    we have to remove duplicates in sorted arrray :
    given an array we have to delete the duplicate node.

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // your code goes here

        unordered_set<int> s;
        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            if (s.find(curr->data) != s.end())
            {
                prev->next = curr->next;
                delete (curr);
            }
            else
            {
                s.insert(curr->data);
                prev = curr;
            }
            curr = prev->next;
        }
        return head;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int K;
    cin >> K;
    struct Node *head = NULL;
    struct Node *temp = head;

    for (int i = 0; i < K; i++)
    {
        int data;
        cin >> data;
        if (head == NULL)
            head = temp = new Node(data);
        else
        {
            temp->next = new Node(data);
            temp = temp->next;
        }
    }

    Solution ob;
    Node *result = ob.removeDuplicates(head);
    print(result);
    cout << endl;

    return 0;
}