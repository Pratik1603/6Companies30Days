#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            dp[0]+=(i*nums[i]);
         
        } 
        int ans=dp[0];
       
        int ind=n-1;
        for(int i=1;i<nums.size();i++){
            dp[i]=sum+dp[i-1]-(n*nums[ind]);
            ind--;
            ans=max(dp[i],ans);
        }
        return ans;
    }
};