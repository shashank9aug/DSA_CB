/*
    reverse stack  : 
        - using another stack 
        - using array/ another DS
*/

//using only one stack :

#include <iostream>
#include <stack>
using namespace std;

void transfer(stack<int> &s, stack<int> &s1, int n)
{
    for (int i = 0; i < n; i++)
    {
        s1.push(s.top());
        s.pop();
    }
}

void reverseStack(stack<int> &s)
{
    //helper stack :
    stack<int> s1;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        //pick the element from top and insert at bottom :
        int x = s.top();
        s.pop();

        //transfer n-i-1 element from s to s1;
        transfer(s, s1, n - i - 1);
        //insert the element x in the stack s1;
        s.push(x);
        //transfer n-i-1 element from s1 to s;
        transfer(s1, s, n - i - 1);
    }
}

int main()
{
    stack<int> s;

    // for(int i=1;i<=5;i++){
    //     s.push(i);
    // }
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"Stack before reverse : 5 4 3 2 1 "<<endl;

    reverseStack(s);
    cout<<"Stack after reverse : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
