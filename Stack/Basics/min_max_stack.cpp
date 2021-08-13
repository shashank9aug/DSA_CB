#include <iostream>
#include <vector>
using namespace std;

class stack
{
    vector<int> st;
    vector<int> min_st;
    vector<int> max_st;

public:
    void push(int data){
        int current_min=data;
        int current_max=data;

        //their is atleast any element in stack
        if(min_st.size()){
            current_min=min(min_st[min_st.size()-1],data);
            current_max=max(max_st[max_st.size()-1],data);
        }

        min_st.push_back(current_min);
        max_st.push_back(current_max);

        st.push_back(data);
    }
    
    int top(){
        return st[st.size()-1];
    }

    int getMin(){
        return min_st[min_st.size()-1];
    }

    int getMax(){
        return max_st[max_st.size()-1];
    }

    //pop from 3 of them
    void pop(){
        min_st.pop_back();
        max_st.pop_back();
        st.pop_back();
    }

    bool isEmpty(){
        return st.size()==0;
    }

};

int main()
{
    stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"Max : "<<s.getMax()<<endl;
    s.pop();
    cout<<"Top : "<<s.top()<<endl;
    cout<<"Min : "<<s.getMin()<<endl;
    cout<<"Max : "<<s.getMax()<<endl;

    s.pop();
    s.pop();
    cout<<"Top : "<<s.top()<<endl;
    cout<<"Max : "<<s.getMax()<<endl;

    return 0;
}