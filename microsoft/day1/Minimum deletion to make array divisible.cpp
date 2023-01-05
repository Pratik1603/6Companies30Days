#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        int flag=0;
        int index;
        for (int i = 0; i < numsDivide.size(); i++)
        {
            g = __gcd(numsDivide[i], g);
        }
      
        sort(nums.begin(),nums.end());
        auto res = find (nums.begin(), nums.end(), g);
        for(int i=0;i<nums.size();i++){
            if(g%nums[i]==0 && g>nums[i]){
                flag=1;
                index=i;
                break;
            }
        }
        
        if(flag){
              return index;
        }
        if (res != nums.end())
        {
          
          
              return res - nums.begin();
          
         
        }
        else{
            return -1;
        }
    }

};
