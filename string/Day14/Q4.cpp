// Input:
// S = "}{{}}{{{"
// Output: 3
// Explanation: One way to balance is:
// "{{{}}{}}". There is no balanced sequence
// that can be formed in lesser reversals.

#include <bits/stdc++.h>
using namespace std;

int countRev(string s);
int main()
{
    string s;
    cin >> s;
    cout << countRev(s) << '\n';
}

// T.C : O(N) and S.C : O(N)
/*
int countRev (string s)
{
    // your code here
    int size = s.size();
    stack<char>st;  
    int count=0;
    if(size%2==0){
        for(int i=0;i<size;i++){
            if(s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(!s.empty()){
                    st.pop();   
                }
                else{
                    st.push('{');
                    count++;
                }
            }
        }
        if(st.size()==0){
            return count;
        }
        else if(st.size()!=0){
            return count + (st.size()/2);
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
}
*/

//T.c : O(N)  S.C : O(1)

int countRev(string s)
{
    int count = 0, ans = 0;
    if (s.size() % 2 != 0)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{')
            {
                count++;
            }
            else
            {
                if (!count)
                {
                    ans++;
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        return ans + count / 2;
    }
}