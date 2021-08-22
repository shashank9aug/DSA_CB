#include <iostream>
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

vector<vector<int>> levelOrder(node *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    //queue will store node
    queue<node *> q;

    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            node *f = q.front();
            v[i] = f->data;

            q.pop();

            //check for left node :
            if (f->left)
            {
                q.push(f->left);
            }

            //check for right node :
            if (f->right)
            {
                q.push(f->right);
            }
        }

        ans.push_back(v);
    }
    return ans;
}

int main()
{
    node *root = buildTree();

    vector<vector<int>>ans=levelOrder(root);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}