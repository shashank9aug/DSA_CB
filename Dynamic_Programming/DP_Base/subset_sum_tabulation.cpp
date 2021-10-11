/*
    Subset sum problem :  Variation of Knapsack-0/1

    we have given no in array and sum we have to return True if subset exist 
    else false.

N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

Approach : 
- Memoization = Recurssion + storing value 
- Tabulation 

*/


//Tabulation approach : 
#include<iostream>
using namespace std;

bool subset_sum(int arr[], int sum, int n)
{
    bool t[n + 1][sum + 1];

    //Initialization : 
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = true;
    }    
    for (int i = 1; i <= sum; i++)
    {
        t[0][i] = false;
    }

    //Smaller Input : 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    if (subset_sum(arr, sum, n))
        cout << "Subset is possible";
    else
        cout << "Subset not possible";
    return 0;
}