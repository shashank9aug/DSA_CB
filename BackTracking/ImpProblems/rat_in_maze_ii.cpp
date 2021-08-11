/*
    print the possible path by which rat can escape from maze

    D -> Down
    R -> Right 
    U -> UP
    L->Left 

    Note : In this question order must be maintained D->L->R->U     
$ ./a.exe
4
1 0 0 0 
1 1 0 1
1 1 0 0
0 1 1 1

DDRDRR DRDDRR

*/

#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
using namespace std;

#define MAX = 100;

vector<string> ans;
void fun(vector<vector<int>>m, int n, string s, int i, int j)
{
    if (i < 0 || i == n || j < 0 || j == n || m[i][j] == 0)
        return;
    else if (i == n - 1 && j == n - 1)
    {
        ans.push_back(s);
        return;
    }
    else
    {
        m[i][j] = 0;
        fun(m, n, s + 'U', i - 1, j);
        fun(m, n, s + 'D', i + 1, j);
        fun(m, n, s + 'L', i, j - 1);
        fun(m, n, s + 'R', i, j + 1);
        m[i][j] = 1;
    }
}
vector<string> printPath(vector<vector<int>>m, int n)
{
    ans.clear();
    fun(m, n, "", 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
    //Your code here
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }                    

    vector<string>s=printPath(m,n);

    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }

    return 0;                    
}