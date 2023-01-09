#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> invalidTransactions(vector<string>& transactions) {
  set<pair<int,int> > st;
  vector<pair<int,pair<pair<int,string>,string> > > times;
  for(int i=0;i<transactions.size();i++){
  string name,time,amount,place;
  int c=0;
  for(int j=0;j<transactions[i].size();j++){
   if(transactions[i][j]==','){
    c++;
   }
   else if(c==0){
     name.push_back(transactions[i][j]);
    }
   else if(c==1){
    time.push_back(transactions[i][j]);
    }
    else if(c==2){
      amount.push_back(transactions[i][j]);
    }
    else{
     place.push_back(transactions[i][j]);
    }
   }
   times.push_back({stoi(time),{{i,name},place}});
 
   if(stoi(amount)>1000){
    st.insert({stoi(time),i});
    }

}
   
    
    sort(times.begin(),times.end());
   
    for(int i=0;i<times.size()-1;i++){
        for(int j=i+1;j<times.size();j++){
      
            if(times[j].first-times[i].first<=60 && times[i].second.first.second==times[j].second.first.second && times[i].second.second!=times[j].second.second){
               
                st.insert({times[i].first,times[i].second.first.first});
                st.insert({times[j].first,times[j].second.first.first});
            }
        }
    }
    vector<string> ans;
    for(auto s:st){
       
        ans.push_back(transactions[s.second]);
    }
    return ans;
    
}
};