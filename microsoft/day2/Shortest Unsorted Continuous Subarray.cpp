#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      int n=nums.size();
      int start=0;
      int end=-1;
      int max=nums[0];
      int min=nums[n-1];
      for(int i=1,j=n-2;i<=n-1;i++){
        if(max<=nums[i]){
            max=nums[i];
        }
        else if(max>nums[i]){
            end=nums[i];
        }
        if(j>=0){
            if(min>=nums[j]){
                min=nums[j];
            }
            else{
                start=nums[j];
            }
        }
        j--;
      }
      return end-start+1;
    }
};
