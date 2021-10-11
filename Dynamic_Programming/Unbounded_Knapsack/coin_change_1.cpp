/*
Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int count(int coin[], int n, int sum) {
        // Initialization :
        
        long long int t[n+1][sum+1];
        for(int i=0;i<sum+1;i++){
            t[0][i]=0;
        }
        for(int i=0;i<n+1;i++){
            t[i][0]=1;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(coin[i-1]<=j){
                    t[i][j]=t[i][j-coin[i-1]]+t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++) cin >> arr[i];
    Solution ob;
    cout << ob.count(arr, m, n) << endl;

    return 0;
} 