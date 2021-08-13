#include <iostream>
#include <vector>
using namespace std;

template<typename T,typename U>
class Stack{
private:
    vector<T> v;    
    vector<U> v1;    
public:
    void push(T data,U data1){
        v.push_back(data);
        v1.push_back(data1);
    }
    bool empty(){
        return v.size()==0;
    }
    void pop(){
        if(!empty()){
             v.pop_back();
             v1.pop_back();
        }
    }
    T top(){
        return v[v.size()-1] ;
    }
};

int main() {
    //T : typename we want to take 
    // Stack<int> s;
    Stack<char,int> s;

    for(int i=65;i<=70;i++){
        s.push(i,i);
    }
    // for(int i=1;i<=5;i++){
    //     s.push(i*i);
    // }
    //Try to print the content of the stack by popping each element
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    

return 0;
}