#include <iostream>
#include <map>
#include <vector>
#include <queue>
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

node *buildTreeLevelWise()
{

    int d;
    cin >> d;

    node *root = new node(d);
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *f = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            f->left = new node(c1);
            q.push(f->left);
        }
        if (c2 != -1)
        {
            f->right = new node(c2);
            q.push(f->right);
        }
    }
    return root;
}

void verticalOrderPrint(node *root, map<int, vector<int>> &m, int d = 0)
{
    if (root == NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    verticalOrderPrint(root->left, m, d - 1);
    verticalOrderPrint(root->right, m, d + 1);
}

int main()
{
    int levels;
    cin >> levels;
    node *root = buildTreeLevelWise();

    map<int, vector<int>> m;

    verticalOrderPrint(root, m);
    for(auto itr : m) {
        for(auto x : itr.second) {
            cout << x << " ";
        }
    }


    return 0;
}