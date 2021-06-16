// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    stack<char>st;
    bool ispar(string )
    {
        // Your code here
        if(s.size()%2!=0){
            return false;
        }
        else{
            for(auto i : x)
            {
                if(i == '(')
                    s.push(')');
            else if(i == '{')
                 s.push('}');
            else if(i == '[')
                 s.push(']');
            else if( s.empty() || s.top() != i)
                 return false;
            else if(s.top() == i)
                 s.pop();
            
            }
        }
        return s.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends