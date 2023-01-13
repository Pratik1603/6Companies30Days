#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
    
    vector<vector<double>> dp(N, vector<double>(N, 1));
        for (int k = 1; k <= K; ++k)
        {
            vector<vector<double>> newDP(N, vector<double>(N));
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    double total = 0;
                    total += i >= 2 && j >= 1 ? dp[i - 2][j - 1] : 0;
                    total += i >= 2 && j + 1 < N ? dp[i - 2][j + 1] : 0;
                    total += i >= 1 && j >= 2 ? dp[i - 1][j - 2] : 0;
                    total += i >= 1 && j + 2 < N ? dp[i - 1][j + 2] : 0;
                    total += i + 1 < N && j >= 2 ? dp[i + 1][j - 2] : 0;
                    total += i + 1 < N && j + 2 < N ? dp[i + 1][j + 2] : 0;
                    total += i + 2 < N && j >= 1 ? dp[i + 2][j - 1] : 0;
                    total += i + 2 < N && j + 1 < N ? dp[i + 2][j + 1] : 0;
                    
                    newDP[i][j] = total / 8;
                }
            }
            
            dp = newDP;
        }
        
        return dp[r][c];
    }
};