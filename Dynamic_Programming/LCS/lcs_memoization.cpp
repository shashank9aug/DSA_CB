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
    if (n == 0 || m == 0)
        return 0;
        
    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n - 1] == s2[m - 1])
        return dp[n][m] = 1 + maxLen(s1, s2, n - 1, m - 1);
    else
        return dp[n][m] = max(0 + maxLen(s1, s2, n - 0, m - 1), 0 + maxLen(s1, s2, n - 1, m - 0));
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