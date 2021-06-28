//Wildcard string matching

// * --> Matches with 0 or more instances of any 
// character or set of characters.
// ? --> Matches with any one character.

// Input: wild = ge*ks
//        pattern = geeks
// Output: Yes
// Explanation: Replace the '*' with 'e' to obtain 
// the string.

//showing error now

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool match(string wild, string pattern)
    {
        // code here
        for(int i=0;i<wild.size();i++){
            if(wild[i]=='*' or wild[i]=='?'){
                if(i==wild.size()-1){
                    wild.insert(i,pattern.substr(i,pattern.size()-1));
                }
                else{
                    wild[i]=pattern[i];
                }
            }
        }
        
        
        if(wild.compare(pattern)){
            return false;
        }
        else{
            return true;
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
