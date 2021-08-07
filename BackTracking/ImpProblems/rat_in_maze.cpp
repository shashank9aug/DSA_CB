/*
    Given N*M matrix with some cells blocked : 
    find : 
    - find the path from src to dest.
    - count the no of path from src to dest.
    - print all the possible paths.

*/

#include <iostream>
#include <vector>
using namespace std;

bool ratInMaze(char maz[10][10], int ans[][10], int i, int j, int m, int n)
{
    //Base case :
    if (i == m and j == n)
    {
        //mark the step :
        ans[m][n] = 1;

        //print the path :
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    //rec case :
    //Rat should be inside grid :
    if (i > m or j > n)
    {
        return false;
    }

    //shell must be unblocked :
    if (maz[i][j] == 'X')
    {
        return false;
    }

    //Assume : solution exists through current shell.
    ans[i][j] = 1;

    //check for right side :
    bool right = ratInMaze(maz, ans, i, j + 1, m, n);
    bool down = ratInMaze(maz, ans, i + 1, j, m, n);

    //Backtrack :
    ans[i][j] = 0;

    if (right or down)
    {
        return true;
    }
    return false;
}

int main()
{
    char maz[10][10] = {"0000",
                        "00X0",
                        "000X",
                        "0X00"};
    int ans[10][10] = {0};
    int m = 4, n = 4;
    bool sol = ratInMaze(maz, ans, 0, 0, m - 1, n - 1);

    if (!sol)
    {
        cout << "Path doen't exist.";
    }

    return 0;
}