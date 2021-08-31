#include<iostream>
#include<vector>
using namespace std;


void print(vector<int>v){
    for(auto x:v){
        cout<<x<<", ";
    }
    cout<<endl;   
}

//In place : O(NlogN)
void buildHeap(vector<int>&v){
    for(int i=2;i<v.size();i++){
        int idx=i;
        int parent=i/2;
        while(idx>1 and v[idx]>v[parent]){
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
}

int main(){
    //heap : 1 based indexing.
    vector<int>v{-1,10,20,5,6,1,8,9,4};
    print(v);
    buildHeap(v);
    print(v);
}