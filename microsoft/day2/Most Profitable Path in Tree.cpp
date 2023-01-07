#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>dist;
    vector<int>parent;
    vector<vector<int>>adj;
    void dfs(int u,int par,int dis){
        dist[u]=dis;
        parent[u]=par;
        for(auto v:adj[u]){
            if(v==par){
                continue;
            }
            dfs(v,u,dis+1);
        }
    }
    int dfs2(int u,vector<int>&amount,int parent){
        int ini=amount[u];
        int maxi=INT_MIN;
        for(auto v:adj[u]){
            if(v!=parent){
               maxi=max(maxi,dfs2(v,amount,u));
            }
        }
        if(maxi==INT_MIN){
            return ini;
        }
        else{
            return ini+maxi;
        }

    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n,vector<int>());
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        parent.resize(n);
        dist.resize(n);
        dfs(0,0,0);
        int currnode=bob;
        int bob_dist=0;
        while(currnode!=0){
            if(dist[currnode]>bob_dist){
                amount[currnode]=0;
            }
            else if(dist[currnode]==bob_dist){
                amount[currnode]=amount[currnode]/2;
            }
            currnode=parent[currnode];
            bob_dist++;
        }
        return dfs2(0,amount,0);
        return 0;
    }
};