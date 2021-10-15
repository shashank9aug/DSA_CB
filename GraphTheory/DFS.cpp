/*
KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Love_450/GraphTheory (master)
$ ./a.exe
5 7
1 2
2 4
2 3
1 3
3 4
1 5
5 3
1
*/

#include<bits/stdc++.h>
using namespace std;


void dfsTraversal(int node,vector<int>adj[],vector<int>&dfs,vector<int>&visited){
    dfs.push_back(node);
    visited[node]=1;
    for(auto it:adj[node]){
        if(visited[it]==0){
            dfsTraversal(it,adj,dfs,visited);
        }
    }
}

vector<int>dfsGraph(int n,vector<int>adj[]){
    vector<int>dfs;  //store traversed nodes
    vector<int>visited(n+1,0);      //visited array for mark the adjacent node 
    
    for(int i=1;i<=n;i++){
        //call dfs for each component
        if(!visited[i]){
            dfsTraversal(i,adj,dfs,visited);
        }
    }
    return dfs;
}


int main(){
    int n,m; 
    cin>>n>>m;

    // vector<pair<int,int>>adj[n+1];
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        // int u,v,wt;
        // cin>>u>>v>>wt;
        int u,v;
        cin>>u>>v;
        // adj[u].push_back({v,wt});
        // adj[v].push_back({u,wt});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>dfs=dfsGraph(n,adj);

    for(auto b:dfs) cout<<b<<", ";

    return 0;
}