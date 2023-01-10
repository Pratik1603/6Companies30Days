#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(pair<int , int> &a , pair<int , int>&b){
        return a.second < b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pair<int , int>> v;
        for(int i = 0 ; i < p.size() ; i++){
            v.push_back({p[i] ,c[i] });
        }
        sort(v.begin()  , v.end()  , cmp);
        priority_queue< int > q;
        int i = 0;
        int n = p.size();
		
        while(k--){
		
            while(i < n && v[i].second <= w){
                q.push(v[i].first);
                i++;
            }
            if(!q.empty()){
                int a = q.top();
                w += a;
                q.pop();
            }
        }
        return w;
		
    }
};
//will take only if capital exist



