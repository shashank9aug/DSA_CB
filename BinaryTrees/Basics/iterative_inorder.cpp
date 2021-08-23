/*
$ ./a.exe
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
1, 10, 9, 6, 7, 8, 3, 13, 14,
*/

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

void inorderTraversal(node*root){
    stack<node*>st;
    //store node in temp node
    node*temp=root;

    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp=temp->left;
            // cout<<temp->data;
        }
        else{
            if(st.empty()==true){
                break;
            }
            temp=st.top();
            st.pop();
            cout<<temp->data<<", ";
            temp=temp->right;
        }
    }

}


int main(){
    node* root=buildTree();

    inorderTraversal(root);
}