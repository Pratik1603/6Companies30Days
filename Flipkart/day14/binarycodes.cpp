#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.length()) return false;
        unordered_map<string, int>mp;
        for (int i = 0; i < s.length()-k+1; i++)
            mp[s.substr(i, k)]++;
        return mp.size() == pow(2, k);
    }
};  