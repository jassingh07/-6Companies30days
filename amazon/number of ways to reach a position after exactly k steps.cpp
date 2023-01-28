#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD (ll)(1e9 + 7)
class Solution {
    vector<vector<ll>> dp;
public:
    Solution(){
        dp.resize(3001, vector<ll>(1001, -1));
    }
    ll numberOfWays(int startPos, int endPos, int k) {
        if(k == 0) return startPos == endPos;
        if(dp[startPos + 1000][k] != -1) return dp[startPos + 1000][k];
        return dp[startPos + 1000][k] = (numberOfWays(startPos + 1, endPos, k - 1) + numberOfWays(startPos - 1, endPos, k - 1)) % MOD;
    }
};
int main()
{
   return 0;
}