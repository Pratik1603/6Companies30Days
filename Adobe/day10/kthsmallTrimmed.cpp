#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
		vector<int>res;
		for(auto q:queries){
			int k = q[0],trim = q[1];
			vector<pair<string,int>>tmp;
			for(int j = 0;j<nums.size();j++){
				int n = nums[j].size();
				string s = nums[j].substr(n-trim);
				if(s.size()) tmp.push_back({s,j});
			}
			sort(begin(tmp),end(tmp));
			res.push_back(tmp[k-1].second);
		}
		return res;
	}
};