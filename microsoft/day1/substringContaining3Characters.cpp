#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int sl = s.size();
     
        if(sl<3) return 0;

     
        int count  = 0;
 
        int track[3] = {0};            
   
        int first = 0;
        int last = -1;
        
        
        while(first<sl && last<sl)
        {
           
            if(track[0] > 0 && track[1]>0 && track[2]>0)
            {
                count += (sl-last);
                track[s[first]-'a']--;
                first++;
            }
            
            else
            {
                last++;
                if(last<sl)track[s[last]-'a']++;
            }
        }

        return count;
    }
};
