#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int checkAndCount(int mask, vector<vector<int>>&statements,int &n){
        vector<int>good(n,0);
        for(int i=0;i<n;i++){
            if((1<<i) & mask)good[i]=1;
        }
        for(int i=0;i<n;i++){
            if(good[i]==0)continue;
            for(int j=0;j<n;j++){
                if(statements[i][j]==0 && good[j]==1){                    
                    return 0;
                }
                if(statements[i][j]==1 && good[j]==0){
                    return 0;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(good[i]==1)count++;
        }
        return count;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        int bitmask=pow(2,n)-1;
        int numberOfGood=0;
        for(int i=bitmask;i>=0;i--){
            int value = checkAndCount(i,statements,n);
            numberOfGood=max(value,numberOfGood);
        }
        return numberOfGood;
    }
};