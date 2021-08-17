#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int t[1001][1001];

    int knapsackCal(int W, int wt[], int val[], int n)
    {
        //Base condition :
        if (W == 0 or n == 0)
        {
            return 0;
        }

        if (t[n][W] != -1)
        {
            return t[n][W];
        }

        if (wt[n - 1] > W)
        {
            return t[n][W] = knapsackCal(W, wt, val, n - 1);
        }

        return t[n][W] = max(val[n - 1] + knapsackCal(W - wt[n - 1], wt, val, n - 1), knapsackCal(W, wt, val, n - 1));
    }

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        memset(t, -1, sizeof(t));

        return knapsackCal(W, wt, val, n);
    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases

    //reading number of elements and weight
    int n, w;
    cin >> n >> w;

    int val[n];
    int wt[n];

    //inserting the values
    for (int i = 0; i < n; i++)
        cin >> val[i];

    //inserting the weights
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    Solution ob;
    //calling method knapSack()
    cout << ob.knapSack(w, wt, val, n) << endl;

    return 0;
}