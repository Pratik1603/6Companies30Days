#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long dp[1001];
    long m=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
       memset(dp,-1,sizeof(dp));
       return solve(1,n,delay,forget); 
    }
    int solve(int day,int n,int delay,int forget){
        if(dp[day]!=-1){
            return dp[day];
        }
        long ans=0;
        ans++;
        if(day+forget<=n){
            ans--;
        }
        for(int start=day+delay;start<min(n+1,day+forget);start++){
            ans+=solve(start,n,delay,forget);
            ans=ans%m;
        }
        dp[day]=ans%m;
        return ans;
    }
};
