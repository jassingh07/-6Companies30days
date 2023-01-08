#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int end = n - 1;
        int res = 0, total = 0;
        for(int i = 0; i < n; i++) {
            res += i * nums[i];
            total += nums[i];
        }
        int sum = res;
        while(end >= 0)
        {
            sum += total -  n * nums[end--];
            res = max(res, sum);
        }
        return res;
    }
};
int main()
{
   return 0;
}