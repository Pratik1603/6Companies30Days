#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>&v,int n,int r,int k){
        if(k==0){
            if(n==0){
                result.push_back(v);
            }
            return;
        }
        for(int i=r;i<=9;i++){
            v.push_back(i);
            solve(v,n-i,i+1,k-1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        solve(v,n,1,k);
        return result;
    }
};
