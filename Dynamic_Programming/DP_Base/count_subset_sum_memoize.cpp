/*

$ ./a.exe
4
1 2 3 3
6
3

*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> memo;
int Solve(int arr[], int n, int index, int sum){
    if(sum == 0){
        return 1;
    }
    if(index >= n || sum < 0){
        return 0;
    }
    if(memo[index][sum] != -1){
        return memo[index][sum];
    }
    return memo[index][sum] = Solve(arr, n, index+1, sum-arr[index]) + Solve(arr, n, index+1, sum);
}
int countSubsetSum(int N, int arr[], int sum){
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

    cout<<countSubsetSum(n,arr,sum)<<endl;
    return 0;
}
