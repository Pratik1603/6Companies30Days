#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        int length=INT_MAX;
        int n=1e6+2;
        vector<int> adj[n];
        for(int i=0;i<cards.size();i++){
            adj[cards[i]].push_back(i);
        }
        for(auto &it:adj){
            if(it.size()>=2){
                vector<int> ans=it;
                for(int i=0;i<ans.size()-1;i++){
                    length=min(length,ans[i+1]-ans[i]+1);
                }
            }
        }
        if(length==INT_MAX) return -1;
        
        return length;
    }
};