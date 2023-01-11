#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long dp[33];
    // formula   f(n)=f(n-1)+f(n-2)+2**(n-2)
    int helper(int n){
        int ans;
        double pow=log(n)/log(2);
        if(pow==int(pow)){
            return dp[(int)pow];
        }
        pow=floor(pow);
        ans=dp[(int)pow];
        int l=1<<(int)pow;
        int left=n-l;
        if(left>=l/2){
            ans+=dp[(int)pow -1]+left-l/2+1;
        }
        else{
            ans+=helper(left);
        }
        return ans;
    }
    
    int findIntegers(int n) {
        dp[0]=0;
        dp[1]=0;
        long val=1;
        for(int i=2;i<33;i++){
            dp[i]=dp[i-1]+dp[i-2]+val;
            val=val<<1;
        }
        int ones=helper(n);
        return n-ones+1;
    }
};