#include<iostream>
#include<stack>
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


//Iterative the tree : Preorder ( Root -> left -> Right) 
//TC : O(N) and worst case : Space complexity : O(N) 

//follow =>  root -> Right ->left
void iterativePreorder(node*root){
    if(root==NULL){
        return;
    }

    stack<node*>st;
    st.push(root);

    while(!st.empty()){
        root=st.top();
        st.pop();
        cout<<root->data<<", ";
        if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
    }
    return;
}

int main(){
    node* root=buildTree();

    iterativePreorder(root);
}