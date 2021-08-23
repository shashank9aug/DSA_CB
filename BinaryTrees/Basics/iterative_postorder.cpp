#include <iostream>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//taking input data in which will reflect in tree
node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void postorderTraversal(node *root)
{
    if (root == NULL)
        return;
    stack<node *> st1;
    node *current = root;
    while (current != NULL || !st1.empty())
    {
        if (current != NULL)
        {
            st1.push(current);
            current = current->left;
        }
        else
        {
            node *temp = st1.top()->right;
            if (temp == NULL)
            {
                temp = st1.top();
                st1.pop();
                cout<<temp->data<<", ";
                while (!st1.empty() && temp == st1.top()->right)
                {
                    temp = st1.top();
                    st1.pop();
                    cout<<temp->data<<", ";
                }
            }
            else
            {
                current = temp;
            }
        }
    }
    return;
}

int main()
{
    node *root = buildTree();

    postorderTraversal(root);
}