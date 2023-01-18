#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct cmp {
        bool operator () (const pair<int, string>& a, const pair<int, string>& b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        vector<string>ans;
        for(auto words:words){
          mp[words]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto i:mp){
          pq.push(make_pair(i.second,i.first));
        }
        while(k--){
          auto temp=pq.top();
          ans.push_back(temp.second);
           pq.pop();
        }
       
  
        return ans;
    }
};
