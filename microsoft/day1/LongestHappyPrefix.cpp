#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(string& word)
    {
        int n=word.length();
        vector<int> longpre(n, 0);
        int j = 0;
        for(int i = 1; i < word.length();)
        {
            if(word[i] == word[j])
            {
                j++;
                longpre[i] = j;
                i++;
            }
            else
            {
                if(j != 0)
                    j = longpre[j-1];
                else
                    i++;
            }
        }
        
        return longpre;
    }
    
    string longestPrefix(string s) {
        vector<int> longpre = solve(s);
        
        return s.substr(0, longpre.back());
    }
};