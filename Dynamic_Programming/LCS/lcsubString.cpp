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
using namespace std;

int LCS(string x,string y,int n,int m,int ans){
    //Base case :
    if(n==0 or m==0){
        return ans;
    }

    //Choice diagram :
    if(x[n-1]==y[m-1]){
        ans = LCS(x,y,n-1,m-1,ans+1);
    }

    //smaller input : making new substring as we get unmatch chars 
    return max(ans,max(LCS(x,y,n,m-1,0),LCS(x,y,n-1,m,0)));
}

int main(){
    string x,y;
    cin>>x>>y;

    int n=x.size()-1;
    int m=y.size()-1;

    cout<<"LCS lenght : "<<LCS(x,y,n,m,0)<<endl;

    return 0;
}