#include <iostream>
#include <stack>
using namespace std;

void delMiddleElement(stack<int> &st,int k)
{
    //base case :
    if (st.size() == 0)
    {
        return;
    }

    if (k == 1)
    {
        st.pop();
        return;
    }

    int temp = st.top();
    st.pop();
    delMiddleElement(st, k - 1);
    st.push(temp);

    return;
}

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;

    stack<int> st;
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        st.push(ele);
    }

    cout << "Stack size : " << st.size() << endl;
    int k = (st.size() / 2) + 1;

    delMiddleElement(st, k);

    // printStack(ans);

    for (int i = 0; i < n-1; i++)
    {
        int x = st.top();
        st.pop();
        cout << x << ",";
    }
    return 0;
}