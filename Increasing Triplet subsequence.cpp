#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> ds;
        for(int i = 0; i < nums.size(); i++){
            int ind = lower_bound(ds.begin(), ds.end(), nums[i]) - ds.begin();
            if(ind == ds.size()) ds.push_back(nums[i]);
            else ds[ind] = nums[i];
            if(ds.size() == 3) return true;
        }
        return false;
    }
};
int main()
{
   return 0;
}