#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>> pq;
		vector<int> res;

		unordered_map<int, int> umap;
		for(auto it : barcodes)
			umap[it]++;

		for(auto e : umap)
			pq.push({e.second, e.first});
       
		while(!pq.empty()) {
			auto t1 = pq.top();
             pq.pop();
			if(res.empty() || res.back()!= t1.second || pq.empty()) {
				res.push_back(t1.second);
				t1.first--;
				if(t1.first)
					pq.push(t1);
			} else {
				auto t2 = pq.top(); 
                pq.pop(); 
                pq.push(t1);
				res.push_back(t2.second);
				t2.first--;
				if(t2.first)
					pq.push(t2);
			}
		}

		return res;  
      
    }
};