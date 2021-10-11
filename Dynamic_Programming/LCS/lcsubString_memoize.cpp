/*

$ ./a.exe
shashank
shaseeee
LCS lenght : 4

KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Love_450/Dynamic_Programming/LCS (master)
$ ./a.exe
shekhar
shekhar
LCS lenght : 7

KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Love_450/Dynamic_Programming/LCS (master)
$ ./a.exe
sahaisingh
sahapsingh
LCS lenght : 5

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int LCS(string &x,string &y,int n,int m,int ans,vector<vector<int>>&dp){
    //Base case :
    if(n==0 or m==0){
        return dp[n][m] = ans;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    //Choice diagram :
    if(x[n-1]==y[m-1]){
        ans = LCS(x,y,n-1,m-1,ans+1,dp);
    }

    //smaller input : making new substring as we get unmatch chars 
    return dp[n][m] = max(ans,max(LCS(x,y,n,m-1,0,dp),LCS(x,y,n-1,m,0,dp)));
}

int main(){
    string x,y;
    cin>>x>>y;

    int n=x.length();
    int m=y.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<"LCS lenght : "<<LCS(x,y,n,m,0,dp)<<endl;

    return 0;
}