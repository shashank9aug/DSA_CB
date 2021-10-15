#include<bits/stdc++.h>
using namespace std;

class check{
private:
    bool detectCycle(int i,int n,vector<int>adj[],vector<int>&visited){
        //create queue for BFS
        queue<pair<int,int>>q;
        visited[i]=true;
        q.push({i,-1});
        while(!q.empty()){
            int node = q.front().first;        
            int prev = q.front().second;
            q.pop();

            for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push({it,node});
                }
                else if(prev!=it){
                    return true;
                }
            }        
        }
        return false;
    }
public:
    bool isCycle(int n,vector<int>adj[]){
        vector<int>visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(detectCycle(i,n,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    check c;
    cout<<c.isCycle(n,adj)<<endl;
    return 0;
}