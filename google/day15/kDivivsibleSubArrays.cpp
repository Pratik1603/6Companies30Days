#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<string> s;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            string str="";
            int count=0;
            for(int j=i;j<n;j++)
            {
                str+=to_string(nums[j])+" ";
                if(nums[j]%p==0)
                {
                    count++;
                }
             
                if(count>k)
                {
                    break;
                }
                s.insert(str);
            }
        }
        return s.size();
    }
};
