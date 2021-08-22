/*
$ ./a.exe
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
8 10 1 6 9 7 3 14 13 
Diameter : 6

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

int height(node*root){
    if(root==NULL){
        return 0;
    }

    int ls=height(root->left);
    int rs=height(root->right);

    return max(ls,rs)+1;
}


// Time complexity for calculating Diameter : O(N^2)  
int diameter(node*root){
    if(root==NULL){
        return 0;
    }

    //case-1: height of left and right subtree along with node 
    int h1=height(root->left);
    int h2=height(root->right);

    int op1=h1+h2;

    //diameter of left subtree separate : 
    int op2=diameter(root->left);

    //diameter of right subtree separate : 
    int op3=diameter(root->right);

    return max(op1,max(op2,op3));
}

//define class Pair : or also available in stl  
class Pair{
public:
    int height;
    int diameter;    
};

//O(N)
Pair fastdiameter(node*root){
    Pair p;
    if(root==NULL){
        p.diameter=p.height=0;
        return p;
    }

    Pair left = fastdiameter(root->left);

    Pair right = fastdiameter(root->right);

    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height , max(left.diameter,right.diameter));

    return p; 
}


int main(){
    node* root=buildTree();

    // print(root);
    // cout<<endl;

    // cout<<"Diameter : "<<diameter(root)<<endl;

    Pair p=fastdiameter(root);
    cout<<"Height : "<<p.height<<endl;
    cout<<"Diameter : "<<p.diameter<<endl;

    return 0;
}