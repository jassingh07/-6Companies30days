#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ans = 0;
        vector<int> dp(n + 1, 0);
        for(int i = m - 1; i >= 0; i--)
            for(int j = 0; j < n; j++){
                if(nums1[i] == nums2[j]) dp[j] = 1 + dp[j + 1];
                else dp[j] = 0;
                ans = max(ans, dp[j]);
            }
        return ans;
    }
};
int main()
{
   return 0;
}