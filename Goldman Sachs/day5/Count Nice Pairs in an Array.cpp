#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<long>v;
        for(int n : nums){
            string s = to_string(n);
            reverse(s.begin(),s.end());
            int x = stoll(s);
            v.push_back(n-x);
        }
        long long cnt=0;
        map<int,long long>m;
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        for(auto it:m){
           cnt += (long)(it.second*(it.second-1))/2;
        }
        return cnt%1000000007;
    }
};