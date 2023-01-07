#include<bits/stdc++.h>
using namespace std;
class Solution {
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int commonGcd = numsDivide[0];
        int n = numsDivide.size();
        for(int i = 1; i < n; i++)
            commonGcd = gcd(commonGcd, numsDivide[i]);

        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            if(commonGcd % nums[i] == 0) break;
            else res++;
        
        return res == nums.size() ? -1 : res;
    }
};
int main()
{
   return 0;
}