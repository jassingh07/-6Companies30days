#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = n, r = -1;
        int last = -1;
        for(int i = 0; i < n; i++){
            if(last != -1 && nums[i] < nums[last]) r = max(r, i);
            if(last == -1 || nums[i] > nums[last]) last = i;
        }
        last = n;
        for(int i = n - 1; i >= 0; i--){
            if(last != n && nums[i] > nums[last]) l = min(l, i);
            if(last == n || nums[i] < nums[last]) last = i;
        }
        return l == n ? 0 : r - l + 1;
    }
};
int main()
{
   return 0;
}