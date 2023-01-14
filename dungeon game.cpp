#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon){
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<int> dp(col, -1e8);
        for(int i = row - 1; i >= 0; i--)
            for(int j = col - 1; j >= 0; j--){
                int right = (j == col - 1 ? -1e8 : dp[j + 1]);
                int down = dp[j];//previous value here i.e for next row

                int res = max(right, down);
                if(res == -1e8) res = 0;
                if(dungeon[i][j] < 0 && res > 0) res = 0;
                res += dungeon[i][j]; 
        // cout << i << " " << j << " " << res << endl;
                dp[j] = res;
            }
        return dp[0] > 0 ? 1 : 1 - dp[0];
    }
};
int main()
{
   return 0;
}