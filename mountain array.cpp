#include<bits/stdc++.h>
using namespace std;
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int bs(int tar, MountainArray &ma, int low, int high, bool inc){
        int mid;
        while(low <= high){
            mid = (low + high) / 2;
            int val = ma.get(mid);
            if(val < tar) inc ? (low = mid + 1) : (high = mid - 1);
            else if(val > tar) inc ? (high = mid - 1) : (low = mid + 1);
            else return mid;
        }
        return 1e5;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low = 1, high = mountainArr.length() - 1;
        int mid, ml;
        int peak = -1, peakind = -1;//not found yet
        while(low <= high){
            mid = (low + high) / 2; ml = mid - 1;
            int right = mountainArr.get(mid);
            int left = mountainArr.get(ml);
            if(right > left) {
                if(right > peak){
                    peak = max(peak, right);
                    peakind = mid;
                }
                low = mid + 1;
            }
            else {
                if(left > peak){
                    peak = max(peak, left);
                    peakind = ml;
                }
                high = ml - 1;
            }
        }//end bs for peak
        
        int res =  min(bs(target, mountainArr,0, peakind - 1, true), bs(target, mountainArr, peakind, mountainArr.length() - 1, false));
        return res == 1e5 ? -1 : res;
    }
};
int main()
{
   return 0;
}