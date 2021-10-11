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
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int dp[1000 + 1][1000 + 1];
    
string printLCS(string& s1, string& s2, int n, int m)
{
    string ans="";

    //Initialization :
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    {
        if(i==0 or j==0){
            dp[i][j]=0;
        }
        else if(s1[i-1]==s2[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int i=n,j=m;
    while(i>0 and j>0){
        //if chars matched :
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        //chars unmatched :
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
        
int main(){
    string x,y;
    cin>>x>>y;

    int n=x.length();
    int m=y.length();
    memset(dp,-1,sizeof(dp));    
    cout<<"LCS : "<<printLCS(x,y,n,m)<<endl;

    return 0;
}