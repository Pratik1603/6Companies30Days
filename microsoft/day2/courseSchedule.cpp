#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
       bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course(numCourses, vector<int>());
        vector<bool> take(numCourses, false);
        vector<int> courseQueue;
        vector<vector<int>> preList(numCourses, vector<int>());
        vector<int> preNum(numCourses, 0);
        int s = 0;
        int c = 0;
        for(int i = 0; i < prerequisites.size(); i++){
            course[prerequisites[i][1]].push_back(prerequisites[i][0]);
            preList[prerequisites[i][0]].push_back(prerequisites[i][1]);
            preNum[prerequisites[i][0]]++;
        }
        
        for(int i = 0; i < numCourses; i++){
            if(preList[i].size() == 0){
                courseQueue.push_back(i);
                take[i] = true;
                s++;
            }
        }
        while(c < s){
            int cur = courseQueue[c];
            c++;
            for(int i = 0; i < course[cur].size(); i++){
                preNum[course[cur][i]]--;
                if(preNum[course[cur][i]] == 0 and not take[course[cur][i]]){
                    take[course[cur][i]] = true;
                    courseQueue.push_back(course[cur][i]);
                    s++;
                }
            }
        }
        return s == numCourses;
    }
};

