#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0) return 1.0;     
        vector<double> dp(max(n,maxPts)+1,0);
        for(int i=1;i<=maxPts;++i) dp[i]=1.0/maxPts;
        double sum=0; 
        for(int i=1;i<=n;++i)
        {
            dp[i]+=sum; 
            if(i<k) sum+= dp[i]/maxPts;     
            if(i>maxPts && i<maxPts+k)
                sum-=dp[i-maxPts]/maxPts; 
        }
        double r=0;
        for(int i=k;i<=n;++i) r+= dp[i];
        return r;
    }
};