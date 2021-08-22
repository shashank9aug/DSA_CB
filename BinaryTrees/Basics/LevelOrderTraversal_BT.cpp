/*
$ ./a.exe
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Height of BT : 4

----Time complexity---
worst case : O(N^2)

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

//Height of tree : 
int heightBT(node*root){
    if(root==NULL){
        return 0;
    }

    int ls=heightBT(root->left);
    int rs=heightBT(root->right);

    return max(ls,rs)+1;
}


void printKthLevel(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }

    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);

    return;
}

void printAllLevels(node*root){
    int H=heightBT(root);

    for(int i=1;i<=H;i++){
        printKthLevel(root,i);
        // cout<<endl;
    }
    return;
} 


int main(){
    node* root=buildTree();

    cout<<"Height of BT : "<<heightBT(root)<<endl;

    cout<<"Kth level nodes : ";
    printKthLevel(root,3);
    cout<<endl;

    cout<<"All level nodes : ";
    printAllLevels(root);

    return 0;
}