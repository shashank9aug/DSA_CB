/*
    -------Min subset sum-----------
    Given arr[] = {1,6,11,5};
    op : 1;

    we have to calculate range of sum each subset can have : Range +=arr[i=0 to n]; 

    we have two group of ranges in vector;
    abs(s1,s2) = minimize

*/

#include<iostream>
#include<numeric>
#include<climits>
#include<vector>
using namespace std;


vector<int> subset_sum(vector<int>arr, int n, int range)
{
    int t[n+1][range+1];
    vector<int>check;
    //Initialization : 
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = true;
    }    
    for (int i = 1; i <= range; i++)
    {
        t[0][i] = false;
    }

    //Smaller Input : 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= range; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    for(int i=0;i<=range;i++){
        for(int j=0;j<=range;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=n;i<n+1;i++){
        for(int j=0;j<=range/2;j++){
            if(t[i][j]==1){
                //j->sum (possible sum)
                check.push_back(j);
            }
        }
    }

    return check;
}



int main(){
    int n;
    cin>>n;

    vector<int>vec;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        vec.push_back(d);
    }
    int range=accumulate(vec.begin(),vec.end(),0);
    vector<int>check=subset_sum(vec,n,range);
    int ans=0;
    int mn=INT_MAX;
    for(int i=0;i<check.size();i++){
        mn=min(mn,range-(2*check[i]));
    }
    cout<<mn<<endl;
    return 0;
}

