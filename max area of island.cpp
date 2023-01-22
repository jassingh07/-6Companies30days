#include<bits/stdc++.h>
using namespace std;
class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();
        if(i < 0 || j < 0 || i >= row || j >= col || !grid[i][j]) return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1) res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};
int main()
{
   return 0;
}