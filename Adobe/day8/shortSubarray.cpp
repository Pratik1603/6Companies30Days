#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int end=-1;  //we will chech from both the directions andd find the start and end index
                    // 
        int n=nums.size();
        int max=nums[0];
         int start=0;
       
         int min=nums[n-1];
        for(int i=1,j=n-2;i<=n-1;i++){
            if(max>nums[i]){
                end=i;
            }
            else{
                max=nums[i];
            }
            if(j>=0){
                if(min<nums[j]){
                start=j;
            }
            else{
                min=nums[j];
            }
            
            }
            j--;
        }
        

       
       
        return end-start+1;
    }

};

 