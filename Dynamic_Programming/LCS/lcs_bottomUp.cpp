/*

KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Love_450/Dynamic_Programming/LCS (master)
$ ./a.exe
shashank
shekhar
LCS lenght : 4

KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Love_450/Dynamic_Programming/LCS (master)
$ ./a.exe
shashank
shashank
LCS lenght : 8

*/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int dp[1000 + 1][1000 + 1];
    
int maxLen(string& s1, string& s2, int n, int m)
{
    //Initialization :
    for(int i=0;i<n+1;i++)
    for(int j=0;j<m+1;j++)        
    {
        if(i==0 or j==0){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    for(int j=1;j<m+1;j++)
    {
        if (s1[i - 1] == s2[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
        else
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
    return dp[n][m];    
}
        
int main(){
    string x,y;
    cin>>x>>y;

    int n=x.length();
    int m=y.length();
    memset(dp,-1,sizeof(dp));    
    cout<<"LCS lenght : "<<maxLen(x,y,n,m)<<endl;

    return 0;
}