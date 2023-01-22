#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        ll last = 0, cur = 0, till = -1;
        for(ll i = 0; i < nums.size(); i++){
            cur += nums[i] % p == 0;
            while(cur > k) cur -= nums[last++] % p == 0;
            for(int j = max(till + 1, last); j <= i;j++) 
                for(int k = last; k <= j; k++)
                    s.insert(vector<int>(nums.begin() + k, nums.begin() + j + 1));
            // cout << ans << ' ';
            till = i;
        }
        return s.size();
    }
};
int main()
{
   return 0;
}