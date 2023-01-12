#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long neg=0,zero=0;
        long long sum=0;
        int mini=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]<0){
                  neg++;
                }
                else if(matrix[i][j]==0){
                    zero++;
                }
                sum+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
            }
        }
        if(zero || neg%2==0){
            return sum;
        }
        else{
            return sum-2*mini;
        }
    }
};