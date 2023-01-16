#include<bits/stdc++.h>
using namespace std;
class MountainArray {
   public:
     int get(int index);
    int length();
};


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=0; 
        int peak,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
                peak=mid+1;
            }
            else if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                r=mid-1;
            }
        }
         l=0;
         r=peak;
  
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)>target){
              r=mid-1;
            }
            else if(mountainArr.get(mid)<target){
                l=mid+1;
            }
            else {
                return mid;
            }
            
        }
        l=peak;
        r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)>target){
              l=mid+1;
            }
            else if(mountainArr.get(mid)<target){
                r=mid-1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};