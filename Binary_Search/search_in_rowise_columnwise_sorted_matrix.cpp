/*
    we have to search an element in array 2-D
    2D matrix is rowise and column wise sorted

    we should take care of array bound condition
        (i>=0 && i<n) and (j>=0 && j<m)


Enter number of column and row : 3 3
Enter numbers in array : 3 30 38
44 52 54
57 60 69
key need to search :44
key is at : 1,0    
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> search_2d_matrix(int n,int m,int arr[][100],int key){
    vector<int>ans(2,-1);
    int i=0,j=m-1;

    //Array bound condition
    while((i>=0 and i<n)and(j>=0 and j<m)){
        if(arr[i][j]==key){
            ans[0]=i;
            ans[1]=j;
            return ans;
        }
        else if(arr[i][j]>key){
            j--;
        }
        else if(arr[i][j]<key){
            i++;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cout<<"Enter number of column and row : ";
    cin>>n>>m;

    int arr[n][100];
    cout<<"Enter numbers in array : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int key;
    cout<<"key need to search :";
    cin>>key;
    vector<int>ans=search_2d_matrix(n,m,arr,key);

    cout<<"key is at : "<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}

// { Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// //User function template for C++
// class Solution
// {
// public:
//     int matSearch(vector<vector<int>> &arr, int N, int M, int X)
//     {
//         // your code here
//         int i = 0, j = M - 1;

//         //Array bound condition
//         while ((i >= 0 && i < N) && (j >= 0 && j < M))
//         {
//             if (arr[i][j] == X)
//             {
//                 return 1;
//             }
//             else if (arr[i][j] > X)
//             {
//                 j--;
//             }
//             else if (arr[i][j] < X)
//             {
//                 i++;
//             }
//         }
//         return 0;
//     }
// };

// // { Driver Code Starts.

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> arr(n, vector<int>(m));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             cin >> arr[i][j];

//     int x;
//     cin >> x;
//     Solution ob;
//     cout << ob.matSearch(arr, n, m, x) << endl;
// }