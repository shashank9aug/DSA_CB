/*
    what we can do : 
        - print the lcs and its length 
        - length of shortest coomon supersequence=(m+n)-(length(lcs));
    But We have to print the superSequence :
        -     


KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Love_450/Dynamic_Programming/LCS (master)
$ ./a.exe
abac
cab
cabac

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    string printLCS(string x,string y,int n,int m,vector<vector<int>>dp){
        //Initialization :
        for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0 or j==0) dp[i][j]=0;
            else if(x[i-1]==y[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        string ans;
        ans.clear();
        int i=n,j=m;
        while(i>0 and j>0){
            if(x[i-1]==y[j-1]){
                ans.push_back(x[i-1]);        
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans.push_back(x[i-1]);
                i--;
            } 
            else{
                ans.push_back(y[j-1]);
                j--;
            } 
        }
        while(i>0){
            ans.push_back(x[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(y[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1=str1.length(),l2=str2.length();
        
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        
        return printLCS(str1,str2,l1,l2,dp);
    }
};



int main(){
    string x,y;
    cin>>x>>y;

    Solution s;
    cout<<s.shortestCommonSupersequence(x,y)<<endl;

    return 0;
}