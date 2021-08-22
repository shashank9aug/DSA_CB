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


int main(){
    node* root=buildTree();

    print(root);
}