//paranthesis checker

//Basically stack problem 

//Question uses : {} or [] or ()

//only push 

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    stack<char>s;
    bool ispar(string x)
    {
        // Your code here
        if(x.size()%2!=0){
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

int main()
{
   int t;
   string a;
   cout<<"Enter the number of test cases : "; 
   cin>>t;
   while(t--)
   {
       cout<<"Enter the input parantheses string : ";
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  