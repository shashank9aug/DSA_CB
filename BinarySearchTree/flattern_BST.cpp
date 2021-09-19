/*
$ ./a.exe
5 3 6 1 7 8 -1

1,3,5,6,7,8,
5,
3,6,
1,7,
8,

1 --> 3 --> 5 --> 6 --> 7 --> 8 -->

*/

#include <iostream>
#include<queue>
#include<climits>
using namespace std;

//node of BST
class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

//Accepts the old root node & data and returns the new root node 
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    // node->data <= root->data  goes left side.  
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }

    // node->data > root->data  goes right side.  
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}

//Print the BST Level By Level
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

//Inorder Print : Always sorted.
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}

class LinkedList{
public:
    node*head;
    node*tail;
};

LinkedList flattern(node*root){
    LinkedList l;

    //sigle node in BST
    if(root==NULL){
        l.head=l.tail=root;
        return l;
    }

    //leaf node in recurssive call:
    if(root->left==NULL and root->right==NULL){
        l.head=l.tail=root;
        return l;
    }

    //left  is not null
    if(root->left!=NULL and root->right==NULL){
        LinkedList leftLL=flattern(root->left);
        leftLL.tail->right=root;

        l.head=leftLL.head;
        l.tail=root;
        return l;
    }

    //right is not null
    if(root->left==NULL and root->right!=NULL){
        LinkedList rightLL=flattern(root->right);
        root->right=rightLL.head;

        l.head=root;
        l.tail=rightLL.tail;

        return l;
    }

    //Both sides are not null
    LinkedList leftLL=flattern(root->left);
    LinkedList rightLL=flattern(root->right);

    leftLL.tail->right=root;
    root->right=rightLL.head;

    l.head=leftLL.head;
    l.tail=rightLL.tail;

    return l;
}


int main(){ 
    node*root = build();
    inorder(root);
    cout<<endl;
    bfs(root);
    cout<<endl;

    LinkedList l= flattern(root);
    node*temp=l.head;

    while(temp!=NULL){
        cout<<temp->data<<" --> ";
        temp=temp->right;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    return 0;
}