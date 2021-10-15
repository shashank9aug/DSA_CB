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
1, 2, 3, 5, 4, 
*/

#include<bits/stdc++.h>
using namespace std;


void bfsTraversal(int n,int i,vector<int>adj[],vector<int>&bfs,vector<int>&visited){
    queue<int>q;
    q.push(i);

    visited[i]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it]=1;
            }
        }
    }
}

vector<int>bfsGraph(int n,vector<int>adj[]){
    vector<int>bfs;  //store traversed nodes
    vector<int>visited(n+1,0);      //visited array for mark the adjacent node 
    
    for(int i=1;i<=n;i++){
        //call bfs for each component
        if(!visited[i]){
            bfsTraversal(n,i,adj,bfs,visited);
        }
    }
    return bfs;
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

    vector<int>bfs=bfsGraph(n,adj);

    for(auto b:bfs) cout<<b<<", ";

    return 0;
}