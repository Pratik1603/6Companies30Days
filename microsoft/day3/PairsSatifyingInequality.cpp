#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[200000];
    
    void update(int ind,int l,int r,int pos){
        if(pos<l||pos>r) return;
        if(l==r){
            t[ind]++;return;
        }
        int mid=l+(r-l)/2;
        update(2*ind,l,mid,pos);
        update(2*ind+1,mid+1,r,pos);
        t[ind]=t[2*ind]+t[2*ind+1];
    }
    int query(int ind,int l,int r,int ql,int qr){
        if(l>qr||r<ql) return 0;
        if(ql<=l && r<=qr) return t[ind];
        int mid=l+(r-l)/2;
        return query(2*ind,l,mid,ql,qr)+query(2*ind+1,mid+1,r,ql,qr);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int dif) {
         int n=nums1.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = nums1[i]-nums2[i];
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int d= query(1,0,40001,0,dif+v[i]+20000);ans+=d;
            update(1,0,40001,v[i]+20000);
        }
        return ans;
    }
};
