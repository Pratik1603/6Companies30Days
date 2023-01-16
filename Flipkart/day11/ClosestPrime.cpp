#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<bool> check;
void sieve(int n){
    check.resize(n+1,true);
    check[0]=false;
    check[1]=false;
    for(int i=2;i*i<=n;i++){
        if(check[i]){
            for(int j=i*i;j<=n;j+=i){
                check[j]=false;
            }
        }
    }
}
    vector<int> closestPrimes(int left, int right) {
        sieve(right);
        vector<int>ans;
        for(int i=left; i<=right; i++){
            if(check[i]==true){
                ans.push_back(i);
            }
        }
        int minn=INT_MAX,ind; 
        if(ans.size()<2){
            return {-1,-1};
        }
        else{
          for(int i=0;i<ans.size()-1;i++){
            if((ans[i+1]-ans[i])<minn){
                minn = (ans[i+1]-ans[i]);
                ind = i;
            }
        }
            return {ans[ind],ans[ind+1]};
        }
    }
};