#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int>v;
    bool minHeap;

    bool compare(int a,int b){
        if(minHeap){
            return a<b;
        }
        else{
            return a>b;
        }
    }

public:

    Heap(int default_size=10,bool type=true){
        v.reserve(default_size);
        //block the 0th index
        v.push_back(-1);
        minHeap=type;
    }

    void push(int d){
        v.push_back(d);
        int idx=v.size()-1;
        int parent=idx/2;

        /*
            keep pushing to the top untill we reached a root node or stop at midway
            because current element is greater than parent.
        */

        while(idx>1 and compare(v[idx],v[parent])){
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }

    int top(){
        return v[1];
    }

    bool empty(){
        return v.size()==1;
    }

};

int main(){
}