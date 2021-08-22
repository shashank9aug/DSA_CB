#include<iostream>
#include<queue>
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

void bfs(node*root){
    queue<node*>q;

    q.push(root);

    while(!q.empty()){
        node*f=q.front();
        cout<<f->data<<", ";
        q.pop();

        //check left child 
        if(f->left){
            q.push(f->left);
        }

        //check right child
        if(f->right){
            q.push(f->right);
        }
    }

    return;
}

node* buildBalanceBT(int arr[],int start,int end){
    //Base case :
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    node* root=new node(arr[mid]);
    //Recurssive case :
    root->left=buildBalanceBT(arr,start,mid-1);
    root->right=buildBalanceBT(arr,mid+1,end);

    return root;    
}


int main(){
    // node* root=buildTree();
    int arr[]={1,2,3,4,5,6,7};
    int n=7;
    node* root=buildBalanceBT(arr,0,n-1);
    bfs(root);
    
}