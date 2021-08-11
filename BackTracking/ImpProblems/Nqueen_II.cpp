#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n)
{
    //check for upper diagonal :
    int dupcol = col;
    int duprow = row;

    //moving upward row and col both will decrease :
    while (row >= 0 and col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    //check for the queen along the col
    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[col][row] == 'Q')
        {
            return false;
        }
        col--;
    }

    //check for the queen below diagonal
    col = dupcol;
    row = duprow;
    while (row < n and col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }

    //if we find all the direction safe
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    //base case :
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            //place the queen at safe position :
            board[row][col] = 'Q';
            //rec for other col
            solve(col + 1, board, ans, n);

            //back track :
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNqueen(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);

    //initailize it as row :
    string s(n,'.');

    for (int i = 0; i < n; i++)
    {
        //add each row '.'
        board[i] = s;
    }
    solve(0, board, ans, n);

    return ans;
}

int main()
{
    int n;
    cout << "Number of queen : ";
    cin >> n;
    vector<vector<string>> ans = solveNqueen(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}