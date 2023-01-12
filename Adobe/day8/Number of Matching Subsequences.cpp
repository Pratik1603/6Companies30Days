#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>>&pos,char c,int last){
        int l=0;
        int ans=-1;
        int r=pos[c-'a'].size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(pos[c-'a'][mid]>last){
                ans=pos[c-'a'][mid];
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>pos(26);
        for(int i=0;i<s.size();i++){
            pos[s[i]-'a'].push_back(i);
        }
        int c=0;
        for(int i=0;i<words.size();i++){
            int last=-1;
            int flag=0;
            for(int j=0;j<words[i].size();j++){
                last=solve(pos,words[i][j],last);
                if(last==-1){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                c++;
            }
        }
        return c;
    }
};