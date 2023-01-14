#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthNumber(int n, int k) {
        stack<int> stk;
        stk.push(1);
        
        while(k){
            if(k == 1) return stk.top();
            long long top = stk.top(), x = top;
            stk.pop();
            long long sum = 0, m = 1;
            
            while(top <= n){
                if(top + m - 1 <= n) sum += m;
                else sum += n - top + 1;
                top *= 10;
                m *= 10;
            }
            
            if(k > sum){
                k -= sum;
                stk.push(x+1);
            }else{
                k --;
                stk.push(x*10);
            }
        }
        return stk.top();
    }
};