/*
$ ./a.exe
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
8, 10, 3, 1, 6, 14, 9, 7, 13,

*/

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


int main(){
    node* root=buildTree();

    bfs(root);

}