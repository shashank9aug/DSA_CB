/*
$ ./a.exe
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Target Sum : 19
8 10 1 
*/

#include<iostream>
#include<vector>
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

vector<vector<int>>ans;

void storePath(node*root,int targetSum,vector<int>&op){
    //Base case :
    if(root==NULL){
        return;
    }
    op.push_back(root->data);
    if(root->left==NULL and root->right==NULL and targetSum-root->data==0){
        ans.push_back(op);
        // op.clear();
        // return;
    }   
    // op.push_back(root->val);
    storePath(root->left,targetSum-root->data,op);
    storePath(root->right,targetSum-root->data,op);
    //Backtrack;
    op.pop_back();
}
vector<vector<int>> pathSum(node* root, int targetSum) {
    vector<int>op;
        
    storePath(root,targetSum,op);
    
    return ans;
}

int main(){
    node* root=buildTree();
    int targetSum;
    cout<<"Target Sum : ";
    cin>>targetSum;

    vector<vector<int>>path=pathSum(root,targetSum);

    for(int i=0;i<path.size();i++){
        for(int j=0;j<path[i].size();j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }

}