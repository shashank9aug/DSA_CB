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
#include<string>
using namespace std;

int LCS(string x,string y,int n,int m){
    //Base case :
    if(n==0 or m==0){
        return 0;
    }

    //Choice diagram :
    if(x[n-1]==y[n-1]){
        return 1+LCS(x,y,n-1,m-1);
    }

    //smaller input :
    return max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
}

int main(){
    string x,y;
    cin>>x>>y;

    int n=x.size()-1;
    int m=y.size()-1;

    cout<<"LCS lenght : "<<LCS(x,y,n,m)<<endl;

    return 0;
}