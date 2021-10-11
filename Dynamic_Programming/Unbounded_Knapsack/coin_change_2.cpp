/*
Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int count(int coin[], int n, int sum) {
        // Initialization :
        
        long long int t[n+1][sum+1];
        t[0][0]=0;
        for(int i=1;i<sum+1;i++){
            t[0][i]=INT_MAX-1;
        }
        for(int i=1;i<sum+1;i++){
            if(i%coin[0]==0){
                t[1][i]=i/coin[0];
            }
            else{
                t[1][i]=INT_MAX-1;
            }
        }
        for(int i=0;i<n+1;i++){
            t[i][0]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(coin[i-1]<=j){
                    t[i][j]=min(t[i][j-coin[i-1]]+1,t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        if (t[n][sum] == INT_MAX - 1){
            return -1;
        }
        return t[n][sum];
    }

    // for(int i=0;i<=n;i++){
	//     for(int j=0;j<=sum;j++){
	//         if(j==0) t[i][j] = 0;
	//         else if(i==0)
    //             t[i][j] = INT_MAX-1;
    //         else if(coin[i-1] <= j){
	//             t[i][j] = min(1+t[i][j-coin[i-1]],t[i-1][j]);
	//         }
	//         else t[i][j] = t[i-1][j];
	//     }
	// }
	// if (t[n][sum] == INT_MAX - 1)
    //     return -1;
	    
	// return t[n][sum];
    // }
};

int main() {
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution ob;
    cout << ob.count(arr, n, sum) << endl;

    return 0;
} 