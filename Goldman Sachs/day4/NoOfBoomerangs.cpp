#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res=0;
    int numberOfBoomerangs(vector<vector<int>>& points) {
        for(auto i=0;i<points.size();i++){
            unordered_map<long,int> group(points.size());
            for(auto j=0;j<points.size();j++){
                if(j==i){
                    continue;
                }
                long dist=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                group[dist]++;
            }
            for(auto &x:group){
            if(x.second>1){
                res+=(x.second)*(x.second-1);
            }
        }
        }
        
        return res;
    }
};
