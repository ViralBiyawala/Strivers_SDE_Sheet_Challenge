#include <bits/stdc++.h> 

typedef vector<int> v;

vector<pair<pair<int,int>,int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,vector<vector<int>>>adj;
    for(auto it:g) {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool>vis(n+1,false);
    vector<pair<pair<int,int>,int>>ans;
    // v = {weight,source,destination}
    priority_queue<v,vector<v>,greater<v>>q;
    q.push({0,-1,1});
    while(!q.empty()) {
        auto node=q.top();
        q.pop();
        int weight=node[0],source=node[1],destination=node[2];
        if(vis[destination]) {
            continue;
        }
        vis[destination]=true;
        if(source!=-1) {
            ans.push_back({{source,destination},weight});
        }
        for(auto it:adj[destination]) {
            if(!vis[it[0]]) {
                q.push({it[1],destination,it[0]});
            }
        }
    }
    return ans;
}