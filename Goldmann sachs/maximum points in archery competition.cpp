#include<bits/stdc++.h>
using namespace std;
class Solution {
    int dfs(int num, vector<int>& aa, vector<vector<int>> &dp, int ind = 0){
        if(ind == 12)
            return 0;
        if(dp[ind][num] != -1) return dp[ind][num];
        int win = -1;
        if(num - aa[ind]  - 1 >= 0) 
            win = ind + dfs(num - aa[ind] - 1, aa, dp, ind + 1);
        int lose = dfs(num, aa, dp, ind + 1);
        return dp[ind][num] = max(win , lose);
    }
public:
    vector<int> maximumBobPoints(int num, vector<int>& aa) {
        vector<vector<int>> dp(13, vector<int>(num + 1, -1));
        for(int i = 0; i <= num; i++) dp[12][i] = 0;
        dfs(num, aa, dp);
        vector<int> bob(12, 0);
        int i = 1, j = num;
        while(i < 12){
            if(j - aa[i]  - 1 >= 0 && dp[i][j] - i == dp[i + 1][j - aa[i] - 1]){
                bob[i] = aa[i] + 1;
                num -= bob[i];
                j = j - aa[i++] - 1;
            }
            else i++;
        }
        for(int i = 0; i < 12; i++) if(bob[i]) {
            bob[i] += num;
            num = 0;
        }
        if(num) bob[0] += num;
        return bob;
    }
};
int main()
{
   return 0;
}