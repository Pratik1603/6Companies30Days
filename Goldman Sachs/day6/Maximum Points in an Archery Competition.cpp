#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m=0;
    vector<int> ans;
    void func(vector<int> &temp,int score,int numArrows,vector<int> aliceArrows,int index)
    {
        if(index==aliceArrows.size())
        {
           
            if(m<score)
            {
               
                m=score;
                for(int i=0;i<ans.size();i++)
                {
                    ans[i]=temp[i];
                }
               
                ans[0]+=numArrows;
            }
            return;
        }
        if(aliceArrows[index]<numArrows)
        {
            
            temp[index]=aliceArrows[index]+1;
            func(temp,score+index,numArrows-temp[index],aliceArrows,index+1);
           
            temp[index]=0;
        }
        
        func(temp,score,numArrows,aliceArrows,index+1);
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
        vector<int>temp(aliceArrows.size(),0);
        
        for(int i=0;i<aliceArrows.size();i++)
        {
            ans.push_back(0);
        }
        func(temp,0,numArrows,aliceArrows,0);
        
        return ans;
        
        
    }
};