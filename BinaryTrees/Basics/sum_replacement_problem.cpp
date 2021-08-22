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

int replaceSum(node* root){
    if(root==NULL){
        return 0;
    }
    //check for leaf node and return its data
    if(root->left==NULL and root->right==NULL){
        return root->data;
    }

    //recursive part : 
    int leftSum=replaceSum(root->left);
    int rightSum=replaceSum(root->right);

    int temp=root->data;
    root->data=leftSum+rightSum;

    return temp+root->data;
}

int main(){
    node* root=buildTree();

    print(root);
    cout<<endl;
    
    replaceSum(root);

    print(root);
}