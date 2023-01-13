#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

class StockPrice {
public:
    unordered_map<int,int> data;
    priority_queue<pii,vector<pii>,greater<pii>> pqMin;
    priority_queue<pii,vector<pii>> pqMax;
    int currTime;
    
    StockPrice() {
        currTime=INT_MIN;
    }
    
    void update(int timestamp, int price) {
        data[timestamp]=price; 
        pqMin.push(make_pair(price,timestamp));
        pqMax.push(make_pair(price,timestamp));
        currTime=max(timestamp,currTime);
    }
    
    int current() {
        return data[currTime];
    }
    
    int maximum() {
        while(data[pqMax.top().second]!=pqMax.top().first) {
            cout<<pqMax.top().first<<" ";
            pqMax.pop();
        }
        return pqMax.top().first;
    }
    
    int minimum() {
        while(data[pqMin.top().second]!=pqMin.top().first) pqMin.pop();
        return pqMin.top().first;    
    }
};