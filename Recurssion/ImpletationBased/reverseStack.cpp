/*
    Reversing a stack can be done in two approach : 
        i) : without any extra space.
        ii) : with extra space. 

*/

#include <iostream>
#include <stack>
using namespace std;

void insertInStack(stack<int> st, int ele)
{
    //Base case :
    if (st.size() == 0)
    {
        st.push(ele);
        return;
    }

    //Hypothesis :
    int temp = st.top();
    st.pop();
    insertInStack(st, ele);
    st.push(temp);

    return;
}

void reverseStack(stack<int> st)
{
    //Base case :
    if (st.size() == 1)
    {
        return;
    }

    //Hypothesis :
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertInStack(st, temp);
    return;
}

int main()
{
    int n;
    cin >> n;

    stack<int> st;
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        st.push(ele);
    }

    reverseStack(st);

    // for(int i=0;i<n;i++){
    //     int ans=st.top();
    //     st.pop();
    //     cout<<ans<<",";
    // }
    while (!(st.empty()))
    {

        cout << st.top() << " ";

        st.pop();
    }

    return 0;
}