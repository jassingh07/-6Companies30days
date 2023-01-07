#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MD (ll)(1e9 + 7)
class Solution {
    int rev(int x){
        int res = 0;
        while(x){
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto i: nums) m[i - rev(i)]++;
        
        ll res = 0;
        for(auto p: m) res = (res + p.second * 1LL * (p.second - 1) / 2) % MD;

        return res;
    }
};
int main()
{
   return 0;
}