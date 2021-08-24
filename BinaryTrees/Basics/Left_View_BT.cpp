/*
$ ./a.exe
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
8 10 1 6 9 7 3 14 13 
8, 10, 1, 9

*/

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

//left View of Tree : 
//maxLevel -> pass by reference because we want to update its value in each step globally
//We can use both BFS as well as DFS

//  ----------------DFS---------------
//left->root->left (reverse order because we want to visit right most node in each level)
void leftView(node*root,int level,int &maxLevel){
    //Base case :
    if(root==NULL){
        return;
    }
    //when we visit any new level in tree
    if(maxLevel<level){
        cout<<root->data<<", ";
        maxLevel=level;
    }

    leftView(root->left,level+1,maxLevel);
    leftView(root->right,level+1,maxLevel);
}


int main(){
    node* root=buildTree();

    print(root);
    cout<<endl;
    int maxLevel=-1;

    leftView(root,0,maxLevel);
}