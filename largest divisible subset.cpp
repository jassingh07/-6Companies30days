#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(n, {1, -1});//{len, prev_ind}
        int end = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
               if(nums[j] % nums[i] == 0)
                    {
                        if(dp[i].first >= dp[j].first) dp[j].first++, dp[j].second = i;
                        if(end == -1 || dp[j].first > dp[end].first) end = j;
                    }
        }
        vector<int> answer;

        while(end != -1){
            answer.push_back(nums[end]);
            end = dp[end].second;
        }
        
        return answer.size() ? answer : vector<int>(nums.begin(), nums.begin() + 1);
    }
};
int main()
{
   return 0;
}