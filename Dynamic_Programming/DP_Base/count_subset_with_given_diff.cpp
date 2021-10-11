/*
$ ./a.exe
4
1      
1 1 2 3
3

*/



#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int countSubsetSum(vector<int>arr, int sum, int n)
{
    int t[n + 1][sum + 1];

    //Initialization : 
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }    
    for (int i = 1; i <= sum; i++)
    {
        t[0][i] = 0;
    }

    //Smaller Input : 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    // for(int i=0;i<(n+1);i++){
    //     for(int j=0;j<(sum+1);j++){
    //         cout<<t[i][j]<<", ";
    //     }
    //     cout<<endl;
    // }

    return t[n][sum];
}


int main(){
    int n;
    cin>>n;

    int diff;
    cin>>diff;
    
    vector<int>vec;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        vec.emplace_back(d);
    }
    
    int svec=accumulate(vec.begin(),vec.end(),0);
    int sum=(diff+svec)/2;

    cout<<countSubsetSum(vec,sum,n)<<endl;

    return 0;
}