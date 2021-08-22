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


node* createBTfromTrav(int *in,int *pre,int s,int e){
    /*
    its pointer variable over array so it will back track or update in recurssion
    so it should be global or static.
    
    static variable : it will initialized only once it won't be updated on each function call
                    so, it will have same value untill function call happen
    */
    static int i=0;

    //Base case :
    if(s>e){
        return NULL;
    }

    //Rec case :
    node*root=new node(pre[i]);
    int index=-1;

    for(int j=s;s<=e;j++){
        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }

    i++;
    root->left=createBTfromTrav(in,pre,s,index-1);
    root->right=createBTfromTrav(in,pre,index+1,e);

    return root;
}


int main(){
    // node* root=buildTree();

    // print(root);

    int in[]={3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};

    int n=sizeof(in)/sizeof(int);
    node*root=createBTfromTrav(in,pre,0,n-1);

    print(root);
}