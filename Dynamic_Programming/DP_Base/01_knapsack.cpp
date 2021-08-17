/*

    we have given (knapsack : Bag) which have max weight it can contain.
    we have to maximize thr profit earned by putting items in bag.

    ip : wt[],val[]
        w : max weight bag can carry.

    Approach : 
    DP : i) : Recurssion + Memoization
        ii) : Top Down. ()  


    DP : Recurssion + storing results
    we divide problems into sub problems and storing its results for future problems
    if that sub problem will repeat we will simply use our previous results 
    
    - it helps us to reduce repeatetive calculation which we were doing in recurssion or backtracking
    - In back tracking we were checking each and every possible solution to get result
      and if we will not get the result we will backtrack 
    - But in DP we will store each step to avoid repeating step to execute.    
*/


#include<iostream>
#include<cstring>
#include<algorithm>
#include<mem.h>
using namespace std;

//Memoize code : 
/*                -------Recurssive code--------
int knapsack(int wt[],int val[],int w,int n){
    //Base case : when w(max weight) will be zero or no of items will be zero
    if(n==0 or w==0){
        return 0;
    } 

    //Recurssive case : we have choices to put item in bag or not so recurssion is possible
    if(wt[n-1]<=w){
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w){
        return knapsack(wt,val,w,n-1);
    }

}
*/
/*           -----------Recurssion + Memoization----------            

memeset(assignement , 0/-1, sizeof(datastructure)) : We can use memset() to set all values as 0 or -1 for integral data types also.
It will not work if we use it to set as other values. 
The reason is simple, memset works byte by byte.


*/

// size will be determined by constraints.
int static t[1002][1002];

int knapsack(int wt[],int val[],int w,int n){
    if(n==0 or w==0){
        return 0;
    }

    //if result calculated previously or not 
    if(t[n][w] != -1){
        return t[n][w];
    }

    if(wt[n-1]<=w){
        return t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    
    else{
        return t[n][w]=knapsack(wt,val,w,n-1);
    }
}

/*int knapsack(int val[], int wt[], int n, int w)
{
    if(n == 0 || w == 0)
        return 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    if(wt[n-1] <= w)
    {
        return dp[n][w] = max(val[n-1] + knapsack(val, wt, n-1, w-wt[n-1]),
                        knapsack(val, wt, n-1, w));
    }
    else
        return dp[n][w] = knapsack(val, wt, n-1, w);
}*/

int main(){
    memset(t,-1,sizeof(t));

    int n;
    cout<<"No of items : ";
    cin>>n;

    int wt[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int val[n];
    cout<<"Enter value of items : ";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int w;
    cout<<"Enter Max weight : ";
    cin>>w;

    cout<<"Maximum profit : "<<knapsack(wt,val,w,n)<<endl;

    return 0;
}