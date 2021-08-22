/*
$ ./a.exe
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
8 10 1 6 9 7 3 14 13 
No of nodes : 9

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

int countNodes(node*root){
    if(root==NULL){
        return 0;
    }

    return 1 + countNodes(root->left)+countNodes(root->right);
}

int sumOfNodes(node* root){
    if(root==NULL){
        return 0;
    }

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main(){
    node* root=buildTree();

    print(root);
    cout<<endl;
    cout<<"No of nodes : "<<countNodes(root)<<endl;
    cout<<"sum of nodes : "<<sumOfNodes(root)<<endl;
}