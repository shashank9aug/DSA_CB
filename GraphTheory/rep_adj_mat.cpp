/*
It's Inefficient approach in case of space complexity if input is large eg: 10^5 or 10^7
*/

#include<iostream>
using namespace std;

int main(){
    int n,m;        //no of nodes and edges
    cin>>n>>m;

    int adj[n+1][n+1];  //matrix of nodes as row and col =>

    //Edges as input :
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    return 0;
}