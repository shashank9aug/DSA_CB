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

//case 1 : print subtree nodes below the target node 
void printSubtreeNodes(node*root,int k){
    //Base case :
    if(root==NULL){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

//case 2 : 
int printNodesAtK(node*root,node*target,int k){
    //base case : node is not present
    if(root==NULL){
        return -1;
    }

    //reach the target node :
    if(root==target){
        printSubtreeNodes(target,k);
        return 0;
    }
    
    //next step : ancestor node
    int DL=printNodesAtK(root->left,target,k);

    if(DL!=-1){
        //target node present in left subtree.
        // their are two cases :
        //i): Ancestor itself.  ii): Go to the right ancestor.

        if(DL+1==K){
            //print ancestor itself
            cout<<root->data<<" ";
        }

        else{
            printSubtreeNodes(root->right,k-2-DL);
        }

        return 1+DL;
    }

    int DR=printNodesAtK(root->right,target,k);
    if(DR!=-1){
        if(DR+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->left,k-2-DR);
        }
        //return distance of target node to the parent 
        return 1+DR;
    }
    //node was not present in left and right subtree : 
    return -1;
}

int main(){
    node* root=buildTree();

    print(root);
    cout<<endl;

    


}