#include<iostream>
using namespace std;


class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

//taking input data in which will reflect in tree
node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();

    return root;
}


//print the tree : Preorder ( Root -> left -> Right)
void print(node* root){
    if(root==NULL){
        return;
    }

    //otherwise, print root first followed by subtree.
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

//Right View of Tree : 
//maxLevel -> pass by reference because we want to update its value in each step globally
//We can use both BFS as well as DFS

//  ----------------DFS---------------
//Right->root->left (reverse order because we want to visit right most node in each level)
void rightView(node*root,int level,int &maxLevel){
    //Base case :
    if(root==NULL){
        return;
    }
    //when we visit any new level in tree
    if(maxLevel<level){
        cout<<root->data<<", ";
        maxLevel=level;
    }

    rightView(root->right,++level,maxLevel);
    rightView(root->left,++level,maxLevel);
}


int main(){
    node* root=buildTree();

    print(root);
    cout<<endl;
    int maxLevel=-1;

    rightView(root,0,maxLevel);
}