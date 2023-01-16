#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        vector<bool>visited(n,false);
        sum=accumulate(nums.begin(),nums.end(),sum);
        if(n<k || sum%k){
            return false;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        return solve(nums,k,sum/k,0,0,visited);
    }

    bool solve(vector<int>& nums, int k,int target,int curr,int start,vector<bool>&visited){
       if(k==1){
           return true;
       }
       else if(start>=nums.size()){ //TLE AVOID
           return false;
       }
       else if(curr==target){
           return solve(nums,k-1,target,0,0,visited);
       }

           for(int j=start;j<nums.size();j++){
               if(visited[j] || curr+nums[j]>target){
                   continue;
               }
               visited[j]=true;
               if(solve(nums,k,target,curr+nums[j],j+1,visited)){
                return true;
               }
               visited[j]=false;
           }
       
       return false;
       
    }
};