#include<bits/stdc++.h>
using namespace std;
class Solution {
    // void merge(vector<int>& a,int low, int mid, int high){
    //     //[low, mid] + [mid + 1, high]
    //     vector<int> sorted;
    //     int i = low, j = mid + 1;
    //     while(i <= mid && j <= high)
    //         sorted.push_back(a[i] < a[j] ? a[i++] : a[j++]);
    //     while(i <= mid) sorted.push_back(a[i++]);
    //     while(j <= high) sorted.push_back(a[j++]);
    //     for(int i = low; i <= high; i++) a[i] = sorted[i - low];
    // }
    // void fun(vector<int>& a, int low, int high){
    //     if(low == high) return;
    //     int mid = (low + high) / 2;
    //     fun(a, low, mid);//left sorted
    //     fun(a, mid + 1, high);//right sorted
    //     merge(a, low, mid, high);
    // }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> count(1e5 + 1, 0);
        for(int i = 0; i < nums.size(); i++) count[nums[i] + 5 * 1e4]++;
        int ptr = 0;
        for(int i = 0; i <= 1e5;i++)  while(count[i]--) nums[ptr++] = i - 5 * 1e4;
        return nums;
    }
};
int main()
{
   return 0;
}