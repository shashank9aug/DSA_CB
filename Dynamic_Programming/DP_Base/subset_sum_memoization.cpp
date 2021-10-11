/*
-------Subset sum ----
- Memoization = Recurssion + storing prev value.

$ ./a.exe
6
3 34 4 12 5 2 
50
Subset is possible

*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> memo;
bool Solve(int arr[], int n, int index, int sum){
    if(sum == 0){
        return true;
    }
    if(index >= n || sum < 0){
        return false;
    }
    if(memo[index][sum] != -1){
        return memo[index][sum];
    }
    return memo[index][sum] = Solve(arr, n, index+1, sum-arr[index]) || Solve(arr, n, index+1, sum);
}
bool isSubsetSum(int N, int arr[], int sum){
    memo.resize(N+1, vector<int>(sum+1, -1));
    return Solve(arr, N, 0, sum);
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
    if (isSubsetSum(n,arr,sum))
        cout << "Subset is possible";
    else
        cout << "Subset not possible";
    return 0;
}
