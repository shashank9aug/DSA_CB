/*
    Sort an given Stack recurssively : 

    Approach : IBH or Desicion  
        IBH : BC then Hypothesis at the end Induction
        Desicion : Recurssive tree it will represent our desicions    

*/


#include<iostream>
#include<stack>
using namespace std;

void insertInRec(stack<int>&st,int temp){
    //Base case : 
    if(st.size()==0 or st.top()<=temp){
        st.push(temp);
        return;
    }

    //else 
    int val=st.top();
    st.pop();
    insertInRec(st,temp);
    st.push(val);
}


void sortAnStack(stack<int> &st){
    //Base case: 
    if(st.size()<=1){
        return;
    }

    //Hypothesis : 
    int temp=st.top();
    st.pop();
    sortAnStack(st);
    insertInRec(st,temp);

    // for(int i=0;i<v.size()-1;i++){
    //     cout<<v[i]<<", ";
    // }
}



int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    stack<int>st;
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        st.push(k);
    }

    sortAnStack(st);

    // printStack(st);

    for(int i=0;i<n;i++){
        int x=st.top();
        st.pop();
        cout<<x<<",";
    }

    return 0;
}

