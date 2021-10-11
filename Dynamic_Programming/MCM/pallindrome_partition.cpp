/*
KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Love_450/Dynamic_Programming/MCM (master)
$ ./a.exe
ababbbabbababa
3
*/
#include <bits/stdc++.h>
using namespace std;

int dp[100+1][100+1];
class Solution{
private:
    bool isPallindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    int solve(string s,int i,int j){
        //Base case:
        if(i>=j){
            return 0;
        }
        
        if(isPallindrome(s,i,j)==true){
            return 0;
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int tempAns = 1 + solve(s,i,k) + solve(s,k+1,j);
            
            ans=min(ans,tempAns);
        }
        return dp[i][j] = ans;
    }
};

// { Driver Code Starts.

int main(){
 
        string str;
        cin>>str;
        memset(dp,-1,sizeof(dp));
        Solution ob;
        cout<<ob.solve(str,0,str.length()-1,dp)<<"\n";
    return 0;
}  // } Driver Code Ends