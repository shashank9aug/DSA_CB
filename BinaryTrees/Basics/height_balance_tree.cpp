// #include<iostream>
// #include<cmath>
#include<bits/stdc++.h>
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

//taking input data for nodes data of tree
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

class HBPair{
public:
    int height;
    bool balanced;    
};

HBPair isHeightBalanced(node*root){
    HBPair p;
    if(root==NULL){
        p.height=0;
        p.balanced=true;

        return p;
    }

    HBPair left=isHeightBalanced(root->left);
    HBPair right=isHeightBalanced(root->right);

    // +1 -> add count of node itself.
    p.height=max(left.height,right.height) + 1;

    if(abs(left.height-right.height)<=1 and left.balanced and right.balanced ){
        p.balanced=true;
    }
    else{
        p.balanced=false;
    }
    return p;
}

int main(){
    node* root=buildTree();
    print(root);
    cout<<endl;
    if(isHeightBalanced(root).balanced){
        cout<<"Balanced tree."<<endl;
    }
    else{
        cout<<"Not Balanced tree."<<endl;
    }

    return 0;
}