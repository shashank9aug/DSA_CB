
#include <iostream>
#include <climits>
#include<cstring>
#include <algorithm>
using namespace std;

int dp[100+1][100+1];
class Solution{
private:
    int solve(int arr[],int i,int j){
        //Base case :
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int tempans=solve(arr,i,k)+solve(arr,k+1,j)+ (arr[i-1]*arr[k]*arr[j]);
            ans = min(ans,tempans);
        }
        return dp[i][j] = ans;
    }
public:
    int matrixMultiplication(int n, int arr[])
    {   
        memset(dp,-1,sizeof(dp));
 
        return solve(arr,1,n-1);
    }
};


int main(){
  
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    return 0;
}