/*
    Sort an given array recurssively : 

    Approach : IBH or Desicion  
        IBH : BC then Hypothesis at the end Induction
        Desicion : Recurssive tree it will represent our desicions    

*/


#include<iostream>
#include<vector>
using namespace std;

void insertInRec(vector<int>&v,int temp){
    //Base case : 
    if(v.size()==0 or temp>=v[v.size()-1]){
        v.push_back(temp);
        return;
    }

    //else 
    int val=v[v.size()-1];
    v.pop_back();
    insertInRec(v,temp);
    v.push_back(val);
}

void sortAnArray(vector<int> &v){
    //Base case: 
    if(v.size()==1){
        return;
    }

    //Hypothesis : 
    int temp=v[v.size()-1];
    v.pop_back();
    sortAnArray(v);
    insertInRec(v,temp);

    // for(int i=0;i<v.size()-1;i++){
    //     cout<<v[i]<<", ";
    // }
}

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    vector<int>v;
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }

    sortAnArray(v);

    for(int i=0;i<n;i++){
        cout<<v[i]<<",";
    }

    return 0;
}